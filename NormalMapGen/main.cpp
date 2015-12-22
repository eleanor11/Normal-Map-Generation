#include<iostream> 
#include "normalGen.h"


using namespace std;

void NormalMapGen1(){

	//Mat mat1 = imread("1.png");

	Mat mat(2048, 2048, CV_8UC4);



	int t = 1;


	for (int i = 0; i < mat.rows; i++) {
		int start = 0;
		start = (i % 40 / 8 - 2) * 8;
		for (int j = 0; j < mat.cols; j += t * 8) {

			if (false) {
				/*
				int start = (i % 40 / 8 - 2) * 8;
				j += t * 40
				*/
				if (j < 0) continue;
				for (int k = 0; k < 24; k += 8) {
					if (j + k >= mat.cols) continue;
					Vec4b&rgba0 = mat.at<Vec4b>(i, j + k);
					rgba0[0] = 191;
					rgba0[1] = 127;
					rgba0[2] = 0;
					rgba0[3] = UCHAR_MAX;

					if (j + t * 1 + k >= mat.cols) continue;
					Vec4b&rgba1 = mat.at<Vec4b>(i, j + t * 1 + k);
					rgba1[0] = 191;
					rgba1[1] = 127;
					rgba1[2] = 47;
					rgba1[3] = UCHAR_MAX;

					if (j + t * 2 + k >= mat.cols) continue;
					Vec4b&rgba2 = mat.at<Vec4b>(i, j + t * 2 + k);
					rgba2[0] = 255;
					rgba2[1] = 127;
					rgba2[2] = 63;
					rgba2[3] = UCHAR_MAX;

					if (j + t * 3 + k >= mat.cols) continue;
					Vec4b&rgba3 = mat.at<Vec4b>(i, j + t * 3 + k);
					rgba3[0] = 255;
					rgba3[1] = 127;
					rgba3[2] = 127;
					rgba3[3] = UCHAR_MAX;

					if (j + t * 4 + k >= mat.cols) continue;
					Vec4b&rgba4 = mat.at<Vec4b>(i, j + t * 4 + k);
					rgba4[0] = 255;
					rgba4[1] = 127;
					rgba4[2] = 127;
					rgba4[3] = UCHAR_MAX;

					if (j + t * 5 + k >= mat.cols) continue;
					Vec4b&rgba5 = mat.at<Vec4b>(i, j + t * 5 + k);
					rgba5[0] = 255;
					rgba5[1] = 127;
					rgba5[2] = 191;
					rgba5[3] = UCHAR_MAX;

					if (j + t * 6 + k >= mat.cols) continue;
					Vec4b&rgba6 = mat.at<Vec4b>(i, j + t * 6 + k);
					rgba6[0] = 191;
					rgba6[1] = 127;
					rgba6[2] = 207;
					rgba6[3] = UCHAR_MAX;

					if (j + t * 7 + k >= mat.cols) continue;
					Vec4b&rgba7 = mat.at<Vec4b>(i, j + t * 7 + k);
					rgba7[0] = 191;
					rgba7[1] = 127;
					rgba7[2] = 255;
					rgba7[3] = UCHAR_MAX;
				}

			}


			if (false) {
				/*

				if (i % 32 < 24){
					start = 8;
				}
				t * 16
				*/
				for (int k = 0; k < t; k++) {
					Vec4b&rgba0 = mat.at<Vec4b>(i, j + k);
					rgba0[0] = 191;
					rgba0[1] = 127;
					rgba0[2] = 0;
					rgba0[3] = UCHAR_MAX;

					Vec4b&rgba1 = mat.at<Vec4b>(i, j + t * 1 + k);
					rgba1[0] = 191;
					rgba1[1] = 127;
					rgba1[2] = 47;
					rgba1[3] = UCHAR_MAX;

					Vec4b&rgba2 = mat.at<Vec4b>(i, j + t * 2 + k);
					rgba2[0] = 255;
					rgba2[1] = 127;
					rgba2[2] = 63;
					rgba2[3] = UCHAR_MAX;

					Vec4b&rgba3 = mat.at<Vec4b>(i, j + t * 3 + k);
					rgba3[0] = 255;
					rgba3[1] = 127;
					rgba3[2] = 127;
					rgba3[3] = UCHAR_MAX;

					Vec4b&rgba4 = mat.at<Vec4b>(i, j + t * 4 + k);
					rgba4[0] = 255;
					rgba4[1] = 127;
					rgba4[2] = 127;
					rgba4[3] = UCHAR_MAX;

					Vec4b&rgba5 = mat.at<Vec4b>(i, j + t * 5 + k);
					rgba5[0] = 255;
					rgba5[1] = 127;
					rgba5[2] = 191;
					rgba5[3] = UCHAR_MAX;

					Vec4b&rgba6 = mat.at<Vec4b>(i, j + t * 6 + k);
					rgba6[0] = 191;
					rgba6[1] = 127;
					rgba6[2] = 207;
					rgba6[3] = UCHAR_MAX;

					Vec4b&rgba7 = mat.at<Vec4b>(i, j + t * 7 + k);
					rgba7[0] = 191;
					rgba7[1] = 127;
					rgba7[2] = 255;
					rgba7[3] = UCHAR_MAX;
				}

			}

			if (false) {
				/*
				
					if (i % 16 < 8){
						start = 8;
					}
					t * 16
				*/
				for (int k = 0; k < t; k++) {
					Vec4b&rgba0 = mat.at<Vec4b>(i, j + k);
					rgba0[0] = 191;
					rgba0[1] = 127;
					rgba0[2] = 0;
					rgba0[3] = UCHAR_MAX;

					Vec4b&rgba1 = mat.at<Vec4b>(i, j + t * 1 + k);
					rgba1[0] = 191;
					rgba1[1] = 127;
					rgba1[2] = 47;
					rgba1[3] = UCHAR_MAX;

					Vec4b&rgba2 = mat.at<Vec4b>(i, j + t * 2 + k);
					rgba2[0] = 255;
					rgba2[1] = 127;
					rgba2[2] = 63;
					rgba2[3] = UCHAR_MAX;

					Vec4b&rgba3 = mat.at<Vec4b>(i, j + t * 3 + k);
					rgba3[0] = 255;
					rgba3[1] = 127;
					rgba3[2] = 127;
					rgba3[3] = UCHAR_MAX;

					Vec4b&rgba4 = mat.at<Vec4b>(i, j + t * 4 + k);
					rgba4[0] = 255;
					rgba4[1] = 127;
					rgba4[2] = 127;
					rgba4[3] = UCHAR_MAX;

					Vec4b&rgba5 = mat.at<Vec4b>(i, j + t * 5 + k);
					rgba5[0] = 255;
					rgba5[1] = 127;
					rgba5[2] = 191;
					rgba5[3] = UCHAR_MAX;

					Vec4b&rgba6 = mat.at<Vec4b>(i, j + t * 6 + k);
					rgba6[0] = 191;
					rgba6[1] = 127;
					rgba6[2] = 207;
					rgba6[3] = UCHAR_MAX;

					Vec4b&rgba7 = mat.at<Vec4b>(i, j + t * 7 + k);
					rgba7[0] = 191;
					rgba7[1] = 127;
					rgba7[2] = 255;
					rgba7[3] = UCHAR_MAX;
				}

			}



			
		}
	}

	std::vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	imwrite("newim.png", mat, compression_params);
}

void NormalMapGen() {
	NormalMap nmap = NormalMap(512);
	nmap.setLineStyle(3);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(2, 2, 4, 4);
	nmap.RowsFirstEdge(2, 2, 4, 4);
	nmap.writeToFile("mat_2244_edge3.png");


	/*
		size
	*
	nmap.setLineStyle(0);

	nmap = NormalMap(64);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_64.png");

	nmap = NormalMap(128);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_128.png");

	nmap = NormalMap(256);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_256.png");

	nmap = NormalMap(512);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_512.png");

	nmap = NormalMap(1024);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_1024.png");

	nmap = NormalMap(2048);
	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_2048.png");
	*/


	/*
	mats
	*
	nmap.RowsGenInterval(1, 1, 1, 1);
	nmap.writeToFile("mat_1111_0_1.png");

	nmap.ColsGenInterval(1, 1, 1, 1);
	nmap.writeToFile("mat_c1111_0_1.png");

	nmap.ColsGenAll();
	nmap.RowsGenInterval(1, 1, 2, 2);
	nmap.writeToFile("mat_1122_0_1.png");

	nmap.ColsGenAll();
	nmap.RowsGenInterval(2, 2, 4, 4);
	nmap.writeToFile("mat_2244_0_1.png");

	nmap.ColsGenAll();
	nmap.RowsGenInterval(3, 1, 4, 2);
	nmap.writeToFile("mat_3142_0_1.png");
	/**/
}

void NormalMapGet() {
	Mat mat = imread("newim.png", -1);
	Mat mat1 = imread("brick1N.png", -1);

	std::cout << mat.elemSize() << std::endl;

	if (0) {
		for (int i = 0; i < mat.rows; i++){
			for (int j = 0; j < mat.cols; j++) {
				Vec3b&rgba = mat.at<Vec3b>(i, j);
				//std::cout << int(rgba[0]) << ' ' << int(rgba[1]) << ' ' << int(rgba[2]) << std::endl;	
			}
		}
	}
	else {
		for (int i = 0; i < mat.rows; i++){
			for (int j = 0; j < mat.cols; j++) {
				Vec4b&rgba = mat.at<Vec4b>(i, j);
				std::cout << int(rgba[0]) << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < mat.rows; i++){
			for (int j = 0; j < mat.cols; j++) {
				Vec4b&rgba = mat.at<Vec4b>(i, j);
				std::cout << int(rgba[1]) << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < mat.rows; i++){
			for (int j = 0; j < mat.cols; j++) {
				Vec4b&rgba = mat.at<Vec4b>(i, j);
				std::cout << int(rgba[2]) << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < mat.rows; i++){
			for (int j = 0; j < mat.cols; j++) {
				Vec4b&rgba = mat.at<Vec4b>(i, j);
				std::cout << int(rgba[3]) << ' ';
			}
			std::cout << std::endl;
		}
	}

	system("pause");
}

int main()
{
	if (1) {
		NormalMapGen();
		//NormalMapGet();
	}
	else {
		NormalMapGet();
	}


	//imshow("im", mat);
	//waitKey(6000);


	return 0;

}