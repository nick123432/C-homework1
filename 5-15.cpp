#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

int random() {
	return (rand() % 3 + 1);
}

int main() {

	srand(time(NULL));
	int number[10] = { 0 };
	int PIN =12345;
	int pin = 0;
	int response = 0;
	int count = 0;

	for (int i = 0; i < 10; i++) {
		number[i] = random();
	}
	cout << endl << "PIN=>";
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl << "NUM=>";
	for (int i = 0; i < 10; i ++ ) {
		cout << number[i] << " ";
	}

	cout << endl;
	while (PIN > 0) {
		pin += number[(PIN % 10)] * pow(10, count);
		PIN /= 10;
		count++;
	}

	cout << "Please enter the pin which is after converted:" << endl;
	cin >> response;

	if (response == pin) {
		cout << "Correct" << endl;
	}
	else {
		cout << "Wrong" << endl;
	}
	
	return 0;
}