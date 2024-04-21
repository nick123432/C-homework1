#include<iostream>

using namespace std;

class Money {
private:
	int dollars;
	int cents;

public:
	void setMoney();
	void readMoney();
	double MoneyAmount(int, int);
};

void Money::setMoney() {
	int Dollar;
	int Cent;
	cout << "Enter the number of dollars:" << endl;
	cin >> Dollar;
	dollars = Dollar;
	cout << "Enter the number of cents:" << endl;
	cin >> Cent;
	cents = Cent;
}

void Money::readMoney() {
	cout << "You have " << dollars << " dollar(s)." << endl;
	cout << "You have " << cents << " cent(s)." << endl;
}

double Money::MoneyAmount(int dol, int cen) {
	dol = dollars;
	cen = cents;
	return dol + (cen * 0.01);
}

int main() {
	Money money;
	int dollars = 0;
	int cents = 0;
	double amount = 0;
	char y_n;

	do
	{
		money.setMoney();
		money.readMoney();
		amount = money.MoneyAmount(dollars, cents);
		cout << "You have " << amount << " dollars in total." << endl;

		cout << "Would you like to run again?" << endl;
		cin >> y_n;

	} while (y_n == 'y');


	system("pause");
	return 0;
}