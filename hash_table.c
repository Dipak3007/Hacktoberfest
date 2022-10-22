/*To change hash table size change in MACRO part currently it is 10*/

#include<stdio.h>
#include<stdlib.h>

#define size 10

typedef struct mynode
{
    int data;
    struct mynode *next;
}node;

node *chain[size];

void initialize()
{
    for(int i = 0; i < size; i++)
        chain[i] = NULL;
}

void insertNode(int value)
{

    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;


    int key = value % size;


    if(chain[key] == NULL)
        chain[key] = newNode;

    else
    {

        node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void printHashTable()
{
    int i;

    for(i = 0; i < size; i++)
    {
        node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    
    initialize();
    int n,temp;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter element %d : ",i);
        scanf("%d",&temp);
        insertNode(temp);
    }
    
    printHashTable();

    return 0;
}