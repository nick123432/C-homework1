#include<iostream>
#include<stdlib.h>
using namespace std;

double ConvertToMPH(int min, int sec) {
	int hr;
	hr = (min * 60 + sec) / 3600;

	return hr;
}

double ConvertToMPH(double KPH) {
	double MPH;
	MPH = KPH / 1.61;
}

int main(void) {
	char again;
	int min, sec;
	double KPH;

	do {

		ConvertToMPH(min, sec);
		ConvertToMPH(KPH);

		cout << "Do you want to run the program again? (y for yes and n for no)" << endl;
		cin >> again;
	} while (again == 'y');

	return 0;
}
