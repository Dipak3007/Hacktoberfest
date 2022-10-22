#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct knap
{
float x[10]; //solution vectors
float profit; //total profit
};

void merge(float *A1,float *A2,float *A3,int *A4,int *p,int *q,int *r){
    int n1=*q-*p+1;
    int i,j,k;
    int n2=*r-*q;
    float left1[n1+2],left2[n1+2],left3[n1+2],left4[n1+2];
    float right1[n2+2],right2[n2+2],right3[n2+2],right4[n2+2];
    for(int i=1;i<=n1;i++){
        left1[i]=A1[*p + i - 1];
        left2[i]=A2[*p + i - 1];
        left3[i]=A3[*p + i - 1];
        left4[i]=A4[*p + i - 1];
    }
    for(int j=1;j<=n2;j++){
        right1[j]=A1[*q+j];
        right2[j]=A2[*q+j];
        right3[j]=A3[*q+j];
        right4[j]=A4[*q+j];
    }
    left1[n1+1]=INT_MIN;
    right1[n2+1]=INT_MIN;
    i=1;
    j=1;
    for(k=*p;k<=*r;k++){
        if(left1[i]>=right1[j]){
            A1[k]=left1[i];
            A2[k]=left2[i];
            A3[k]=left3[i];
            A4[k]=left4[i];
            i=i+1;
        }
        else{
            A1[k]=right1[j];
            A2[k]=right2[j];
            A3[k]=right3[j];
            A4[k]=right4[j];
            j=j+1;
        }
    }
}

void mergesort(float *A1,float *A2,float *A3,int *A4,int *p,int *r){
    if(*p < *r){
        int q=((*p+*r)/2);
        int s=q+1;
        mergesort(A1,A2,A3,A4,p,&q);
        mergesort(A1,A2,A3,A4,&s,r);
        merge(A1,A2,A3,A4,p,&q,r);
    }
    return;
}
struct knap *k;
struct knap *knapsack(int n,float *w,float *c,float *W){
    
    k=(struct knap *)malloc(sizeof(struct knap));
    int i,a[n],l,r;
    float x[n],v[n+1];
    for (i = 1; i <= n; i++)
    {
        k->x[i] = 0;
        v[i] = c[i] / w[i];
    }
    printf("SORTED VALUE:\n");
    for(int i=1;i<=n;i++){
        printf("v{%d}=%.2f\n",i,v[i]);         
    }
    printf("\nSORTED WEIGHT:\n");
    for(int i=1;i<=n;i++){
        printf("w{%d}=%.2f\n",i,w[i]);         
    }
    printf("\nSORTED COST:\n");
    for(int i=1;i<=n;i++){
        printf("c{%d}=%.2f\n",i,c[i]);         
    }
    for(i=1;i<=n;i++){
        a[i]=i;  
    }
    l=1;
    r=n;
    mergesort(v,w,c,a,&l,&r);
    i=1;
    while ((*W!= 0) && (i<=n))
    {
            if (*W >= w[i])
            {
                k->x[i] = 1;
                *W = *W - k->x[i] * w[i];
            }
            else
            {
                k->x[i] = *W / w[i];
                *W = *W - k->x[i] * w[i];
            }
            i=i+1;
    }
    return k;
}

int main()
{
struct knap *ptr;
float w[20], c[20], W; //w[i], and c[i] are weights, and cost, W is the knapsack capacity
int n; //n is the number of objects
printf("Enter the Number of Objects:");
scanf("%d", &n);
for (int i = 1; i<=n; i++)
{
printf("Enter the Weight of the object O[%d]", i);
printf("w[%d]=",i);
scanf("%f", &w[i]);
}
for (int i = 1; i<=n; i++)
{
printf("Enter the Cost of the object O[%d]", i);
printf("c[%d]=",i);
scanf("%f", &c[i]);
}
printf("Enter the capacity of knapsack: ");
scanf("%f", &W);
ptr=knapsack(n, w, c, &W);
printf("\nThe solution vector is:\n");
    for(int j=1;j<=n;j++){
    printf("x{%d}=%.2f\n", j, ptr->x[j]);
    }
    ptr->profit=0;
    printf("\nMaximum profit:\n");
    for(int j=1;j<=n;j++){
    ptr->profit=(c[j])*(ptr->x[j])+ptr->profit;
    }
    printf("%.2f",ptr->profit);
return 0;
}