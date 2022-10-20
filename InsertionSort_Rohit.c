#include<stdio.h>

void Insertion(int A[],int n) {
    int i,j,key;
    for(i=1;i<n;i++) {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
            A[j+1]=A[j--];
        A[j+1]=key;
    }
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int A[n];
    printf("Enter Array :-\n");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    Insertion(A,n);
    printf("\nSorted Array :-\n");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
