/* -*-c++-*- SemiGlobalMatching - Copyright (C) 2020.
* Author	: Ethan Li <ethan.li.whu@gmail.com>
* Describe	: main
*/

#include "stdafx.h"
#include "SemiGlobalMatching.h"

// opencv library
#include <opencv2/opencv.hpp>
#ifdef _DEBUG
#pragma comment(lib,"opencv_world310d.lib")
#else
#pragma comment(lib,"opencv_world310.lib")
#endif


/**
 * \brief 
 * \param argv 3
 * \param argc argc[1]:×óÓ°ÏñÂ·¾¶ argc[2]: ÓÒÓ°ÏñÂ·¾¶ argc[3]: ×îÐ¡ÊÓ²î[¿ÉÑ¡£¬Ä¬ÈÏ0] argc[4]: ×î´óÊÓ²î[¿ÉÑ¡£¬Ä¬ÈÏ64]
 * \param eg. ..\Data\cone\im2.png ..\Data\cone\im6.png 0 64 
 * \return 
 */
int main(int argv,char** argc)
{
    if(argv < 3) {
        std::cout << "²ÎÊý¹ýÉÙ£¬ÇëÖÁÉÙÖ¸¶¨×óÓÒÓ°ÏñÂ·¾¶£¡" << std::endl;
        return -1;
    }

    //¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    // ¶ÁÈ¡Ó°Ïñ
    std::string path_left = argc[1];
    std::string path_right = argc[2];
   
    cv::Mat img_left = cv::imread(path_left, cv::IMREAD_GRAYSCALE);
    cv::Mat img_right = cv::imread(path_right, cv::IMREAD_GRAYSCALE);

    if (img_left.data == nullptr || img_right.data == nullptr) {
        std::cout << "¶ÁÈ¡Ó°ÏñÊ§°Ü£¡" << std::endl;
        return -1;
    }
    if (img_left.rows != img_right.rows || img_left.cols != img_right.cols) {
        std::cout << "×óÓÒÓ°Ïñ³ß´ç²»Ò»ÖÂ£¡" << std::endl;
        return -1;
    }


    //¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    const sint32 width = static_cast<uint32>(img_left.cols);
    const sint32 height = static_cast<uint32>(img_right.rows);

	// ×óÓÒÓ°ÏñµÄ»Ò¶ÈÊý¾Ý
    auto bytes_left = new unsigned char[width*height];
    auto bytes_right = new unsigned char[width*height];
	for (int i = 0; i < height;i++) {
		for (int j = 0; j < width;j++) {
			bytes_left[i*width + j] = img_left.at<unsigned char>(i, j);
			bytes_right[i*width + j] = img_right.at<unsigned char>(i, j);
		}
	}


    // SGMÆ¥Åä²ÎÊýÉè¼Æ
    SemiGlobalMatching::SGMOption sgm_option;
    // ¾ÛºÏÂ·¾¶Êý
	sgm_option.num_paths = 8;
	// ºòÑ¡ÊÓ²î·¶Î§
    sgm_option.min_disparity = argv < 4 ? 0 : atoi(argc[3]);
    sgm_option.max_disparity = argv < 5 ? 64 : atoi(argc[4]);
    // Ò»ÖÂÐÔ¼ì²é
    sgm_option.is_check_lr = true;
    sgm_option.lrcheck_thres = 1.0f;
    // Î¨Ò»ÐÔÔ¼Êø
	sgm_option.is_check_unique = true;
    sgm_option.uniqueness_ratio = 0.99;
    // ÌÞ³ýÐ¡Á¬Í¨Çø
	sgm_option.is_remove_speckles = true;
    sgm_option.min_speckle_aera = 30;
    // ³Í·£ÏîP1¡¢P2
	sgm_option.p1 = 10;
    sgm_option.p2_init = 150;
	// ÊÓ²îÍ¼Ìî³ä
	sgm_option.is_fill_holes = true;
    
	// ¶¨ÒåSGMÆ¥ÅäÀàÊµÀý
    SemiGlobalMatching sgm;

    //¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    // ³õÊ¼»¯
    if(!sgm.Initialize(width, height, sgm_option)) {
        std::cout << "SGM³õÊ¼»¯Ê§°Ü£¡" << std::endl;
        return -2;
    }


    //¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    // Æ¥Åä
    auto disparity = new float32[uint32(width * height)]();
    if(!sgm.Match(bytes_left,bytes_right,disparity)) {
        std::cout << "SGMÆ¥ÅäÊ§°Ü£¡" << std::endl;
        return -2;
    }

	//¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    // ÏÔÊ¾ÊÓ²îÍ¼
    cv::Mat disp_mat = cv::Mat(height, width, CV_8UC1);
    float min_disp = width, max_disp = -width;
	for (sint32 i = 0; i < height; i++) {
        for (sint32 j = 0; j < width; j++) {
            const float32 disp = disparity[i * width + j];
            if (disp != Invalid_Float) {
                min_disp = std::min(min_disp, disp);
                max_disp = std::max(max_disp, disp);
            }
        }
    }
    for (sint32 i = 0; i < height; i++) {
        for (sint32 j = 0; j < width; j++) {
            const float32 disp = disparity[i * width + j];
            if (disp == Invalid_Float) {
                disp_mat.data[i * width + j] = 0;
            }
            else {
                disp_mat.data[i * width + j] = static_cast<uchar>((disp - min_disp) / (max_disp - min_disp) * 255);
            }
        }
    }

    cv::imshow("ÊÓ²îÍ¼", disp_mat);
	cv::Mat disp_color;
	applyColorMap(disp_mat, disp_color, cv::COLORMAP_JET);
	cv::imshow("ÊÓ²îÍ¼-Î±²Ê", disp_color);

	// ±£´æ½á¹û
    std::string disp_map_path = argc[2]; disp_map_path += ".d.bmp";
    std::string disp_color_map_path = argc[2]; disp_color_map_path += ".c.bmp";
    cv::imwrite(disp_map_path, disp_mat);
    cv::imwrite(disp_color_map_path, disp_color);
    

	cv::waitKey(0);

    //¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤¡¤//
    // ÊÍ·ÅÄÚ´æ
    delete[] disparity; 
	disparity = nullptr;
	delete[] bytes_left;
	bytes_left = nullptr;
	delete[] bytes_right;
	bytes_right = nullptr;

    system("pause");
	return 0;
}

