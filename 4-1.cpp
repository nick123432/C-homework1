#include <iostream>
#include <stdlib.h>
using namespace std;

void TimeInput(int& hr, int& min) {
	cout << "Please enter the time in the form of HH MM" << endl;
	cin >> hr >> min;
}

void TimeConversion(int& hr, char& A_or_P) {
	
	if (hr > 12) {
		A_or_P = 'P';
		hr = hr - 12;
	}
	else {
		A_or_P = 'A';
	}
}

void TimeOutput(int hr, int min, char& A_or_P) {
	
	cout << "The time after convert will be " << hr << ":" << min << " " << A_or_P << endl;

}

int main(void) {
	int hr, min;
	char A_P;
	char again;
	do
	{
		TimeInput(hr, min);
		TimeConversion(hr, A_P);
		TimeOutput(hr, min, A_P);

		cout << "Do you want to convert again?" << endl;
		cin >> again;

	} while (again == 'y');

	return 0;
}