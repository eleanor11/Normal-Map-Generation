#include<iostream> 
#include <vector>  
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

const int WIDTHBASE = 8;
const int COLORSIZE = 4;
const int LINESTYLES = 11;

/*verticle: x, y, z, a*/
uchar FLAT[COLORSIZE] = {127, 127, 255, 255};
uchar LINESTYLE[WIDTHBASE * COLORSIZE * LINESTYLES] = {	
	/* 0 */
	//circle(-70, -45, -20, 20, 45, 70)
	127, 247, 171, 255,
	127, 217, 217, 255,
	127, 171, 247, 255,
	127, 83, 247, 255,
	127, 37, 217, 255,
	127, 7, 171, 255,
	0, 0, 0, 0,
	0, 0, 0, 0,

	/* 1 */
	/*
	linen plain fabric
	60 degrees
	*/
	127, 191, 237, 255,
	127, 173, 246, 255,
	127, 154, 252, 255,
	127, 136, 254, 255,
	127, 118, 254, 255,
	127, 100, 252, 255,
	127, 81, 246, 255,
	127, 63, 237, 255,

	/* 2 */
	/*
	crepe de chine facric row
	*/
	127, 138, 254, 255,
	127, 134, 254, 255,
	127, 131, 254, 255,
	127, 127, 254, 255,
	127, 123, 254, 255,
	127, 120, 254, 255,
	127, 116, 254, 255,
	0, 0, 0, 0,

	/* 3 */
	/*
	crepe de chine facric col
	*/
	127, 191, 237, 255,
	127, 191, 237, 255,
	127, 165, 249, 255,
	127, 140, 254, 255,
	127, 114, 254, 255,
	127, 89, 249, 255,
	127, 63, 237, 255,
	127, 63, 237, 255,

	/* 4 */
	/*
	front side of polyester stain charmeuse facric row
	*/
	127, 138, 254, 255,
	127, 134, 254, 255,
	127, 131, 254, 255,
	127, 127, 254, 255,
	127, 123, 254, 255,
	127, 120, 254, 255,
	127, 116, 254, 255,
	0, 0, 0, 0,

	/* 5 */
	/*
	front side of polyester stain charmeuse facric col
	*/
	127, 217, 217, 255,
	127, 181, 243, 255,
	127, 138, 254, 255,
	127, 131, 254, 255,
	127, 123, 254, 255,
	127, 116, 254, 255,
	127, 73, 243, 255,
	127, 37, 217, 255,

	/* 0 */
	127, 255, 191, 255,
	127, 207, 191, 255,
	127, 191, 255, 255,
	127, 127, 255, 255,
	127, 127, 255, 255,
	127, 63, 255, 255,
	127, 47, 191, 255,
	127, 0, 191, 255,

	/* 1 */
	152, 233, 191, 255,
	152, 207, 191, 255,
	127, 191, 255, 255,
	127, 127, 255, 255,
	127, 127, 255, 255,
	127, 63, 255, 255,
	148, 47, 191, 255,
	148, 20, 191, 255,

	/* 2 */
	127, 255, 191, 255,
	127, 207, 191, 255,
	127, 191, 255, 255,
	127, 142, 255, 255,
	127, 112, 255, 255,
	127, 63, 255, 255,
	127, 47, 191, 255,
	127, 0, 191, 255,

	/* 3 */
	152, 233, 191, 255,
	152, 207, 191, 255,
	127, 191, 255, 255,
	127, 142, 255, 255,
	127, 112, 255, 255,
	127, 63, 255, 255,
	148, 47, 191, 255,
	148, 20, 191, 255,

	/* 4 */
	127, 255, 255, 255,
	127, 255, 255, 255,
	127, 127, 255, 255,
	127, 127, 255, 255,
	127, 127, 255, 255,
	127, 0, 255, 255,
	127, 0, 255, 255,
	127, 127, 255, 255,

														
};

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

		for (int i = 0; i < scale; i++) {
			for (int j = 0; j < scale; j++) {
				if (bmat.at<uchar>(i, j) > 0 && bmat.at<uchar>(i, j) < 255) {
					std::cout << i << ' ' << j << std::endl;
				}
			}
		}
		system("pause");

	}


	void GenFlatAll() {
		for (int i = 0; i < mat.rows; i++) {
			for (int j = 0; j < mat.cols; j++) {
				Vec4b &rgba = mat.at<Vec4b>(i, j);
				rgba[0] = FLAT[2];			//z
				rgba[1] = FLAT[1];			//x
				rgba[2] = FLAT[0];			//y
				rgba[3] = FLAT[3];			//a

				bmat.at<uchar>(i, j) = 127;
			}
		}
	}

	void RowsGenAll() {
		for (int i = 0; i < mat.rows; i += lineWidth * WIDTHBASE) {
			for (int j = 0; j < mat.cols; j++) {
				for (int k = 0; k < WIDTHBASE; k++) {
					uchar* color = lineStyle + k * COLORSIZE;
					if (color[0] == 0) continue;
					if (i + k * lineWidth >= mat.rows) {
						break;
					}
					for (int l = 0; l < lineWidth; l++) {
						if (i + k * lineWidth + l >= mat.rows) {
							break;
						}
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

		RowsGenInterval(a, b, c, d, 0, 0);
		return;

		//int step = lineWidth * WIDTHBASE;
		//for (int i = 0; i < mat.rows; i += step) {
		//	if (i / step % c < a) {
		//		for (int j = 0; j < mat.cols; j++){
		//			if (j / step % d < b) {
		//				for (int k = 0; k < WIDTHBASE; k++) {
		//					uchar* color = lineStyle + k * COLORSIZE;
		//					if (i + k * lineWidth>= mat.rows) {
		//						break;
		//					}
		//					for (int l = 0; l < lineWidth; l++) {
		//						if (i + k * lineWidth + l >= mat.rows) {
		//							break;
		//						}
		//						Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
		//						rgba[0] = color[2];			//z
		//						rgba[1] = color[1];			//x
		//						rgba[2] = color[0];			//y
		//						rgba[3] = color[3];			//a

		//						bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
		//					}
		//				}
		//			}
		//		}
		//	}
		//	else {
		//		for (int j = 0; j < mat.cols; j++){
		//			if (j / step % d >= b) {
		//				for (int k = 0; k < WIDTHBASE; k++) {
		//					uchar* color = lineStyle + k * COLORSIZE;
		//					for (int l = 0; l < lineWidth; l++) {
		//						Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
		//						rgba[0] = color[2];			//z
		//						rgba[1] = color[1];			//x
		//						rgba[2] = color[0];			//y
		//						rgba[3] = color[3];			//a

		//						bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
		//					}
		//				}
		//			}
		//		}

		//	}
		//}

	}
	void RowsGenInterval(int a, int b, int c, int d, int e, int f) {
		/*
		the first a * b square are rows in a (c * (e + 1)) * (d * (f + 1))square
		e is row interval and f is col interval
		*/

		int step = lineWidth * WIDTHBASE;
		int h = c * (e + 1), w = d * (f + 1);
		int hh = a * (e + 1), ww = b * (f + 1);
		for (int i = 0; i < mat.rows; i += step) {
			int tmp = i / step % h;
			if (tmp < hh && tmp % (e + 1) < 1) {
				for (int j = 0; j < mat.cols; j++){
					int tmp = j / step % w;
					//if (tmp < ww || (tmp >= ww && tmp % (f + 1) > 0)) {
					if (! (tmp >= ww && tmp % (f + 1) < 1)) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + k * COLORSIZE;
							if (color[0] == 0) continue;
							if (i + k * lineWidth >= mat.rows) {
								break;
							}
							for (int l = 0; l < lineWidth; l++) {
								if (i + k * lineWidth + l >= mat.rows) {
									break;
								}
								Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
								rgba[0] = color[2];			//z b
								rgba[1] = color[1];			//x g
								rgba[2] = color[0];			//y r
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i + k * lineWidth + l, j) = 0;
								//t = (1, 0, 0)
							}
						}
					}
				}
			}
			else if (tmp >= hh && tmp % (e + 1) < 1){
				for (int j = 0; j < mat.cols; j++){
					int tmp = j / step % w;
					//if (tmp >= ww || (tmp < ww && tmp % (f + 1) >= 1)) {
					if (! (tmp < ww && tmp % (f + 1) < 1)) {
						for (int k = 0; k < WIDTHBASE; k++) {
							uchar* color = lineStyle + k * COLORSIZE;
							if (color[0] == 0) continue;
							for (int l = 0; l < lineWidth; l++) {
								Vec4b &rgba = mat.at<Vec4b>(i + k * lineWidth + l, j);
								rgba[0] = color[2];			//z b
								rgba[1] = color[1];			//x g
								rgba[2] = color[0];			//y r
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
			b is total length(all cols),
			c is width
			d is total width(all rows)
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
						if (color[0] == 0) continue;
						if (i + k * lineWidth >= mat.rows) {
							break;
						}
						for (int l = 0; l < lineWidth; l++) {
							if (i + k * lineWidth + l >= mat.rows) {
								break;
							}
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
					if (color[0] == 0) continue;
					if (j + k * lineWidth >= mat.cols) {
						break;
					}
					for (int l = 0; l < lineWidth; l++) {
						if (j + k * lineWidth + l >= mat.cols) {
							break;
						}
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
							if (color[0] == 0) continue;
							if (j + k * lineWidth >= mat.cols) {
								break;
							}
							for (int l = 0; l < lineWidth; l++) {
								if (j + k * lineWidth + l >= mat.cols) {
									break;
								}
								Vec4b &rgba = mat.at<Vec4b>(i, j + k * lineWidth + l);
								rgba[0] = color[2];			//z b
								rgba[1] = color[0];			//x g 
								rgba[2] = color[1];			//y r
								rgba[3] = color[3];			//a

								bmat.at<uchar>(i, j + k * lineWidth + l) = 255;
								//t = (0, 1, 0)
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
							if (color[0] == 0) continue;
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

	//TODO:
	void RowsGenInterval(int a, int b, int c, int d, int e, int f, int ee, int ff){}
	void ColsGenInterval(int a, int b, int c, int d, int e, int f){}
	void ColsGenLean(int a, int b) {
		/*
		a is length,
		b is length(rows) interval,
		*/

		ColsGenLean(a, b, 1, 1);
	}
	void ColsGenLean(int a, int b, int c, int d) {

		/*
		a is length,
		b is total length(all rows),
		c is width
		d is total width(all cols)
		*/

		ColsGenLean(a, b, c, d, 0);
	}
	void ColsGenLean(int a, int b, int c, int d, int e) {
		/*
		a is length,
		b is total length(all rows),
		c is width
		d is total width(all cols)
		(b * d) ^ 2
		*/




	}

	//TODO END

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
							if (j + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + k);
							rgba[2] = color[1];

							if (j + lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							if (j + step * b - lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b - lineWidth + k);
							rgba[2] = color[1];

							if (j + step * b - lineWidth * 2 + k >= mat.cols) {
								break;
							}
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
							if (j + step * b + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b + k);
							rgba[2] = color[1];

							if (j + step * b + lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							if (j + step * d - lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * d - lineWidth + k);
							rgba[2] = color[1];

							if (j + step * d - lineWidth * 2 + k >= mat.cols) {
								break;
							}
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
							if (j + step * b + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b + k);
							rgba[2] = color[1];
							if (j + step * b + lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + step * b + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							if (j + step * d - lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * d - lineWidth + k);
							rgba[2] = color[1];
							if (j + step * d - lineWidth * 2 + k >= mat.cols) {
								break;
							}
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
							if (j + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + k);
							rgba[2] = color[1];
							if (j + lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i, j + lineWidth + k);
							rgba1[2] = color1[1];
						}
					}
					{
						//right side
						uchar* color = lineStyle;
						uchar* color1 = lineStyle + 1 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++) {
							if (j + step * b - lineWidth + k >= mat.cols) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i, j + step * b - lineWidth + k);
							rgba[2] = color[1];
							if (j + step * b - lineWidth * 2 + k >= mat.cols) {
								break;
							}
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
							if (i + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + k, j);
							rgba[1] = color[1];
							if (i + lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							if (i + step * a - lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * a - lineWidth + k, j);
							rgba[1] = color[1];
							if (i + step * a - lineWidth * 2 + k >= mat.rows) {
								break;
							}
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
							if (i + step * a + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * a + k, j);
							rgba[1] = color[1];
							if (i + step * a + lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							if (i + step * c - lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * c - lineWidth + k, j);
							rgba[1] = color[1];
							if (i + step * c - lineWidth * 2 + k >= mat.rows) {
								break;
							}
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
							if (i + step * a + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * a + k, j);
							rgba[1] = color[1];
							if (i + step * a + lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							if (i + step * c - lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * c - lineWidth + k, j);
							rgba[1] = color[1];
							if (i + step * c - lineWidth * 2 + k >= mat.rows) {
								break;
							}
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
							if (i + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + k, j);
							rgba[1] = color[1];
							if (i + lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i + lineWidth + k, j);
							rgba1[1] = color1[1];
						}
					}
					{
						//down side
						uchar* color = lineStyle + 7 * COLORSIZE;
						uchar* color1 = lineStyle + 6 * COLORSIZE;
						for (int k = 0; k < lineWidth; k++){
							if (i + step * a - lineWidth + k >= mat.rows) {
								break;
							}
							Vec4b &rgba = mat.at<Vec4b>(i + step * a - lineWidth + k, j);
							rgba[1] = color[1];
							if (i + step * a - lineWidth * 2 + k >= mat.rows) {
								break;
							}
							Vec4b &rgba1 = mat.at<Vec4b>(i + step * a - lineWidth * 2 + k, j);
							rgba1[1] = color1[1];
						}
					}
				}
			}
		}
	}
};