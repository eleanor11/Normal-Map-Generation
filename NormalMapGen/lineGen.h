#include <math.h>

using namespace std;

double pi = 3.14159;

int changeCos(double theta) {
	double x = cos(theta);

	x = x / 2 + 0.5;
	return int(x * 255);
}

int changeSin(double theta) {
	double x = sin(theta);

	x = x / 2 + 0.5;
	return int(x * 255);
}

void exchange(double x) {
	double y = sqrt(1 - x * x);
	double theta = atan2(y, x);

	//cout << x << " " << y << " ";
	cout << int(theta / pi * 180) << " " << changeCos(theta) << " " << changeSin(theta) << endl;
}

void lineGen(int t) {

	double tmp = 2.0 / (t - 1);
	for (int i = 0; i < t; i++) {
		double x = tmp * i - 1;
		exchange(x);
	}

}

void lineGen(int t, double start) {
	double a = start / 180 * pi;
	double s = cos(a);
	double tmp = 2 * s / (t - 1);
	for (int i = 0; i < t; i++) {
		double x = tmp * i - s;
		exchange(x);
	}
}