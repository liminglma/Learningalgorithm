// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include <list>
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void swapArray(int *arr, int a, int b)
{

	if (a < b)
	{
		if (arr[a] > arr[b])
		{
			swap(arr[a], arr[b]);
		}
	}
	else
	{
		if (arr[a] < arr[b])
		{
			swap(arr[a], arr[b]);
		}
	}
}

void merge(int *arr, int firstRank, int firstLength, int secondRank, int length)
{
	int first = 0;
	int second = 0;
	int secondLength;
	if (secondRank + firstLength  >= length)
	{
		secondLength = length - secondRank;
	}
	else
	{
		secondLength = firstLength;
	}

	int *temp = new int[firstLength + secondLength];
	while (first < firstLength  &&
		second <secondLength)
	{
		if (arr[firstRank + first] <= arr[secondRank + second])
		{
			temp[first + second] = arr[firstRank + first];
			first += 1;
		}
		else
		{
			temp[first + second] = arr[secondRank + second];
			second += 1;
		}
	}
	if (second == secondLength)
	{
		while (first != firstLength)
		{
			temp[first + second] = arr[firstRank + first];
			++first;
		}
	}
	else if (first == firstLength)
	{
		while (second != secondLength)
		{
			temp[first + second] = arr[secondRank + second];
			++second;
		}
	}
	cout << endl;
	memcpy(arr + firstRank, temp, (firstLength + secondLength) * sizeof(int));
	delete[]temp;
}
void mergeSort(int *arr, int length)
{
	 
	int step = 1;
	while (step < length )
	{
		for (int i = 0; i < length - step; i += step * 2)
		{
			merge(arr, i, step, i + step, length);
		}
		step *= 2;
	}
}

int main()
{
	int a[] = { 3, 1, 5, 2, 7, 12, 99, 13, 4, 5, 145, 11, 12};
	int length = sizeof(a) / sizeof(a[0]);
	mergeSort(a, length);


	for (auto num : a)
	{
		cout << num << "-";
	}

	while (true)
	{

	}
}
