#include <iostream>
using namespace std;

class HotDogStand {
public:
	HotDogStand(int ID, int sold_num);   //set initial value
	void JustSold(int num);              //compute both the value of total and stand sold
	int get_sold();                      //get value of stand sold
	static int get_total();              //get value of total sold
private:
	int ID_num;
	int sold = 0;
	static int total_number;
};

int HotDogStand::total_number = 0;

HotDogStand::HotDogStand(int ID, int sold_num) : ID_num(ID), sold(sold_num) {
	total_number += sold_num;
}

void HotDogStand::JustSold(int num) {
	total_number += num;
	sold += num;
}

int HotDogStand::get_sold(){
	return sold;
}

int HotDogStand::get_total() {
	return total_number;
}

int main() {
	HotDogStand Id1(101, 5), Id2(102, 9), Id3(103, 3);    //set the initial value

	int ID;
	int num;
	int count;

	cout << "101 stand sold " << Id1.get_sold() << " hotdogs" << endl;
	cout << "102 stand sold " << Id2.get_sold() << " hotdogs" << endl;
	cout << "103 stand sold " << Id3.get_sold() << " hotdogs" << endl;
	cout << "Today you have sold " << HotDogStand::get_total() << "hotdogs" << endl;

	do {
		cout << "which stand are you going to buy the hotdog?(101,102,103)(-1 to stop)" << endl;
		cin >> ID;
		if (ID != -1) {
			cout << "How many would you want to buy?" << endl;
			cin >> num;
			switch (ID) {
			case 101:
				Id1.JustSold(num);
				break;
			case 102:
				Id2.JustSold(num);
				break;
			case 103:
				Id3.JustSold(num);
				break;
			default:
				cout << "Enter error." << endl;
				break;
			}
		}
		else {
			cout << "End" << endl;
		}
	} while (ID != -1);


	cout << "101 stand sold " << Id1.get_sold() << " hotdogs" << endl;
	cout << "102 stand sold " << Id2.get_sold() << " hotdogs" << endl;
	cout << "103 stand sold " << Id3.get_sold() << " hotdogs" << endl;
	cout << "Today you have sold " << HotDogStand::get_total() << "hotdogs" << endl;

	return 0;
}
