#include <stdio.h>
#include <stdlib.h>

// Here structure is created with name node
struct node
{
    struct node *prev; // It is pointer which will point the prevoius node
    int info;
    struct node *next; // It is pointer which will point the next node
};

struct node *start = NULL; // A start pointer is created which will now initialize with NULL value

struct node *createcdll(struct node *);
struct node *printcdll(struct node *);
struct node *inscdllfirst(struct node *);
struct node *inscdllend(struct node *);
struct node *inscdllafgn(struct node *);
struct node *delcdllfirst(struct node *);
struct node *delcdllend(struct node *);

int main()
{
    int choice;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        printf("1.To create link list\n");
        printf("2.To traverse link list\n");
        printf("3.To insert a node at the beginning of circular doubly link list\n");
        printf("4.To insert a node at the end of circular doubly link list\n");
        printf("5.To insert a node after the node of circular doubly link list\n");
        printf("6.To delete a node from the beginning of circular doubly linked list:\n");
        printf("7.To delete a node from the end of circular doubly linked list:\n");
        printf("8.To exit:\n");
        printf("enter your choice\n");
        scanf("%d", &choice); // Here takinginput from the user
        switch (choice)
        {
        case 1:
            createcdll(ptr);
            break;
        case 2:
            printcdll(ptr);
            break;
        case 3:
            inscdllfirst(ptr);
            break;
        case 4:
            inscdllend(ptr);
            break;
        case 5:
            inscdllafgn(ptr);
            break;
        case 6:
            delcdllfirst(ptr);
            break;
        case 7:
            delcdllend(ptr);
            break;
        case 8:
            exit(0); // The program will stop executing
            break;
        default:
            printf("Invalid Input:\n");
            break;
        }
    }
}
/*create function started which will create new node */
struct node *createcdll(struct node *a)
{
    int n;
    printf("enter no of nodes:\n");
    scanf("%d", &n);
    if (n != 0)
    {
        int data, i;
        struct node *newnode, *temp;                          // Two new pointers is initialized
        newnode = (struct node *)malloc(sizeof(struct node)); // newnode is created
        printf("Enter data:\n");
        scanf("%d", &data); // taking input from the user
        newnode->info = data;
        start = newnode;
        temp = start;
        newnode->next = temp;
        newnode->prev = start;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node)); // newnode is created
            int data;
            printf("Enter data:\n");
            scanf("%d", &data);
            newnode->info = data;
            newnode->prev = temp;
            newnode->next = start;
            temp->next = newnode;
            temp = temp->next;
        }
        printf("List is created successfully\n\n");
    }
    else
        printf("list is already created:\n");
}
/*print function which will print the info of node*/
struct node *printcdll(struct node *a)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("underflown:\n");
    }

    temp = start;
    printf("Displaying info of linked list:\n");
    while (temp->next != start)
    {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
    printf("Data = %d\n", temp->info);
}
/*inscdllfirst function is created to insert at the beginning of linked list*/
struct node *inscdllfirst(struct node *a)
{
    int item;
    struct node *newnode, *temp;                          // Two new pointers is initialized
    newnode = (struct node *)malloc(sizeof(struct node)); // newnode is created
    if (newnode == NULL)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter item you want to insert at the beginning\n");
        scanf("%d", &item);
        newnode->info = item;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prev = start;
        }
        else
        {
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            start->prev = newnode;
            newnode->next = start;
            start = newnode;
        }
    }
    printf("Node inserted successfully\n\n");
}
// Here inscdllend function is created to insert at the end of linked list
struct node *inscdllend(struct node *a)
{
    int item;
    struct node *newnode, *temp;                          // Two new pointers is initialized
    newnode = (struct node *)malloc(sizeof(struct node)); // newnode is created
    if (newnode == NULL)
    {
        printf("overflown\n");
    }
    else
    {
        printf("enter item you want to insert at the end\n");
        scanf("%d", &item); // taking input from the user
        newnode->info = item;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prev = start;
        }
        else
        {
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            start->prev = newnode;
            newnode->next = start;
        }
    }
    printf("Node inserted successfully\n\n");
}
/*Here inscdllafgn is created to insert a new node after a given value of node*/
struct node *inscdllafgn(struct node *a)
{
    int item;
    struct node *newnode, *temp;                          // Two new pointers is initialized
    newnode = (struct node *)malloc(sizeof(struct node)); // newnode is created
    if (newnode == NULL)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter data you want to insert after the given node value\n");
        scanf("%d", &item); // Taking input from the user
        newnode->info = item;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prev = start;
        }
        else
        {
            int value;
            printf("enter value of node after which a node to be inserted:\n");
            scanf("%d", &value);
            temp = start;
            while (temp->info != value)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}
/*Here delcdllfirst function is created to delete node from the beginning of linked list*/
struct node *delcdllfirst(struct node *a)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("underflow:\n");
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = start->next;
        start->next->prev = temp;
        free(start);
        start = temp->next;
    }
    printf("Delete successfully from the begininng of linked list:\n\n");
}
/*Here delcdllend function is created to delete a node from the end of linked list*/
struct node *delcdllend(struct node *a)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("overflow:\n");
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->prev->next = start;
        start->prev = temp->prev;
        free(temp);
        printf("\nnode deleted\n");
    }
    printf("Delete successfully from the end of linked list:\n\n");
}
