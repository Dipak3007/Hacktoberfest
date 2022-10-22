#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define queueSize 100

struct queue
{
    char data[queueSize];
    int front,rear;
};

void enQueue(struct queue * ptr,char newData);
char deQueAtFront(struct queue * ptr);
char deQueAtRear(struct queue * ptr);
int isEmpty(struct queue * ptr);
int isFull(struct queue * ptr);

int main()
{
    char string[queueSize];
    int i;
    struct queue *myQue;
    myQue=(struct queue *)malloc(sizeof(struct queue));
    myQue->front=0;
    myQue->rear=-1;
    printf("Enter your string : ");
    scanf("%[^\n]s",string);
    for(i=0;i<strlen(string);i++)
    {
        enQueue(myQue,string[i]);
    }
    for(i=0;i<strlen(string)/2;i++)
    {
        if(deQueAtFront(myQue)!=deQueAtRear(myQue))
            break;
    }
    if(i==strlen(string)/2)
        printf("The entered string is pallindrome\n");
    else 
        printf("The entered string is not pallindrome\n");
    return 0;
}

void enQueue(struct queue * ptr,char newData)
{
    if(!isFull(ptr))
        ptr->data[(++(ptr->rear))%queueSize]=newData;
    else 
        {
            exit(0);    
        }
    return;
}

char deQueAtFront(struct queue * ptr)
{
    char ch;
    ch=ptr->data[ptr->front];
    if(++(ptr->front)>ptr->rear)
        {
            ptr->front=0;
            ptr->rear=-1;
        }    
    return ch;
}

char deQueAtRear(struct queue * ptr)
{
    char ch;
    ch=ptr->data[ptr->rear];
    if(--(ptr->rear)<ptr->front)
        {
            ptr->front=0;
            ptr->rear=-1;
        }    
    return ch;
}

int isFull(struct queue * ptr)
{
    if(((ptr->rear+1)%queueSize)==ptr->front && ptr->rear!=-1)
        return 1;
    else 
        return 0;    
}