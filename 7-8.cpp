#include<iostream>
#include<vector>                                        
using namespace std;

int find_grade(vector<int> grade, int find_number) {    //find grade
	int count = 0;
	for (int i = 0; i < grade.size(); i++) {
		if (grade[i] == find_number) {                  //if the grade exist, count +1 
			count++;                                   
		}
	}
	return count;                                       //return count
}

int main() {
	vector<int> grade;                                  //set the vector
	int number;
	int max_number;
	cout << "Enter the grade maximum =>";
	cin >> max_number;                                  //input the grade maximum
	do {
		cout << "Enter the grade =>";
		cin >> number;                                  //input 
		if (number > -1 && number <= max_number) {
			grade.push_back(number);                    //push back to vector
		}
		else {
			cout << "Enter error!!" << endl;            //if number exceed the range, output false
		}
	} while (number != -1);
	for (int i = 0; i <= max_number; i++) {
		cout << find_grade(grade, i) << " grades of " << i << endl;      //output the grade 
	}
	return 0;
}