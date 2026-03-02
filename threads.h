#ifndef THREADS_H
#define THREADS_H

#include <windows.h>

struct ThreadData {
	int* arr;
	int size;
	int min;
	int max;
	double average;
};

DWORD WINAPI min_max(LPVOID lpParam);
DWORD WINAPI average(LPVOID lpParam);

#endif
