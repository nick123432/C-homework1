#include <iostream>
#include <stdlib.h>
#define strlength 6

using namespace std;

int main(void) {
	int number;
	int index = 0;
	int score_counter[strlength] = { 0 };
	int num[100];
	int spaceused;

	cout << "Please enter the grade: (enter -1 to stop entering)" << endl;

	do
	{
		cin >> number;
		num[index] = number;
		index++;
		spaceused = index;

		if (number == -1) {
			break;
		}

		for (int u = 0; u < 6; u++) {
			if (number == u) {
				score_counter[u] += 1;
			}
		}

	} while (index < 100);

	for (int k = 0; k < spaceused-1; k++) {
		cout << " " << num[k];
	}

	for(int i = 0; i < 6; i++)
	{
		cout << endl;
		cout << score_counter[i] << " grade(s) of " << i << endl;
	}

	return 0;
}