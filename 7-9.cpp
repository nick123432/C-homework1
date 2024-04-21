#include<iostream>
#include<cmath>
using namespace std;

class zip_code {                                  
public:
	zip_code(int enter_zip_code);                 //change zip code to bar code
	zip_code(string enter_bar_code);              //change bar code to zip code
private:
	int zip_code_str = 0;                         //zip code integer
	string bar_code_str;                          //bar code string
	int number[5] = {};
};

zip_code::zip_code(string enter_bar_code) : bar_code_str(enter_bar_code) {      
	cout << "Your bar code is " << bar_code_str << endl;                      
	int count = 0;
	int index = 1;
	int num[5];
	for (int j = 0; j < 5; j++) {
		while (count < 5) {                                                   
			num[count] = bar_code_str[index] - '0';                           
			index++;
			count++;
		}
		count = 0;
		for (int i = 0; i < 5; i++) {                                         
			if (i == 0) {                                                     
				number[j] += num[i] * 7;
			}
			else if (i < 4) {
				number[j] += num[i] * pow(2, 3 - i);
			}
			else {
				number[j] += 0;
			}
		}
		if (number[j] == 11) {                                                
		}
	}
	for (int i = 0; i < 5; i++) {
		zip_code_str += number[i] * pow(10, 4 - i);                          
	}
	cout << "Your zip code is " << zip_code_str << endl;                      
}

zip_code::zip_code(int enter_zip_code) : zip_code_str(enter_zip_code) {       
	cout << "Your zip code is " << zip_code_str << endl;                      
	int count = 4;
	while (zip_code_str > 0) {                                              
		count--;
		zip_code_str /= 10;
	}
	cout << "Your bar code is " << "1";
	for (int i = 0; i < 5; i++) {                                             
		switch (number[i]) {
		case 0:
			bar_code_str = "11000";
			break;
		case 1:
			bar_code_str = "00011";
			break;
		case 2:
			bar_code_str = "00101";
			break;
		case 3:
			bar_code_str = "00110";
			break;
		case 4:
			bar_code_str = "01001";
			break;
		case 5:
			bar_code_str = "01010";
			break;
		case 6:
			bar_code_str = "01100";
			break;
		case 7:
			bar_code_str = "10001";
			break;
		case 8:
			bar_code_str = "10010";
			break;
		case 9:
			bar_code_str = "10100";
			break;
		}
		cout << bar_code_str;                                                
	}
	cout << "1" << endl;
}

int main() {
	char type;
	cout << "What type you want to input (zip code or bar code)(z or b)=>";
	cin >> type;                                        
	if (type == 'z') {
		int enter_zip_code;
		cout << "Enter the zip code =>";
		cin >> enter_zip_code;                          
		zip_code code(enter_zip_code);
	}
	else if (type == 'b') {
		string enter_bar_code;
		cout << "Enter the bar code =>";
		cin >> enter_bar_code;                          
		zip_code code2(enter_bar_code);
	}
	else {                                              
		cout << "Enter error!!" << endl;
	}
	return 0;
}