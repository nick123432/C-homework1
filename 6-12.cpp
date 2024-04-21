#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include<fstream>
using namespace std;

class BoxOfProduce {

private:
	string items[3];
public:
	
	void setitem(string list[]);
	void displayItem();
	void substituteItem(int, const string&);
};

string randombox(string list[]) {
	return list[rand() % 5];
}

void BoxOfProduce::setitem(string list[]) {
	for (int i = 0; i < 3; i++) {
		items[i] = randombox(list);
	}
}

void BoxOfProduce::displayItem() {
	cout << "Items in the box =>" << endl;
	for (int i = 0; i < 3; i++) {
		cout << items[i] <<"," << endl;
	}
}

void BoxOfProduce::substituteItem(int index, const string& newitem) {
	if (index >= 0 && index < 5) {
		items[index] = newitem;
		cout << "Item substituted successfully." << endl;
	}
	else {
		cout << "Invalid index." << endl;
	}

}

void InputFile(string list[]) {
	fstream inputfile;
	inputfile.open("input.txt");
	for (int i = 0; i < 5; i++) {
		inputfile >> list[i];
	}
}


int main() {
	srand(time(0));
	int place;
	string produce[5];
	string newproduce;
	char y_n;

	BoxOfProduce box;
	InputFile(produce);

	box.setitem(produce);
	box.displayItem();

	
	do{
		cout << "Do you want to substitute the produce?" << endl;
		cin >> y_n;

		cout << "Please enter the index you want to substitute:" << endl;
		cin >> place;
		cout << "Please enter the produce you want to substitute:" << endl;
		cin >> newproduce;

		box.substituteItem(place - 1, newproduce);
		box.displayItem();

	} while (y_n == 'y');

	system("pause");
	return 0;
}