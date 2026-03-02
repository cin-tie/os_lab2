#include "threads.h"
#include <iostream>

using namespace std;

int main(){
	int size;
	cout << "Enter array size: ";
	cin >> size;

	int* arr = new int[size];

	cout << "Enter array elements: ";
	for(int i = 0; i < size; ++i){
		cin >> arr[i];
	}

	ThreadData data;
	data.arr = arr;
	data.size = size;

	HANDLE hMinMax = CreateThread(NULL, 0, min_max, &data, 0, NULL);
	HANDLE hAverage = CreateThread(NULL, 0, average, &data, 0, NULL);

	WaitForSingleObject(hMinMax, INFINITE);
	WaitForSingleObject(hAverage, INFINITE);

	CloseHandle(hMinMax);
	CloseHandle(hAverage);

	for(int i = 0; i < size; ++i){
		if(arr[i] == data.min || arr[i] == data.max){
			arr[i] = (int)data.average;
		}
	}

	cout << "Result array: ";
	for(int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;
	return 0;

}
