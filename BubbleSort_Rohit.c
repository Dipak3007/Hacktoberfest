#include<stdio.h>

void Bubble(int A[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++)
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int A[n];
    printf("Enter Array :-\n");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    Bubble(A,n);
    printf("\nSorted Array :-\n");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
