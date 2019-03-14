#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int* arr, int size)
//时间复杂度:O(N^2)
//空间复杂度:O(1)
{
	int i = 0;
	int j = size - 1;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int ret = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ret;
			}
		}
	}
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

int BinarySearch(int* arr, int size,int value)
//时间复杂度:log2^N
//空间复杂度:O(1)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else if (arr[mid] > value)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

int Fib(int num)
//时间复杂度:O(2^N)
//空间复杂度:O(N)
{
	if (num <= 2)
		return 1;
	else
		return Fib(num - 2) + Fib(num - 1);
}

int Factorial(int num)
//时间复杂度:O(N);
//空间复杂度:O(N);
{
	if (num <= 2)
		return num;
	else
		return num * Factorial(num - 1);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, size);

	//int value = 4;
	//printf("%d\n",BinarySearch(arr, size,value));

	//int num = 8;
	//printf("斐波那契数列的第%d个数为:%d\n", num, Fib(num));

	int num = 5;
	printf("%d的阶乘为:%d\n", num, Factorial(num));
	system("pause");
}