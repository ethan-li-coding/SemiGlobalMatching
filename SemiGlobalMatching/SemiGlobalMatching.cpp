/* -*-c++-*- SemiGlobalMatching - Copyright (C) 2020.
* Author	: Ethan Li <ethan.li.whu@gmail.com>
* Describe	: implement of semi-global matching class
*/

#include "stdafx.h"
#include "SemiGlobalMatching.h"
#include "sgm_util.h"
#include <algorithm>
#include <vector>
#include <cassert>

SemiGlobalMatching::SemiGlobalMatching(): width_(0), height_(0), img_left_(nullptr), img_right_(nullptr),
                                          census_left_(nullptr), census_right_(nullptr),
                                          cost_init_(nullptr), cost_aggr_(nullptr),
										  cost_aggr_1_(nullptr), cost_aggr_2_(nullptr),
                                          cost_aggr_3_(nullptr), cost_aggr_4_(nullptr),
                                          cost_aggr_5_(nullptr), cost_aggr_6_(nullptr),
                                          cost_aggr_7_(nullptr), cost_aggr_8_(nullptr),
                                          disp_left_(nullptr), 
										  is_initialized_(false)
{
}


SemiGlobalMatching::~SemiGlobalMatching()
{
    Release();
    is_initialized_ = false;
}

bool SemiGlobalMatching::Initialize(const sint32& width, const sint32& height, const SGMOption& option)
{
    // ··· 赋值
    
	// 影像尺寸
    width_ = width;
    height_ = height;
    // SGM参数
    option_ = option;

    if(width == 0 || height == 0) {
        return false;
    }

    //··· 开辟内存空间

    // census值（左右影像）
    census_left_ = new uint32[width * height]();
    census_right_ = new uint32[width * height]();

    // 视差范围
    const sint32 disp_range = option.max_disparity - option.min_disparity;
    if (disp_range <= 0) {
        return false;
    }

    // 匹配代价（初始/聚合）
    cost_init_  = new uint8[width * height * disp_range]();
    cost_aggr_  = new uint16[width * height * disp_range]();
    cost_aggr_1_ = new uint8[width * height * disp_range]();
    cost_aggr_2_ = new uint8[width * height * disp_range]();
    cost_aggr_3_ = new uint8[width * height * disp_range]();
    cost_aggr_4_ = new uint8[width * height * disp_range]();
    cost_aggr_5_ = new uint8[width * height * disp_range]();
    cost_aggr_6_ = new uint8[width * height * disp_range]();
    cost_aggr_7_ = new uint8[width * height * disp_range]();
    cost_aggr_8_ = new uint8[width * height * disp_range]();

    // 视差图
    disp_left_ = new float32[width * height]();

    is_initialized_ = census_left_ && census_right_ && cost_init_ && cost_aggr_ && disp_left_;

    return is_initialized_;
}


void SemiGlobalMatching::Release()
{
    // 释放内存
    SAFE_DELETE(census_left_);
    SAFE_DELETE(census_right_);
    SAFE_DELETE(cost_init_);
    SAFE_DELETE(cost_aggr_);
    SAFE_DELETE(cost_aggr_1_);
    SAFE_DELETE(cost_aggr_2_);
    SAFE_DELETE(cost_aggr_3_);
    SAFE_DELETE(cost_aggr_4_);
    SAFE_DELETE(cost_aggr_5_);
    SAFE_DELETE(cost_aggr_6_);
    SAFE_DELETE(cost_aggr_7_);
    SAFE_DELETE(cost_aggr_8_);
    SAFE_DELETE(disp_left_);
}


bool SemiGlobalMatching::Match(const uint8* img_left, const uint8* img_right, float32* disp_left)
{
    if(!is_initialized_) {
        return false;
    }
    if (img_left == nullptr || img_right == nullptr) {
        return false;
    }

    img_left_ = img_left;
    img_right_ = img_right;

    // census变换
    CensusTransform();

    // 代价计算
    ComputeCost();

    // 代价聚合
    CostAggregation();

    // 视差计算
    ComputeDisparity();

    // 输出视差图
    memcpy(disp_left, disp_left_, width_ * height_ * sizeof(float32));

	return true;
}

bool SemiGlobalMatching::Reset(const uint32& width, const uint32& height, const SGMOption& option)
{
    // 释放内存
    Release();

    // 重置初始化标记
    is_initialized_ = false;

    // 初始化
    return Initialize(width, height, option);
}

void SemiGlobalMatching::CensusTransform() const
{
	// 左右影像census变换
    sgm_util::census_transform_5x5(img_left_, census_left_, width_, height_);
    sgm_util::census_transform_5x5(img_right_, census_right_, width_, height_);
}

void SemiGlobalMatching::ComputeCost() const
{
    const sint32& min_disparity = option_.min_disparity;
    const sint32& max_disparity = option_.max_disparity;
    const sint32 disp_range = max_disparity - min_disparity;
    if (disp_range <= 0) {
        return;
    }

	// 计算代价（基于Hamming距离）
    for (sint32 i = 0; i < height_; i++) {
        for (sint32 j = 0; j < width_; j++) {

            // 左影像census值
            const uint32 census_val_l = census_left_[i * width_ + j];

            // 逐视差计算代价值
        	for (sint32 d = min_disparity; d < max_disparity; d++) {
                if (j - d < 0 || j - d >= width_) {
                    continue;
                }
                // 右影像对应像点的census值
                const uint32 census_val_r = census_right_[i * width_ + j - d];
                
        		// 计算匹配代价
                cost_init_[i * width_ * disp_range + j * disp_range + (d - min_disparity)] = sgm_util::Hamming32(census_val_l, census_val_r);
            }
        }
    }
}

void SemiGlobalMatching::CostAggregation() const
{
    // 路径聚合
    // 1、左->右/右->左
    // 2、上->下/下->上
    // 3、左上->右下/右下->左上
    // 4、右上->左上/左下->右上
    //
    // ↘ ↓ ↙   5  3  7
    // →    ←	 1    2
    // ↗ ↑ ↖   8  4  6
    //
    const auto& min_disparity = option_.min_disparity;
    const auto& max_disparity = option_.max_disparity;
    assert(max_disparity > min_disparity);

    const sint32 size = width_ * height_ * (max_disparity - min_disparity);
    if(size <= 0) {
        return;
    }

    const auto& P1 = option_.p1;
    const auto& P2_Int = option_.p2_init;

    // 左右聚合
    sgm_util::CostAggregateLeftRight(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_1_, true);
	sgm_util::CostAggregateLeftRight(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_2_, false);
    // 上下聚合
	sgm_util::CostAggregateUpDown(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_3_, true);
	sgm_util::CostAggregateUpDown(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_4_, false);
	// 对角线1聚合
    sgm_util::CostAggregateDagonal_1(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_5_, true);
    sgm_util::CostAggregateDagonal_1(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_6_, false);
    // 对角线2聚合
    sgm_util::CostAggregateDagonal_2(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_7_, true);
    sgm_util::CostAggregateDagonal_2(img_left_, width_, height_, min_disparity, max_disparity, P1, P2_Int, cost_init_, cost_aggr_8_, false);


    // 把4/8个方向加起来
    for(sint32 i =0;i<size;i++) {
    	cost_aggr_[i] = cost_aggr_1_[i] + cost_aggr_2_[i] + cost_aggr_3_[i] + cost_aggr_4_[i];
    	if (option_.num_paths == 8) {
            cost_aggr_[i] += cost_aggr_5_[i] + cost_aggr_6_[i] + cost_aggr_7_[i] + cost_aggr_8_[i];
        }
    }
}

void SemiGlobalMatching::ComputeDisparity() const
{
    const sint32& min_disparity = option_.min_disparity;
    const sint32& max_disparity = option_.max_disparity;
    const sint32 disp_range = max_disparity - min_disparity;
    if(disp_range <= 0) {
        return;
    }

    const auto cost_ptr = cost_aggr_;

    // 逐像素计算最优视差
    for (sint32 i = 0; i < height_; i++) {
        for (sint32 j = 0; j < width_; j++) {
            
            uint16 min_cost = UINT16_MAX;
            uint16 max_cost = 0;
            sint32 best_disparity = 0;

            // 遍历视差范围内的所有代价值，输出最小代价值及对应的视差值
            for (sint32 d = min_disparity; d < max_disparity; d++) {
                const auto& cost = cost_ptr[i * width_ * disp_range + j * disp_range + d - min_disparity];
                if(min_cost > cost) {
                    min_cost = cost;
                    best_disparity = d;
                }
                max_cost = std::max(max_cost, cost);
            }

            // 最小代价值对应的视差值即为像素的最优视差
            if (max_cost != min_cost) {
                disp_left_[i * width_ + j] = static_cast<float>(best_disparity);
            }
            else {
                disp_left_[i * width_ + j] = Invalid_Float;
            }
        }
    }
}
