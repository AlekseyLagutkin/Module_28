#include <iostream>
#include <random>
#include <ctime>
#include "mers.h"

using namespace std;

int main()
{
	int n = 100;   //Размер массива
	int l = 0;   //Левая грнаница
	int r = n - 1;   //Правая граница
	int th = 0;   //Счетчик потоков
	int thm = 2;   //Максимальное число потоков
	int& nth = th;
	int& nthm = thm;
	unsigned int start;
	unsigned int stop;
	int* a = new int[n];
	srand(10);
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand()/100;
	}
	cout << "Input array:" << endl;
	outa(a, n);
	cout << endl;
	start = clock();
	mersort(a, l, r, nth, nthm);
	stop = clock();
	unsigned int t = stop - start;
	cout << "Output array:" << endl;
	outa(a, n);
	cout << endl;
	cout << "Run time = " << t << endl;
	cout << "Threads = " << nth << endl;
	delete[] a;
	return 0;
}