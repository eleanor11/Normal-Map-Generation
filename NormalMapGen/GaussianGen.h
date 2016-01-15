
#include <random>  
#include <algorithm>  
#include <cmath>  
#include <time.h>

void GaussianGen(int scale) {
	cv::Mat mat(scale, scale, CV_8UC1);

	double tmp1 = 1.0 / scale;
	double tmp2 = 3.1415926545 / 2 / (scale - 1);

	std::default_random_engine e;
	e.seed(time(NULL));

	for (int i = scale - 1; i >= 0; i--) {
		for (int j = 0; j < scale; j++) {
			double w = tmp1 * (scale - i);
			double theta = tmp2 * j;
			
			std::normal_distribution<double> n(theta, w);
			double result = n(e);

			cout << w << " " << theta << ": " << result << endl;
		}
	}

	imwrite("gaussianMap.png", mat);

}