#include <iostream>
#include <future>
#include "mers.h"

using namespace std;

void mersort(int* a, int l, int r, int &nth, int &nthm)
{
	if (l >= r)
	{
		return;
	}
	int m = (l + r) / 2;
	mersort(a, l, m, nth, nthm);
	mersort(a, m + 1, r, nth, nthm);
	if (nth < nthm)
	{
		nth++;
		future <void> f = async(launch::async, [&]() {mers(a, l, m, r); });
	}
	else
	{
		mers(a, l, m, r);
	}
}

void mers(int* a, int l, int m, int r)
{
	int nl = m - l + 1;
	int nr = r - m;
	int* al = new int[nl];
	int* ar = new int[nr];
	int i;
	int j;
	int k;
	for (i = 0; i < nl; ++i)
	{
		al[i] = a[l + i];
	}
	for (j = 0; j < nr; ++j)
	{
		ar[j] = a[m + j + 1];
	}
	i = 0; j = 0; k = l;
	while (i < nl && j < nr)
	{
		if (al[i] <= ar[j])
		{
			a[k] = al[i];
			++i;
		}
		else
		{
			a[k] = ar[j];
			++j;
		}
		++k;
	}
	while (i < nl)
	{
		a[k] = al[i];
		++i;
		++k;
	}
	while (j < nr)
	{
		a[k] = ar[j];
		++j;
		++k;
	}
	delete[] al;
	delete[] ar;
}

void outa(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[i] << std::endl;
	}
}