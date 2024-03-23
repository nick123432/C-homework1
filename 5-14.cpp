#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void rate(int movie_num[], int rate[]) {
	for (int i = 0; i < 3; i++) {
		cin >> movie_num[i] >> rate[i];
		movie_num[i] -= 100;
	}
}

int distance(int review[4][6], int movie_num[], int rate[]) {
	int sum[4] = {0};
	double sqrtsum[4];
	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			sum[j] += pow((rate[i] - review[j][movie_num[i]]), 2);
		}
	}
	for (int i = 0; i < 4; i++) {
		sqrtsum[i] = sqrt((double)sum[i]);
	}

	for (int i = 1; i < 4; i++) {
		if (sqrtsum[i] < sqrtsum[index]) {
			index = i;
		}
	}
	return index;
}


int main(void) {

	int review[4][6] = { {3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2} };
	int movie[3];
	int rating[3];
	int index;

	cout << "Please enter the movie you are going to rate." << endl;

	rate(movie, rating);
	index = distance(review, movie, rating);

	for (int i = 0; i < 6; i++) {
		if (i != movie[0] && i != movie[1] && i != movie[2]) {
			cout << "a rating of " << review[index][i] << " for movie " << 100 + i << endl;

			
		}
	}
	return 0;
}