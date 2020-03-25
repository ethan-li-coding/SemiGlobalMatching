/* -*-c++-*- SemiGlobalMatching - Copyright (C) 2020.
* Author	: Ethan Li <ethan.li.whu@gmail.com>
* Describe	: implement of semi-global matching class
*/

#include "stdafx.h"
#include "SemiGlobalMatching.h"


SemiGlobalMatching::SemiGlobalMatching(): width_(0), height_(0), img_left_(nullptr), img_right_(nullptr),
                                          census_left_(nullptr),
                                          census_right_(nullptr),
                                          cost_init_(nullptr),
                                          cost_aggr_(nullptr),
                                          disp_left_(nullptr)
{
}


SemiGlobalMatching::~SemiGlobalMatching()
{
}

void SemiGlobalMatching::Initialize(const uint32& width, const uint32& height, const SGMOption& option)
{
}

void SemiGlobalMatching::Match(const uint8* img_left, const uint8* img_right, float32* disp_left)
{
}

void SemiGlobalMatching::Reset(const uint32& width, const uint32& height)
{
}

void SemiGlobalMatching::Reset(const SGMOption& option)
{
}

void SemiGlobalMatching::CensusTransform()
{
}

void SemiGlobalMatching::ComputeCost()
{
}

void SemiGlobalMatching::CostAggregation()
{
}

void SemiGlobalMatching::ComputeDisparity()
{
}
