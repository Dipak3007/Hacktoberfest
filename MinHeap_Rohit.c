#include<stdio.h>
#include<math.h>

int heapsize,length;

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void MinHeapify(int A[],int i){
    int l=Left(i);
    int r=Right(i);
    int smallest;
    if(l<=heapsize && A[l]<A[i])
        smallest=l;
    else
        smallest=i;
    if(r<=heapsize && A[r]<A[smallest])
        smallest=r;
    if(smallest!=i){
        int temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        MinHeapify(A,smallest);
    }
}

void BuildMinHeap(int A[]){
    heapsize=length;
    for(int i=floor(length/2);i>0;i--)
        MinHeapify(A,i);
}

int main()
{
    printf("Enter size of array : ");
    scanf("%d",&length);
    int A[length+1];
    printf("Enter Array :-\n");
    for(int i=1;i<=length;i++)
        scanf("%d",&A[i]);
    BuildMinHeap(A);
    printf("\nMinHeap :-\n");
    for(int i=1;i<=length;i++)
        printf("%d ",A[i]);
    return 0;
}
