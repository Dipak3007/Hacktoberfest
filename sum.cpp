#include<stdio.h>
#include<conio.h>

int main()
{
	clrscr();
	int i;
	int arr[10];
	int sum=0;

	printf("Enter The Number");
	for(i=0; i<10; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0; i<10; i++)
	{
		sum=sum+arr[i];
	}

	printf("Sum Of All Numbers Is %d",sum);
	getch();
	return 0;
}

