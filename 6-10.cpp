#include<iostream>
using namespace std;

class weight {
	private:

		double weightinPounds;

	public:
		void setweightpounds(double);
		void setweightkilograms(double);
		void setweightounces(double);
		double getweightinpounds();
		double getweightinkilograms();
		double getweightinounces();
};

//setter
void weight::setweightpounds(double pounds){
	weightinPounds = pounds;
}

void weight::setweightkilograms(double kilograms) {
	weightinPounds = kilograms*2.21;
}

void weight::setweightounces(double ounces) {
	weightinPounds = ounces/16.0;
}

//getter
double weight::getweightinpounds() {
	return weightinPounds;
}

double weight::getweightinkilograms() {
	return weightinPounds/2.21;
}

double weight::getweightinounces() {
	return weightinPounds*16;
}

int main() {
	weight myweight;
	char scale;
	double value;

	cout << "Please choose the scale.(p for pounds, k for kilograms, o for ounces.)" << endl;
	cin >> scale;
	cout << "please enter the value" << endl;
	cin >> value;

	if (scale == 'p') {
		myweight.setweightpounds(value);

		cout << "the weight in pounds =>" << myweight.getweightinpounds() << " lbs." << endl;
		cout << "the weight in kilograms =>" << myweight.getweightinkilograms() << " kg." << endl;
		cout << "the weight in ounces =>" << myweight.getweightinounces() << " oz." << endl;
	}
	else if (scale == 'k') {
		myweight.setweightpounds(value);

		cout << "the weight in pounds =>" << myweight.getweightinpounds() << " lbs." << endl;
		cout << "the weight in kilograms =>" << myweight.getweightinkilograms() << " kg." << endl;
		cout << "the weight in ounces =>" << myweight.getweightinounces() << " oz." << endl;
	}
	else if (scale == 'o') {
		myweight.setweightounces(value);

		cout << "the weight in pounds =>" << myweight.getweightinpounds() << " lbs." << endl;
		cout << "the weight in kilograms =>" << myweight.getweightinkilograms() << " kg." << endl;
		cout << "the weight in ounces =>" << myweight.getweightinounces() << " oz." << endl;
	}

	system("pause");
	return 0;
}