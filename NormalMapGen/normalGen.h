#include<iostream> 
#include <vector>  
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

const int WIDTHBASE = 8;
const int COLORSIZE = 4;
const int LINESTYLES = 5;

/*verticle: x, y, z, a*/
uchar FLAT[COLORSIZE] = {127, 127, 255, 255};
uchar LINESTYLE[WIDTHBASE * COLORSIZE * LINESTYLES] = {	127, 255, 191, 255,
														127, 207, 191, 255,
														127, 191, 255, 255, 
														127, 127, 255, 255,
														127, 127, 255, 255,
														127, 63, 255, 255,
														127, 47, 191, 255,
														127, 0, 191, 255,
																
														152, 233, 191, 255,
														152, 207, 191, 255,
														127, 191, 255, 255,
														127, 127, 255, 255,
														127, 127, 255, 255,
														127, 63, 255, 255, 
														148, 47, 191, 255,
														148, 20, 191, 255,

														127, 255, 191, 255,
														127, 207, 191, 255,
														127, 191, 255, 255,
														127, 142, 255, 255,
														127, 112, 255, 255,
														127, 63, 255, 255,
														127, 47, 191, 255,
														127, 0, 191, 255,

														152, 233, 191, 255,
														152, 207, 191, 255,
														127, 191, 255, 255,
														127, 142, 255, 255,
														127, 112, 255, 255,
														127, 63, 255, 255,
														148, 47, 191, 255,
														148, 20, 191, 255,

														127, 255, 255, 255,
														127, 255, 255, 255,
														127, 127, 255, 255,
														127, 127, 255, 255,
														127, 127, 255, 255,
														127, 0, 255, 255,
														127, 0, 255, 255,
														127, 127, 255, 255 };

class NormalMap {

private:
	Mat mat;
	Mat bmat;

	int scale = 2048;
	int lineWidth = 1;

	uchar* lineStyle = LINESTYLE;

public:
	NormalMap() {
		mat = Mat(scale, scale, CV_8UC4);
		bmat = Mat(scale, scale, CV_8UC1);
	}

	NormalMap(int s){
		scale = s;
		mat = Mat(s, s, CV_8UC4);
		bmat = Mat(scale, scale, CV_8UC1);
	}

	void setScale(int s) {
		scale = s;
	}
	int getScale() {
		return scale;
	}
	void setLineWidth(int l) {
		lineWidth = l;
	}
	int getLineWidth() {
		return lineWidth;
	}

	void setLineStyle(int s){
		if (s >= LINESTYLES) s = 0;
		lineStyle = LINESTYLE + s * WIDTHBASE * COLORSIZE;
	}

	void writeToFile(String name) {
		std::vector<int> compression_params;
		compression_params.push_back(IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(9);

		imwrite(name, mat, compression_params);
		imwrite("b" + name, bmat, compression_params);
	}


	void GenFlatAll() {
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j++) {
				Vec4b &rgba = mat.at<Vec4b>(i, j);
				rgba[0] = FLAT[2];			//z
				rgba[1] = FLAT[1];			//x
				rgba[2] = FLAT[0];			//y
				rgba[3] = FLAT[3];			//a
			}
		}
	}

	void RowsGenAll() {
		for (int i = 0; i < mat.rows; i += lineWidth * WIDTHBASE) {
			for (int j = 0; j < mat.cols; j++) {
				for (int k = 0; k < WIDTHBASE; k++) {
					uchar* color = lineStyle + k * COLORSIZE;
					for (int l = 0; l < lineWidth; l++) {
						Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
						rgba[0] = color[2];			//z
						rgba[1] = color[1];			//y
						rgba[2] = color[0];			//x
						rgba[3] = color[3];			//a
						
						bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
					}
				}
			}
		}

	}
	void RowsGenInterval(int a, int b) {
		/*
		the first a lines of b lines
		*/

		RowsGenInterval(a, 1, b, 1);
		return;

		//int step = lineWidth * WIDTHBASE;
		//for (int i = 0; i < mat.rows; i += step) {
		//	if (i / step % b < a) {
		//		for (int j = 0; j < mat.cols; j++){
		//			for (int k = 0; k < WIDTHBASE; k++) {
		//				uchar* color = lineStyle + k * COLORSIZE;
		//				for (int l = 0; l < lineWidth; l++) {
		//					Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
		//					rgba[0] = color[2];			//z
		//					rgba[1] = color[1];			//x
		//					rgba[2] = color[0];			//y
		//					rgba[3] = color[3];			//a

		//					bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
		//				}
		//			}
		//		}
		//	}
		//}
	}
	void RowsGenInterval(int a, int b, int c, int d) {

		/*
		the first a * b square are rows in a c * d square
		*/

		int step = lineWidth * WIDTHBASE;
		for (int i = 0; i < mat.rows; i += step) {
			if (i / step % c < a) {
				for (int j = 0; j < mat.cols; j++){
					if (j / step % d < b) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + k * COLORSIZE;
							for (int l = 0; l < lineWidth; l++) {
								Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
								rgba[0] = color[2];			//z
								rgba[1] = color[1];			//x
								rgba[2] = color[0];			//y
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
							}
						}
					}
				}
			}
			else {
				for (int j = 0; j < mat.cols; j++){
					if (j / step % d >= b) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + k * COLORSIZE;
							for (int l = 0; l < lineWidth; l++) {
								Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
								rgba[0] = color[2];			//z
								rgba[1] = color[1];			//x
								rgba[2] = color[0];			//y
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
							}
						}
					}
				}

			}
		}

	}

	void RowsGenLean(int a, int b) {
		/*
		a is length,
		b is length(cols) interval,
		*/

		RowsGenLean(a, b, 1, 1);
	}
	void RowsGenLean(int a, int b, int c, int d) {

		/*
		a is length,
		b is total length(all cols),
		c is width
		d is total width(all rows)
		*/

		RowsGenLean(a, b, c, d, 0);
	}
	void RowsGenLean(int a, int b, int c, int d, int e) {
		/*
			a is length, 
			b is total length, 
			c is width(rows) interval, 
			d is align
			(b * d) ^ 2
		*/

		int step = lineWidth * WIDTHBASE;
		int step2 = b * d * step;
		for (int i = 0; i < mat.rows; i += step) {
			if (i / step % d >= c) continue;
			int start = (i % step2 / (step * d) - (b - a) + 1) * step;
			//
			for (int j = start; j < mat.cols; j++) {
				if (j < 0) continue;
				if ((j - start) / step % b < a) {
					for (int k = 0; k < WIDTHBASE; k++) {
						uchar* color = lineStyle + k * COLORSIZE;
						for (int l = 0; l < lineWidth; l++) {
							Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
							rgba[0] = color[2];			//z
							rgba[1] = color[1];			//x
							rgba[2] = color[0];			//y
							rgba[3] = color[3];			//a

							bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
						}
					}
				}

			}
		}

	}

	void ColsGenAll() {
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j += lineWidth * WIDTHBASE) {
				for (int k = 0; k < WIDTHBASE; k++) {
					uchar* color = lineStyle + (WIDTHBASE - k - 1)* COLORSIZE;
					for (int l = 0; l < lineWidth; l++) {
						Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
						rgba[0] = color[2];			//z
						rgba[1] = color[0];			//x
						rgba[2] = color[1];			//y
						rgba[3] = color[3];			//a

						bmat.at<uchar>(i, j + k * lineWidth + l) = 255;
					}
				}
			}
		}

	}
	void ColsGenInterval(int a, int b) {
		/*
			the first a lines of b lines
		*/

		ColsGenInterval(1, a, 1, b);
		return;

		//int step = lineWidth * WIDTHBASE;
		//for (int i = 0; i < mat.rows; i++) {
		//	for (int j = 0; j < mat.cols; j += step){
		//		if (j / step % b < a) {
		//			for (int k = 0; k < WIDTHBASE; k++) {
		//				uchar* color = lineStyle + (WIDTHBASE - k - 1) * COLORSIZE;
		//				for (int l = 0; l < lineWidth; l++) {
		//					Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
		//					rgba[0] = color[2];			//z
		//					rgba[1] = color[0];			//x
		//					rgba[2] = color[1];			//y
		//					rgba[3] = color[3];			//a

		//					bmat.at<uchar>(i, j + k * lineWidth + l) = 255;
		//				}
		//			}
		//		}
		//	}
		//}

	}
	void ColsGenInterval(int a, int b, int c, int d) {
		/*
			the first a * b square are cols in a c * d square
		*/

		int step = lineWidth * WIDTHBASE;
		for (int i = 0; i < mat.rows; i++) {
			if (i / step % c < a) {
				for (int j = 0; j < mat.cols; j += step){
					if (j / step % d < b) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + (WIDTHBASE - k - 1) * COLORSIZE;
							for (int l = 0; l < lineWidth; l++) {
								Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
								rgba[0] = color[2];			//z
								rgba[1] = color[0];			//x
								rgba[2] = color[1];			//y
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i, j + k * lineWidth + l) = 255;
							}
						}
					}
				}
			}
			else {
				for (int j = 0; j < mat.cols; j += step){
					if (j / step % d >= b) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + (WIDTHBASE - k - 1) * COLORSIZE;
							for (int l = 0; l < lineWidth; l++) {
								Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
								rgba[0] = color[2];			//z
								rgba[1] = color[0];			//x
								rgba[2] = color[1];			//y
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i, j + k * lineWidth + l) = 255;
							}
						}
					}
				}
			}
		}

	}

	void RowsFirstEdge(int a, int b, int c, int d) {
		/*
		the first a * b square are rows in a c * d square
		*/

		int step = lineWidth * WIDTHBASE;

		//edit row edges
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j += step * d) {
				if (i / step % c < a) {
					//(0..a) * (0..b)
					{
						//left side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b - lineWidth + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b - lineWidth * 2 + k);
							rgba1[2] = color1[1];
						}
					}
				}
				else {
					//(a..c) * (b..d)
					{
						//left side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * d - lineWidth + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * d - lineWidth * 2 + k);
							rgba1[2] = color1[1];
						}
					}
				}
			}
		}


	}
	void RowsSecondEdge(int a, int b, int c, int d) {
		/*
		the first a * b square are cols in a c * d square
		*/


		int step = lineWidth * WIDTHBASE;

		//edit row edges
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j += step * d) {
				if (i / step % c < a) {
					//(a..c) * (b..d)
					{
						//left side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * d - lineWidth + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * d - lineWidth * 2 + k);
							rgba1[2] = color1[1];
						}
					}
				}
				else {
					//(0..a) * (0..b)
					{
						//left side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b - lineWidth + k);
							rgba[2] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b - lineWidth * 2 + k);
							rgba1[2] = color1[1];
						}
					}
				}
			}
		}

	}


	void ColsFirstEdge(int a, int b, int c, int d) {
		/*
		the first a * b square are cols in a c * d square
		*/

		int step = lineWidth * WIDTHBASE;

		//edit col edges
		for (int i = 0; i < mat.rows; i += step * c) {
			for (int j = 0; j < mat.cols; j++) {
				if (j / step % d < b) {
					//(0..a) * (0..b)
					{
						//up side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * a - lineWidth + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a - lineWidth * 2 + k, j);
							rgba1[1] = color1[1];
						}
					}
				}
				else {
					//(a..c) * (b..d)
					{
						//up side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * a + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * c - lineWidth + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * c - lineWidth * 2 + k, j);
							rgba1[1] = color1[1];
						}
					}
				}
			}
		}
	}
	void ColsSecondEdge(int a, int b, int c, int d) {

		/*
		the first a * b square are rows in a c * d square
		*/

		int step = lineWidth * WIDTHBASE;

		//edit col edges
		for (int i = 0; i < mat.rows; i += step * c) {
			for (int j = 0; j < mat.cols; j++) {
				if (j / step % d < b) {
					//(a..c) * (0..b)
					{
						//up side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * a + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * c - lineWidth + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * c - lineWidth * 2 + k, j);
							rgba1[1] = color1[1];
						}
					}
				}
				else {
					//(0..a) * (b..d)
					{
						//up side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							Vec4b &rgba = mat.at<Vec4b>(i + step * a - lineWidth + k, j);
							rgba[1] = color[1];
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a - lineWidth * 2 + k, j);
							rgba1[1] = color1[1];
						}
					}
				}
			}
		}
	}
};