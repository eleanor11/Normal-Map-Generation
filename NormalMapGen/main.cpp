#include<iostream> 
#include "normalGen.h"
#include "lineGen.h"

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

void LinenPlain(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(1);
	nmap.ColsGenInterval(1, 2);
	nmap.RowsGenInterval(1, 1, 2, 2, 1, 1);
	//nmap.writeToFile("linenPlain_" + name + ".png");
	nmap.writeToFile("linenPlain");
}
void CreprDeChine(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(3);
	nmap.ColsGenInterval(1, 2);
	nmap.setLineStyle(2);
	nmap.RowsGenInterval(1, 1, 2, 2, 0, 1);
	//nmap.writeToFile("creprDeChine_" + name + ".png");

	nmap.writeToFile("creprDeChine");
}
void PolyesterStainCharmeuseFront(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(4);
	nmap.ColsGenAll();
	nmap.setLineStyle(5);
	nmap.RowsGenLean(1, 5, 1, 2);
	//nmap.writeToFile("polyesterStainCharmeuseFront_" + name + ".png");
	nmap.writeToFile("polyesterStainCharmeuseFront");

}
void PolyesterStainCharmeuseBack(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(6);
	nmap.ColsGenAll();
	nmap.setLineStyle(7);
	nmap.RowsGenLean(4, 5, 1, 2);
	//nmap.writeToFile("polyesterStainCharmeuseBack_" + name + ".png");
	nmap.writeToFile("polyesterStainCharmeuseBack");

}
void Velvet(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(9);
	nmap.ColsGenInterval(1, 2);
	nmap.setLineStyle(8);
	nmap.RowsGenInterval(1, 1, 2, 2, 0, 1);
	nmap.writeToFile("velvet_" + name + ".png");

}
void SilkShot(int size, string name) {
	NormalMap nmap = NormalMap(size);

	nmap.GenFlatAll();
	nmap.setLineStyle(11);
	nmap.ColsGenInterval(1, 2);
	nmap.setLineStyle(10);
	nmap.RowsGenInterval(1, 1, 2, 2, 0, 1);
	nmap.writeToFile("silkShot_" + name + ".png");
}
void NormalMapGen() {
	NormalMap nmap = NormalMap(512);

	//nmap.ColsGenAll();
	//nmap.RowsGenLean(4, 4, 3, 1);
	//nmap.writeToFile("mat_.png");

	/*all line model*/
	//nmap = NormalMap(64);
	//nmap.setLineStyle(1);
	//nmap.GenFlatAll();
	//nmap.RowsGenAll();
	//nmap.writeToFile("line0.png");
	//nmap.setLineStyle(1);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line1.png");

	//nmap.setLineStyle(2);
	//nmap.GenFlatAll();
	//nmap.RowsGenAll();
	//nmap.writeToFile("line2.png");
	//nmap.setLineStyle(3);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line3.png");

	//nmap.setLineStyle(4);
	//nmap.GenFlatAll();
	//nmap.RowsGenAll();
	//nmap.writeToFile("line4.png");
	//nmap.setLineStyle(5);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line5.png");

	//nmap.setLineStyle(6);
	//nmap.GenFlatAll();
	//nmap.RowsGenAll();
	//nmap.writeToFile("line6.png");
	//nmap.setLineStyle(7);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line7.png");

	//nmap.setLineStyle(8);
	//nmap.RowsGenAll();
	//nmap.writeToFile("line8.png");
	//nmap.setLineStyle(9);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line9.png");

	//nmap.setLineStyle(10);
	//nmap.GenFlatAll();
	//nmap.RowsGenAll();
	//nmap.writeToFile("line10.png");
	//nmap.setLineStyle(11);
	//nmap.ColsGenAll();
	//nmap.writeToFile("line11.png");

	//PolyesterStainCharmeuseBack(2048, "W1");
	//PolyesterStainCharmeuseBack(64, "64");
	//Velvet(2048, "W1");
	//Velvet(64, "64");
	//SilkShot(2048, "W1");
	//SilkShot(64, "64");

	LinenPlain(512, "512");
	CreprDeChine(512, "512");
	PolyesterStainCharmeuseFront(512, "512");
	PolyesterStainCharmeuseBack(512, "512");

	//LinenPlain(1024, "1024");
	//CreprDeChine(1024, "1024");
	//PolyesterStainCharmeuseFront(1024, "1024");
	//PolyesterStainCharmeuseBack(1024, "1024");

	//LinenPlain(2048, "2048");
	//CreprDeChine(2048, "2048");
	//PolyesterStainCharmeuseFront(2048, "2048");
	//PolyesterStainCharmeuseBack(2048, "2048");

	/*3 different tex*/
	//LinenPlain(2048, "W1");
	//LinenPlain(64, "64");
	//CreprDeChine(2048, "W1");
	//CreprDeChine(64, "64");
	//PolyesterStainCharmeuseFront(2048, "W1");
	//PolyesterStainCharmeuseFront(64, "64");
	
	/*different lines
	nmap.setLineStyle(5);
	nmap.ColsGenAll();
	nmap.setLineStyle(1);
	nmap.RowsGenLean(3, 6);
	nmap.writeToFile("lean0W11S51.png");

	nmap.setLineStyle(5);
	nmap.setLineWidth(1);
	nmap.ColsGenAll();
	nmap.setLineWidth(2);
	nmap.RowsGenLean(3, 6);
	nmap.writeToFile("lean1W12S55.png");

	nmap.setLineStyle(5);
	nmap.setLineWidth(1);
	nmap.ColsGenAll();
	nmap.RowsGenLean(3, 6);
	nmap.writeToFile("lean2W11S55.png");

	nmap.setLineStyle(5);
	nmap.setLineWidth(1);
	nmap.ColsGenAll();
	nmap.setLineStyle(1);
	nmap.setLineWidth(2);
	nmap.RowsGenLean(3, 6);
	nmap.writeToFile("lean3W12S51.png");
	*/


	/*lean

	nmap.setLineStyle(1);
	nmap.setLineWidth(1);

	nmap.ColsGenAll();
	nmap.RowsGenLean(3, 6);
	nmap.writeToFile("lean.png");

	nmap.ColsGenAll();
	nmap.RowsGenLean(1, 6);
	nmap.writeToFile("lean1.png");

	nmap.ColsGenAll();
	nmap.RowsGenLean(2, 5, 1, 2);
	nmap.writeToFile("lean2.png");

	nmap.ColsGenAll();
	nmap.RowsGenLean(2, 4, 2, 3);
	nmap.writeToFile("lean3.png");
	*/


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

		if (1) {
			NormalMapGen();
			//NormalMapGet();
		}
		else {
			NormalMapGet();
		}

	}
	else {


		//plain
		//lineGen(8, -75);

		//crete de chine
		//lineGen(7, -85);
		//lineGen(6, -60);

		//front polyester stain charmeuse 
		//lineGen(2, -45);
		//lineGen(2, -65);
		//lineGen(4, -85);

		//back polyester stain charmeuse 
		//lineGen(2, -45);
		//lineGen(3, -83);
		//lineGen(3, -87);

		//velvet 1
		//lineGen(64, 0);

		//velvet 2
		//lineGen(56, 0);

		//silk shot
		//lineGen(4, -60);
		//lineGen(8, -30);	//kou diao zhong jian si ge

		system("pause");

		return 0;

	}


	//imshow("im", mat);
	//waitKey(6000);


	return 0;

}