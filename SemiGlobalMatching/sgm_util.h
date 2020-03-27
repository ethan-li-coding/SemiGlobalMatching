#pragma once
#include "sgm_types.h"
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
	void census_transform_5x5(const uint8* source, uint32* census, const uint32& width, const uint32& height);
	void census_transform_9x7(const uint8* source, uint64* census, const uint32& width, const uint32& height);
	// Hamming距离
	uint16 Hamming32(const uint32& x, const uint32& y);

}