#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
char stack[max];
int top = -1;

void push(char);
char pop(char stack[], char item);
int precedence(char symbol);
void inftopfx(char Q[], char P[]);

int main()
{
    char Q[max], P[max]; // declare the infix string and postfix string
    int choice = 1;
    while (choice == 1)
    {
        printf("\n*Infix to postfix Expression*\n\n");
        printf("\nEnter Infix expression : ");
        scanf("%s", &Q);
        inftopfx(Q, P); // call to convert infix to postfix
        printf("Do you want to convert more  press(1)\n");
        scanf("%d", &choice);
    }
    return 0;
}

void push(char item)
{
    if (top >= max - 1)
    {
        printf("overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop(char stack[], char item)
{
    if (top < 0)
    {
        printf("underflow\n");
        exit(0);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-') // lowest precedence
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void inftopfx(char Q[], char P[])
{
    int i = 0, j = 0,last;
    char data, n;
    push('(');      // push this '(' onto stack
    last =strlen(Q);
    Q[last] = ')'; // add ')' to end of infix expression
    data = Q[i];
    Q[last+1] = '\0';
    printf("New Expression of Q is %s\n\n", Q);
    while (data != '\0')
    {
        if ((data >= '0' & data <= '9') || (data >= 'a' & data <= 'z') || (data >= 'A' & data <= 'Z'))
        {
            P[j] = data; /* add the operand symbol to postfix expression */
            j++;
        }
        else if (data == '(')
        {
            push(data); // if '(' then add it to stack
        }
        else if (operator(data) == 1) /* means symbol is operator */
        {
            n = pop(stack, data);
            while (operator(n) == 1 && precedence(n) >= precedence(data))
            {
                P[j] = n;
                j++;
                n = pop(stack, data); /* add them to postfix expresion */
            }
            push(n);
            push(data); /* pushes the current oprerator symbol onto stack */
        }
        else if (data == ')')
        {
            n = pop(stack, data);
            while (n != '(') /* '(' encounterd  then stop*/
            {
                P[j] = n;
                j++;
                n = pop(stack, data);
            }
        }
        else
        {
            printf("\nInfix Expression is invalid\n");
            exit(1);
        }
        i++;
        data = Q[i];
    }
    printf("Postfix Expression is \n ");
    printf("%s\n", P); /* print postfix expression */
}
