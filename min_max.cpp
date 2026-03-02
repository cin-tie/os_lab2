#include "threads.h"
#include <iostream>

using namespace std;

DWORD WINAPI min_max(LPVOID lpParam){
	ThreadData* data = (ThreadData*)lpParam;
	data->min = data->arr[0];
	data->max = data->arr[0];

	for(int i = 1; i < data->size; ++i){
		if(data->arr[i] < data->min){
			data->min = data->arr[i];
		}
		Sleep(7);
		
		if(data->arr[i] > data->max){
			data->max = data->arr[i];
		}
		Sleep(7);
	}

	cout << "Min elements: " << data->min << endl;
	cout << "Max elements: " << data->max << endl;

	return 0;
}
