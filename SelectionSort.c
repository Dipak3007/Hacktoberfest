#include<stdio.h>

void Selection(int A[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(A[j]<A[min])
                min=j;
        if(min!=i){
            int temp=A[i];
            A[i]=A[min];
            A[min]=temp;
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
    Selection(A,n);
    printf("\nSorted Array :-\n");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
