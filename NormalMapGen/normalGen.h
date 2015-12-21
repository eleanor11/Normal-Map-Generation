#include<iostream> 
#include <vector>  
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

const int WIDTHBASE = 8;
const int COLORSIZE = 4;

/*verticle: x, y, z, a*/
uchar lineStyle1[WIDTHBASE * COLORSIZE] = { 127, 255, 191, 255,
											127, 207, 191, 255,
											127, 191, 255, 255, 
											127, 127, 255, 255,
											127, 127, 255, 255,
											127, 63, 255, 255,
											127, 47, 191, 255,
											127, 0, 191, 255 };

class NormalMap {

private:
	Mat mat;

	int scale = 2048;

	int lineWidth = 1;

public:
	NormalMap() {
		mat = Mat(scale, scale, CV_8UC4);
	}

	NormalMap(int s){
		scale = s;
		mat = Mat(s, s, CV_8UC4);
	}

	void setScale(int s) {
		scale = s;
	}
	int getScale() {
		return scale;
	}

	void writeToFile(String name) {
		std::vector<int> compression_params;
		compression_params.push_back(IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(9);

		imwrite(name, mat, compression_params);
	}

	void RowsGenAll() {
		for (int i = 0; i < mat.rows; i += lineWidth * WIDTHBASE) {
			for (int j = 0; j < mat.cols; j++) {
				for (int k = 0; k < WIDTHBASE; k++) {
					uchar* color = &(lineStyle1[k * COLORSIZE]);
					for (int l = 0; l < lineWidth; l++) {
						Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
						rgba[0] = color[2];			//z
						rgba[1] = color[1];			//y
						rgba[2] = color[0];			//x
						rgba[3] = color[3];			//a
					}
				}
			}
		}

	}

	void ColsGenAll() {
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j += lineWidth * WIDTHBASE) {
				for (int k = 0; k < WIDTHBASE; k++) {
					uchar* color = &(lineStyle1[(WIDTHBASE - k - 1)* COLORSIZE]);
					for (int l = 0; l < lineWidth; l++) {
						Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
						rgba[0] = color[2];			//z
						rgba[1] = color[0];			//x
						rgba[2] = color[1];			//y
						rgba[3] = color[3];			//a
					}
				}
			}
		}

	}



};