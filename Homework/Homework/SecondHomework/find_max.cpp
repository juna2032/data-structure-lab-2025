#include <opencv2/opencv.hpp>
#include <stdio.h>

int find_max_brightness(const cv::Mat& image) {
    int max_value = 0;

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            
            int pixel_value = image.at<uchar>(i, j);
            if (pixel_value > max_value) {
                max_value = pixel_value;
            }
        }
    }

    return max_value;
}

int main() {
   
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        printf("이미지를 불러올 수 없습니다.\n");
        return -1;
    }

    int max_brightness = find_max_brightness(img);
    printf("최대 밝기 값: %d\n", max_brightness);

    return 0;
}















//#include <iostream>
//#include<opencv2/opencv.hpp>

//int main() {
	
	//cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	//cv::imshow("lenna window", img);
	//cv::waitKey(0);

	
	
	
	
	//	std::cout << "OpenCV Version: " << CV_VERSION;

//}