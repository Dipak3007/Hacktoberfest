#include <stdio.h> //Header file for input and output
#include <stdlib.h>
#include <string.h>
// Here structure is created with a name node
struct node
{
    int info;           // It will represent the info part of node which is of integer type
    struct node *left;  // It is a ponter of type struct which will point left node
    struct node *right; // It is a ponter of type struct which will point right node
};
// Here structure is created with a name stack
struct stack
{
    struct node *data;
    struct stack *next;
    int flag;
};

int arr[100];
struct node *root = NULL;
int num = 0;
int top = 0; // top of stack
static int i;
static int item;
long int stack1[20];

struct node *createbst(struct node *root, int item)
{
    struct node *newnode, *ptr;
    int value;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (root == NULL)
    {
        root = newnode;
        root->info = item;
        num++;
        newnode->left = NULL;
        newnode->right = NULL;
        return root;
    }
    ptr = root;
    do
    {
        if (item < ptr->info && ptr->left != NULL)
        {
            ptr = ptr->left;
            value = 1;
        }
        else if (item >= ptr->info && ptr->right != NULL)
        {
            ptr = ptr->right;
            value = 1;
        }
        else
        {
            value = 0;
        }
    } while (value == 1);
    if (item < ptr->info)
    {
        ptr->left = newnode;
    }
    else
    {
        ptr->right = newnode;
    }
    newnode->info = item;
    num++;
    newnode->left = NULL;
    newnode->right = NULL;
    return root;
}

struct node *inorder(struct node *root)
{
    int value;
    struct node *ptr;
    struct stack *ptr1, *top;
    ptr = root;
    top = (struct stack *)malloc(sizeof(struct stack));
    top->data = NULL;
    top->next = NULL;
    do
    {
        while (ptr != NULL)
        {
            ptr1 = (struct stack *)malloc(sizeof(struct stack));
            ptr1->next = top;
            top = ptr1;
            top->data = ptr;
            ptr = ptr->left;
        }
        ptr = top->data;
        top = top->next;
        while (ptr != NULL)
        {
            arr[i] = ptr->info;
            i++;
            if (ptr->right != NULL)
            {
                ptr = ptr->right;
                value = 1;
                break;
            }
            else
            {
                ptr = top->data;
                top = top->next;
                value = 0;
            }
        }
    } while (value == 1);
    return root;
}

struct node *postorder(struct node *root)
{
    int i = 0;
    struct node *ptr,*temp;
    long int add; // used for type casting,and negative number is also can not be assigned to struct node* pointer
    // initaially stack is empty
    top = 0;
    stack1[top] = 0;
    ptr = root;

    // postorder traversal,first the left subtree is printed then right subtree and after that root is printed
step2: // label
    while (ptr != NULL)
    { // roots of correspoding subtrees are stored in stack without negative sign
        top = top + 1;
        stack1[top] = ptr;

        // right subtrees of correspoding roots are stored in stack with negative sign
        if (ptr->right != NULL)
        {
            top = top + 1;
            add = ptr->right; // negative of stack1[top] = -1*ptr->right will show error
            //add = ptr->right->info;
            stack1[top] = -add;
        }

        ptr = ptr->left; // moving to leftmost side of each subtree/tree
    }

    // processing the top node in stack
    add = stack1[top];
    top = top - 1;

    while (add > 0) // not a root of right subree, so processing
    {
        ptr = (struct node *)add;
        // printf(" %d\n", ptr->info);
        arr[i] = ptr->info;
        i++;
        add = stack1[top];
        top = top - 1;
    }

    if (add < 0) // root of a right subree or a right node
    {
        ptr = (struct node *)(-add);
        goto step2; // moving to repeat steps after the label step 2
    }

    return root;
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.To create BST\n");
        printf("2.To In-Order Traversal of BST\n");
        printf("3.To Post-order Traversal of BST\n");
        printf("4.To In-order Traversal of Max-heap\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter - 1 to terminate\n");
            printf("Enter data item\n");
            scanf("%d", &item);
            while (item != -1) // termination criteria
            {
                root = createbst(root, item);
                printf("Enter the data item:\n");
                scanf("%d", &item);
            }
            printf("\n**Binary search tree is created**\n\n");
            break;

        case 2:
            if (root == NULL)
                printf("In - order Traversal: Binary tree is empty\n");
            else
            {
                printf("In - order Traversal\n");
                root = inorder(root);
                for (i = 0; i < num; i++)
                {
                    printf("Element in array is %d\n", arr[i]);
                }
                break;
            }
            break;
        case 3:
            if (root == NULL)
                printf("Post - order Traversal: Binary tree is empty\n");
            else
            {
                printf("\n ** Post - order Traversal ** \n\n");
                root = postorder(root);
                for (i = 0; i < num; i++)
                {
                    printf("Element in updated array is %d\n", arr[i]);
                }
                break;
            }
            break;
        case 4:
            root = inorder(root);
            for (i = 0; i < num; i++)
            {
                printf("Element in updated tree is %d\n", arr[i]);
            }
        }
    }
}