#include <iostream>
#include <unordered_map>

using namespace std;

int findSubMatrix(unordered_map<int,int>& sums, int x1, int y1, int x2, int y2) {
	int bigSquareSum;
	int horizontalSquareSum;
	int verticalSquareSum;
	int smallSquareSum;
		if(x1 <= x2 && y1 <= y2) {
			bigSquareSum = sums.at(x2*10+y2);
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
				smallSquareSum = 0;
				if(x1 == 0 || x2 == 0) {
					horizontalSquareSum = 0;
				} else {
					horizontalSquareSum = (sums.at((x1-1)*10+y2));
				}
				if(y1 == 0 || y2 == 0) {
					verticalSquareSum = 0;
				} else {
					verticalSquareSum = (sums.at(x2*10+(y1-1)));
				}
			} else {
				horizontalSquareSum = (sums.at((x1-1)*10+y2));
				verticalSquareSum = (sums.at(x2*10+(y1-1)));
				smallSquareSum = (sums.at((x1-1)*10+(y1-1)));
			}
		} else if(x1 < x2 && y1 > y2) {
			bigSquareSum = sums.at(x2*10+y1);
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
				smallSquareSum = 0;
				if(x1 == 0 || x2 == 0) {
					horizontalSquareSum = 0;
				} else {
					horizontalSquareSum = (sums.at(x2*10+(y2-1)));
				}
				if(y1 == 0 || y2 == 0) {
					verticalSquareSum = 0;
				} else {
					verticalSquareSum = (sums.at((x1-1)*10+y1));
				}
			} else {
				horizontalSquareSum = (sums.at(x2*10+(y2-1)));
				verticalSquareSum = (sums.at((x1-1)*10+y1));
				smallSquareSum = (sums.at((x1-1)*10+(y2-1)));
			}
		} else if(x1 > x2 && y1 < y2) {
			bigSquareSum = sums.at(x1*10+y2);
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
				smallSquareSum = 0;
				if(x1 == 0 || x2 == 0) {
					horizontalSquareSum = 0;
				} else {
					horizontalSquareSum = (sums.at(x1*10+(y1-1)));
				}
				if(y1 == 0 || y2 == 0) {
					verticalSquareSum = 0;
				} else {
					verticalSquareSum = (sums.at((x2-1)*10+y2));
				}
			} else {
				horizontalSquareSum = (sums.at(x1*10+(y1-1)));
				verticalSquareSum = (sums.at((x2-1)*10+y2));
				smallSquareSum = (sums.at((x2-1)*10+(y1-1)));
			}
		} else if(x1 >= x2 && y1 >= y2) {
			bigSquareSum = sums.at(x1*10+y1);
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
				smallSquareSum = 0;
				if(x1 == 0 || x2 == 0) {
					horizontalSquareSum = 0;
				} else {
					horizontalSquareSum = (sums.at((x2-1)*10+y1));
				}
				if(y1 == 0 || y2 == 0) {
					verticalSquareSum = 0;
				} else {
					verticalSquareSum = (sums.at(x1*10+(y2-1)));
				}
			} else {
				horizontalSquareSum = (sums.at((x2-1)*10+y1));
				verticalSquareSum = (sums.at(x1*10+(y2-1)));
				smallSquareSum = (sums.at((x2-1)*10+(y2-1)));
			}
		}
	return bigSquareSum - horizontalSquareSum - verticalSquareSum + smallSquareSum;
}
int main(int argc, char const *argv[])
{
	int arr[7][10] = { {1,2,3,4,5,6,7,8,9,10},
						{11,12,13,14,15,16,17,18,19,20},
						{21,22,23,24,25,26,27,28,29,30},
						{31,32,33,34,35,36,37,38,39,40},
						{41,42,43,44,45,46,47,48,49,50},
						{51,52,53,54,55,56,57,58,59,60},
						{61,62,63,64,65,66,67,68,69,70},
						// {71,72,73,74,75,76,77,78,79,80},
						// {81,82,83,84,85,86,87,88,89,90},
						// {91,92,93,94,95,96,97,98,99,100}
					  };


	int arrayCols = (sizeof((arr[0]))/sizeof((arr[0][0])));
	int arrayRows = (sizeof((arr))/sizeof((arr[0])));
	unordered_map<int,int> sums;
	for(int i = 0; i < arrayRows; i++) {
		for(int j = 0; j < arrayCols; j++) {
			int tempSum = 0;
			for(int m = 0; m <= i; m++) {
				for(int n = 0; n <= j; n++) {
					tempSum += arr[m][n];
				}
			}
			pair<int,int> sumPair ((i*10+j), tempSum);
			sums.insert(sumPair);
		}
	}
	while(1) {
		int x1, x2, y1, y2;
		cout << "Insert row coordinate of First Element: ";
		cin >> x1;

		if(x1 < 0 || x1 > arrayRows - 1) {
			cerr << "Invalid Coordinate\nStarting Over...\n\n" << endl;
			continue;
		}

		cout << "Insert column coordinate of First Element: ";
		cin >> y1;

		if(y1 < 0 || y1 > arrayCols - 1) {
			cerr << "Invalid Coordinate\nStarting Over...\n\n" << endl;
			continue;
		}

		cout << "Insert row coordinate of Second Element: ";
		cin >> x2;

		if(x2 < 0 || x2 > arrayRows - 1) {
			cerr << "Invalid Coordinate\nStarting Over...\n\n" << endl;
			continue;
		}

		cout << "Insert column coordinate of Second Element: ";
		cin >> y2;

		if(y2 < 0 || y2 > arrayCols - 1) {
			cerr << "Invalid Coordinate\nStarting Over...\n\n" << endl;
			continue;
		}

		cout << findSubMatrix(sums, x1, y1, x2, y2) << endl;
	}
	return 0;
}
