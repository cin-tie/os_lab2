#include "threads.h"
#include <iostream>

using namespace std;

DWORD WINAPI average(LPVOID lpParam){
	ThreadData* data = (ThreadData*)lpParam;
	int sum = 0;

	for(int i = 0; i < data->size; ++i){
		sum += data->arr[i];
		Sleep(12);
	}

	data->average = (double)sum / data->size;
	cout << "Average value: " << data->average << endl;

	return 0;
}
