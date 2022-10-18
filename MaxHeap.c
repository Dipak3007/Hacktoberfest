#include<stdio.h>
#include<math.h>

int heapsize,length;

int Parent(int i){
    return floor(i/2);
}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void MaxHeapify(int A[],int i){
    int l=Left(i);
    int r=Right(i);
    int largest;
    if(l<=heapsize && A[l]>A[i])
        largest=l;
    else
        largest=i;
    if(r<=heapsize && A[r]>A[largest])
        largest=r;
    if(largest!=i){
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MaxHeapify(A,largest);
    }
}

void BuildMaxHeap(int A[]){
    heapsize=length;
    for(int i=floor(length/2);i>0;i--)
        MaxHeapify(A,i);
}

int main()
{
    printf("Enter size of array : ");
    scanf("%d",&length);
    int A[length+1];
    printf("Enter Array :-\n");
    for(int i=1;i<=length;i++)
        scanf("%d",&A[i]);
    BuildMaxHeap(A);
    printf("\nMaxHeap :-\n");
    for(int i=1;i<=length;i++)
        printf("%d ",A[i]);
    return 0;
}
