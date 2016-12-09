#include <iostream>
#include <string.h>
#include <cctype>
#include <unistd.h>
#include <stdlib.h>
#include <climits>
using namespace std;


class Array {
public:
	int *arr;
	int size;
	Array(int size) {
		// arr = (int*)realloc(temp, size * sizeof(int));
		arr = (int*)malloc(size * sizeof(int));
		// cout << size << endl;
		for(int i = 0; i < size; i++) {
			// cout << i << endl;
			arr[i] = i;
		}
		this -> size = size;
	}

	void setSize(int size) {
		arr = (int*)malloc(size * sizeof(int));
		for(int i = 0; i < size; i++) {
			arr[i] = i;
		}
		this -> size = size;
	}

	void reverse() {
		for(int i = 0; i < size/2; i++) {
			int temp;
			temp = arr[i];
			arr[i] = arr[size-i-1];
			arr[size-i-1] = temp;
		}
	}

	friend std::ostream& operator<< (std::ostream&, const Array&);

};

class MyVector : public Array {
public:
	MyVector(int size) : Array(size) {

	}

	MyVector& operator=(const Array arr) {
		// cout << "here" << endl;
		MyVector *v = new MyVector(arr.size);
		v -> size = arr.size;
		for(int i = 0; i < v -> size; i++) {
			v -> arr[i] = arr.arr[i];
		}
		return *v;
	}

};

std::ostream& operator<< (std::ostream& out, const Array& arr) {
	for(int i = 0; i < arr.size; i++) {
		out << arr.arr[i];
		if(i != (arr.size - 1)) {
			out << ",";
		}
	}
	// out<< endl;
	return out;
}


int main(int argc, char const *argv[])
{
	// MyVector v1(5);
	// MyVector v2(5);
	// v2 = v1;
	// Array arr1 = v1;
	// v1.reverse();
	// cout << v1 << endl;
	// cout << v2 << endl;
	// cout << arr1 << endl;

	// -s <number>: specified the size of the vector to be created.
	// -S : tells to create a vector that supports shallow copy.
	// -D : tells to create a vector that supports deep copy.
	// -C : copy the previous vector to the current vector.
	// -R : reverses the content of the current vector.
	// -O p/c: prints the previous/current vector.

	// char currentArg;

	// while((*currentArg = getopt(argc, argv, "s:SDCRO:")) != -1) {
	// 	switch(currentArg) {
	// 		case 's':
	// 			cout << "-s" << " " << optarg << endl;
	// 		case 'S':
	// 			cout << "-S";
	// 		case 'D':
	// 			cout << "-D";
	// 		case 'C':
	// 			cout << "-C";
	// 		case 'R':
	// 			cout << "-R";
	// 		case 'O':
	// 			cout << "-O" << " " << optarg << endl;
	// 	}
	// }


	int i = 1;
	int arraySize;
	enum ArrayEnum {none, vector1, vector2, array1, array2};
	ArrayEnum current = none;
	ArrayEnum previous = none;
	MyVector v1(0);
	MyVector v2(0);
	Array arr1(0);
	Array arr2(0);
	while(argc > 1) {
		if(strcmp(argv[i], "-s") == 0) {
			if(atoi(argv[i+1])) {
				arraySize = atoi(argv[i+1]);
				i++;
				argc--;
			} else {
				cerr << "\n\n---Invalid Array Size---\n\n\n\n";
				cerr << "Usage: vector [Options]\n\n";
				cerr << "Options: -s <number>: specifies the size of the vector to be created.\n";
				cerr << "	 -S : tells to create a vector that supports shallow copy.\n";
				cerr << "	 -D : tells to create a vector that supports deep copy.\n";
				cerr << "	 -C : copies the previous vector to the current vector.\n";
				cerr << "	 -R : reverses the content of the current vector.\n";
				cerr << "	 -O p/c: prints the previous/current vector.\n\n\n\n";
				return (-1);
			}
		} else if(strcmp(argv[i], "-S") == 0) {
			// cout << "-S" << endl;
			if(previous == none || previous == vector1) {
				arr1.setSize(arraySize);
				if(previous == none) {
					previous = array1;
				} else {
					current = array1;
				}
			} else if(previous == array1) {
				arr2.setSize(arraySize);
				current = array2;
			}
			// cout << "-S" << endl;
			// isDeepCopy = false;
		} else if(strcmp(argv[i], "-D") == 0) {
			// cout << "-D" << endl;
			if(previous == none || previous == array1) {
				v1.setSize(arraySize);
				if(previous == none) {
					previous = vector1;
				} else {
					current = vector1;
				}
			} else if(previous == vector1) {
				v2.setSize(arraySize);
				current = vector2;
			}
			// cout << "-D" << endl;
			// isDeepCopy = true;
		} else if(strcmp(argv[i], "-C") == 0) {
			// cout << previous << endl;
			// cout << current << endl;
			if(previous == array1 && current == array2) {
				arr2 = arr1;
			} else if(previous == array1 && current == vector1) {
				// cout << "Keyur" << endl;
				v1 = arr1;
			} else if(previous == vector1 && current == vector2) {
				v2 = v1;
			} else if(previous == vector1 && current == array1) {
				arr1 = v1;
			} else {
				// error
			}
			// cout << "-C" << endl;
			// copyVector = true;
		} else if(strcmp(argv[i], "-R") == 0) {
			if(current == none) {
				if(previous == array1) {
					arr1.reverse();
				} else if(previous == vector1) {
					v1.reverse();
				} else if(previous == array2) {
					arr2.reverse();
				} else if(previous == vector2) {
					v2.reverse();
				} else {
					// error
				}
			} else {
				if(current == array1) {
					arr1.reverse();
				} else if(current == vector1) {
					v1.reverse();
				} else if(current == array2) {
					arr2.reverse();
				} else if(current == vector2) {
					v2.reverse();
				} else {
					// error
				}
			}
			// cout << "-R" << endl;
			// reverse = true;
		} else if(strcmp(argv[i], "-O") == 0) {
			// cout << "-O" << endl;
			if(argc > 2) {
				if(strcmp(argv[i+1], "p") == 0) {
					// cout << "p" << endl;
					// print = previous;
					if(previous == array1) {
						cout << arr1 << endl;
					} else if(previous == vector1) {
						cout << v1 << endl;
					} else {
						// error
						cout << "previous vector not set" << endl;
					}
					i++;
					argc--;
				} else if(strcmp(argv[i+1], "c") == 0) {
					// cout << "c" << endl;
					// print = current;
					if(current == array1) {
						cout << arr1 << endl;
					} else if(current == vector1) {
						cout << v1 << endl;
					} else if(current == array2) {
						cout << arr2 << endl;
					} else if(current == vector2) {
						cout << v2 << endl;
					} else {
						// error
						cout << "current vector not set" << endl;
					}
					i++;
					argc--;
				} else if(!(strcmp(argv[i+1], "c") == 0) && !(strcmp(argv[i+1], "p") == 0)) {
					// print = current;
					if(current == none) {
						if(previous == array1) {
							cout << arr1 << endl;
						} else if(previous == vector1) {
							cout << v1 << endl;
						} else {
							// error
							cout << "previous vector not set" << endl;
						}
					} else {
						if(current == array1) {
							cout << arr1 << endl;
						} else if(current == vector1) {
							cout << v1 << endl;
						} else if(current == array2) {
							cout << arr2 << endl;
						} else if(current == vector2) {
							cout << v2 << endl;
						} else {
							// error
							cout << "current vector not set" << endl;
						}
					}
				} else {
					cerr << "\n\n---Invalid Output Parameter---\n\n\n\n";
					cerr << "Usage: vector [Options]\n\n";
					cerr << "Options: -s <number>: specifies the size of the vector to be created.\n";
					cerr << "	 -S : tells to create a vector that supports shallow copy.\n";
					cerr << "	 -D : tells to create a vector that supports deep copy.\n";
					cerr << "	 -C : copies the previous vector to the current vector.\n";
					cerr << "	 -R : reverses the content of the current vector.\n";
					cerr << "	 -O p/c: prints the previous/current vector.\n\n\n\n";
					exit(0);
				}
			} else {
				// print = current;
					if(current == none) {
						if(previous == array1) {
							cout << arr1 << endl;
						} else if(previous == vector1) {
							cout << v1 << endl;
						} else {
							// error
							cout << "previous vector not set" << endl;
						}
					} else {
						if(current == array1) {
							cout << arr1 << endl;
						} else if(current == vector1) {
							cout << v1 << endl;
						} else if(current == array2) {
							cout << arr2 << endl;
						} else if(current == vector2) {
							cout << v2 << endl;
						} else {
							// error
							cout << "current vector not set" << endl;
						}
					}
			}

		} else {
			cerr << "\n\n---Invalid Argument---\n\n\n\n";
			cerr << "Usage: vector [Options]\n\n";
			cerr << "Options: -s <number>: specifies the size of the vector to be created.\n";
			cerr << "	 -S : tells to create a vector that supports shallow copy.\n";
			cerr << "	 -D : tells to create a vector that supports deep copy.\n";
			cerr << "	 -C : copies the previous vector to the current vector.\n";
			cerr << "	 -R : reverses the content of the current vector.\n";
			cerr << "	 -O p/c: prints the previous/current vector.\n\n\n\n";
			exit(0);
		}
		argc--;
		i++;
	}

	// cout << arr1 << endl;
	// cout << arr2 << endl;
	// cout << v1 << endl;
	// cout << v2 << endl;
	// cout << "returning 0" << endl;
	return 0;
}
