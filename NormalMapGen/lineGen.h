#include <math.h>

using namespace std;

double pi = 3.14159;

int changeCos(double theta) {
	double x = cos(theta / 180 * pi);

	x = x / 2 + 0.5;
	return int(x * 255);
}

int changeSin(double theta) {
	double x = sin(theta / 180 * pi);

	x = x / 2 + 0.5;
	return int(x * 255);
}

void lineGen() {

	cout << changeCos(-70) << ' ' << changeSin(-70) << endl;
	cout << changeCos(-45) << ' ' << changeSin(-45) << endl;
	cout << changeCos(-20) << ' ' << changeSin(-20) << endl;
	cout << changeCos(20) << ' ' << changeSin(20) << endl;
	cout << changeCos(45) << ' ' << changeSin(45) << endl;
	cout << changeCos(70) << ' ' << changeSin(70) << endl;
}