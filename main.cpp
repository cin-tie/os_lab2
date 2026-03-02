#include "threads.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Enter array size: ";
	cin >> size;

	arr = new int[size];

	cout << "Enter array elements: ";
	for(int i = 0; i < size; ++i){
		cin >> arr[i];
	}

}
