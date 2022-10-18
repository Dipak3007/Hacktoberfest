#include<stdio.h>

int Partition(int A[],int p,int r){
    int x=A[r],i=p-1,temp;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

void QuickSort(int A[],int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
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
    QuickSort(A,0,n-1);
    printf("\nSorted Array :-\n");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
