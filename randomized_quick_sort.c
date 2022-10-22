#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int randomizedpartion(int *arr, int *p, int *r)
{
	int pivotIndex = *p + rand() % (*r - *p + 1);
	int pivot;
	int i = *p - 1;
	int j;
	pivot = arr[pivotIndex];
	swap(&arr[pivotIndex], &arr[*r]);
	for (j = *p; j < *r; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[*r]);
	return i + 1;
}
void randomizedquicksort(int *arr, int *p, int *r)
{
	int j;
	if (*p < *r)
	{
		j = randomizedpartion(arr, p, r);
		int a = j - 1;
		int b = j + 1;
		randomizedquicksort(arr, p, &a);
		randomizedquicksort(arr, &b, r);
	}
}
void printelement(int *arr, int size)
{
	printf("Sorted Array: ");
	for (int i = 0; i <= size - 1; i++)
	{
		printf("%d   ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int size;
	printf("Enter the size of the array: \n");
	scanf("%d", &size);
	int *arr = (int *)malloc(size * sizeof(int));
	for (int i = 0; i <= size - 1; i++)
	{
		printf("Enter element %d \n", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("\n");
	int a = 0;
	int b = size - 1;
	randomizedquicksort(arr, &a, &b);
	printelement(arr, size);
}

