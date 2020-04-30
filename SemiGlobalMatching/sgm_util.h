/* -*-c++-*- SemiGlobalMatching - Copyright (C) 2020.
* Author	: Ethan Li <ethan.li.whu@gmail.com>
* Describe	: implement of sgm_util
*/

#pragma once
#include "sgm_types.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(P) {if(P) delete[](P);(P)=nullptr;}
#endif

namespace sgm_util
{
	//······ census工具集
	// census变换

	/**
	 * \brief census变换
	 * \param source	输入，影像数据
	 * \param census	输出，census值数组
	 * \param width		输入，影像宽
	 * \param height	输入，影像高
	 */
	void census_transform_5x5(const uint8* source, uint32* census, const sint32& width, const sint32& height);
	void census_transform_9x7(const uint8* source, uint64* census, const sint32& width, const sint32& height);
	// Hamming距离
	uint8 Hamming32(const uint32& x, const uint32& y);


	/**
	 * \brief 左右路径聚合 → ←
	 * \param img_data			输入，影像数据
	 * \param width				输入，影像宽
	 * \param height			输入，影像高
	 * \param min_disparity		输入，最小视差
	 * \param max_disparity		输入，最大视差
	 * \param p1				输入，惩罚项P1
	 * \param p2_init			输入，惩罚项P2_Init
	 * \param cost_init			输入，初始代价数据
	 * \param cost_aggr			输出，路径聚合代价数据
	 * \param is_forward		输入，是否为正方向（正方向为从左到右，反方向为从右到左）
	 */
	void CostAggregateLeftRight(const uint8* img_data, const sint32& width, const sint32& height, const sint32& min_disparity, const sint32& max_disparity,
		const sint32& p1,const sint32& p2_init, const uint8* cost_init, uint8* cost_aggr, bool is_forward = true);

	/**
	 * \brief 上下路径聚合 ↓ ↑
	 * \param img_data			输入，影像数据
	 * \param width				输入，影像宽
	 * \param height			输入，影像高
	 * \param min_disparity		输入，最小视差
	 * \param max_disparity		输入，最大视差
	 * \param p1				输入，惩罚项P1
	 * \param p2_init			输入，惩罚项P2_Init
	 * \param cost_init			输入，初始代价数据
	 * \param cost_aggr			输出，路径聚合代价数据
	 * \param is_forward		输入，是否为正方向（正方向为从上到下，反方向为从下到上）
	 */
	void CostAggregateUpDown(const uint8* img_data, const sint32& width, const sint32& height, const sint32& min_disparity, const sint32& max_disparity,
		const sint32& p1, const sint32& p2_init, const uint8* cost_init, uint8* cost_aggr, bool is_forward = true);

	/**
	 * \brief 对角线1路径聚合（左上<->右下）↘ ↖
	 * \param img_data			输入，影像数据
	 * \param width				输入，影像宽
	 * \param height			输入，影像高
	 * \param min_disparity		输入，最小视差
	 * \param max_disparity		输入，最大视差
	 * \param p1				输入，惩罚项P1
	 * \param p2_init			输入，惩罚项P2_Init
	 * \param cost_init			输入，初始代价数据
	 * \param cost_aggr			输出，路径聚合代价数据
	 * \param is_forward		输入，是否为正方向（正方向为从左上到右下，反方向为从右下到左上）
	 */
	void CostAggregateDagonal_1(const uint8* img_data, const sint32& width, const sint32& height, const sint32& min_disparity, const sint32& max_disparity,
		const sint32& p1, const sint32& p2_init, const uint8* cost_init, uint8* cost_aggr, bool is_forward = true);

	/**
	 * \brief 对角线2路径聚合（右上<->左下）↙ ↗
	 * \param img_data			输入，影像数据
	 * \param width				输入，影像宽
	 * \param height			输入，影像高
	 * \param min_disparity		输入，最小视差
	 * \param max_disparity		输入，最大视差
	 * \param p1				输入，惩罚项P1
	 * \param p2_init			输入，惩罚项P2_Init
	 * \param cost_init			输入，初始代价数据
	 * \param cost_aggr			输出，路径聚合代价数据
	 * \param is_forward		输入，是否为正方向（正方向为从上到下，反方向为从下到上）
	 */
	void CostAggregateDagonal_2(const uint8* img_data, const sint32& width, const sint32& height, const sint32& min_disparity, const sint32& max_disparity,
		const sint32& p1, const sint32& p2_init, const uint8* cost_init, uint8* cost_aggr, bool is_forward = true);

	
	/**
	 * \brief 中值滤波
	 * \param in				输入，源数据 
	 * \param out				输出，目标数据
	 * \param width				输入，宽度
	 * \param height			输入，高度
	 * \param wnd_size			输入，窗口宽度
	 */
	void MedianFilter(const float32* in, float32* out, const sint32& width, const sint32& height, const sint32 wnd_size);

	void RemoveSpeckles(float32* disparity_map, const sint32& width, const sint32& height, const sint32& diff_insame,const uint32& min_speckle_aera, const float& invalid_val);
}