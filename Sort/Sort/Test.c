#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	InsertSort(a, sz);
	PrintArray(a, sz);
}

void TestShellSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	ShellSort(a, sz);
	PrintArray(a, sz);
}

void TestSelectSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	SelectSort(a, sz);
	PrintArray(a, sz);
}

void TestHeapSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	HeapSort(a, sz);
	PrintArray(a, sz);
}

void TestBubbleSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	BubbleSort(a, sz);
	PrintArray(a, sz);
}

void TestQuickSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	QuickSort(a, 0, sz - 1);
	//QuickSortNonR(a, 0, sz - 1);
	PrintArray(a, sz);
}

void TestMergeSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	MergeSort(a, sz);
	//MergeSortNonR(a, sz);
	PrintArray(a, sz);
}

void TestCountSort()
{
	int a[] = { 5,9,8,4,6,3,1,5,6,4,8 };
	int sz = sizeof(a) / sizeof(a[0]);

	PrintArray(a, sz);
	CountSort(a, sz);
	PrintArray(a, sz);
}

void TestOP()
{
	srand((unsigned int)time(NULL));
	const int N = 100000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();

	int begin8 = clock();
	CountSort(a8, N);
	int end8 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);
	printf("MergeSort:%d\n", end7 - begin7);
	printf("CountSort:%d\n", end8 - begin8);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
}

int main()
{
	srand((unsigned int)time(NULL));
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	//TestCountSort();
	TestOP();
	return 0;
}