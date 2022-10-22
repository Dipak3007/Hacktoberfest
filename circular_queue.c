#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cirqins(void);
int cirqdel(void);
void cirqdisplay(void);

#define max 10
int queue[max];
int front = -1;
int rear = -1;
static int item;
//Main Function i.e: Driver Of The program
int main()
{
    int choice;
    printf("\n** C Program To Implement Circular Queue **\n\n");
    while (1)
    {
        printf("---- Main Menu -----\n");
        printf("1.To Insert Element in Circular Queue\n");
        printf("2.To Delete Element from the Circular Queue\n");
        printf("3.To Display Elements of Queue\n");
        printf("4.To Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cirqins();
            break;
        case 2:
            item = cirqdel();
            if (item != -1)
                printf("The element %d is deleted from the queue\n\n", item);
            printf("**Item Deleted Successfully**\n\n");
            break;
        case 3:
            cirqdisplay();
            break;
        case 4:
            exit(1);
            break;
        }
    }
    return 0;
}
// Function To Insert Elements In The Circular Queue
void cirqins()
{
    printf("Enter value of item you want to insert\n");
    scanf("%d", &item);
    if (front == rear + 1) // Here i check that circular queue is full or not
    {
        printf("overflow\n");
    }
    else if (front == -1 && rear == -1) // if circular queue is empty
    {
        front = 0; // pointing front to 0th position in array
        rear = 0;  // pointing rear to 0th position in array
    }
    else if (rear == max - 1 && front != 0) // Here if front is not at 0th place and rear at last place
    {
        rear = 0; // we assign rear to 0th place
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item; // Inserting elements in the array
    printf("**Item Inserted Successfully**\n\n");
}
// Function To Delete Element From The Circular queue
int cirqdel()
{
    if (front == -1 && rear == -1)
    {
        printf("underflown\n");
        return -1;
    }
    item = queue[front]; // Assigning value of deleted item
    if (front == rear)   // If only one elements in the array
    {
        front = -1;
        rear = -1;
    }
    else if (front == max - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
    return item;
}
// Function To Display All Elements Of The circular Queue
void cirqdisplay()
{
    int i;
    i = front;
    printf("\n** Displaying All The Elements In The Circular Queue **\n\n");
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Elements in the Queue :\n");
        while (i <= rear)
        {
            printf("%d\n", queue[i]);
            i = i + 1;
        }
    }
}