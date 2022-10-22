#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct polynomial
{
    int power;
    int coefficient;
    struct polynomial * next;
};
void add_polynomial(struct polynomial * pol1,struct polynomial * pol2)
{
    struct polynomial * result, * temp1,* temp2, * q, * p,* new;
    int index;
    result=(struct polynomial *)malloc(sizeof(struct polynomial));
    temp1=(struct polynomial *)malloc(sizeof(struct polynomial));
    temp2=(struct polynomial *)malloc(sizeof(struct polynomial));
    q=(struct polynomial *)malloc(sizeof(struct polynomial));
    p=(struct polynomial *)malloc(sizeof(struct polynomial));
    for(temp1=pol2;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=pol1;temp2!=NULL;temp2=temp2->next)
        {             
            if(temp1->power==temp2->power)
            {
                temp2->coefficient += temp1->coefficient;
                break;        
            }
        }
        if(temp2==NULL)                                      //that power is absent in pol1 nut in pol2
            {
                new=(struct polynomial *)malloc(sizeof(struct polynomial));
                new->coefficient=temp1->coefficient;
                new->power=temp1->power;

                for(p=pol1;p!=NULL;q=p,p=p->next)
                    {
                        if(new->power>p->power)
                        {
                            q->next=new;
                            new->next=p;
                            break;
                        }
                        if(p->next == NULL)
                        {
                            p->next=new;
                            new->next=NULL;
                            break;
                        }

                    }      
             
            }    
    }
}

int main()
{
    int n,term_count1,term_count2,c1=0,c2=0,k=0;
    struct polynomial *pol1,*pol2,*temp1,*temp2,*tem3,*p;
    pol1=(struct polynomial *)malloc(sizeof(struct polynomial));
    pol2=(struct polynomial *)malloc(sizeof(struct polynomial));
    temp1=(struct polynomial *)malloc(sizeof(struct polynomial));
    temp2=(struct polynomial *)malloc(sizeof(struct polynomial));
    printf("How many terms are there in your first polynomial: ");
    scanf("%d",&term_count1);
    printf("\nEnter the terms highest to lowest power wise.\n\n");
    temp1=pol1;
    temp2=pol1;
    while(term_count1--)
    {
        if(c1!=0)
            temp1=(struct polynomial *)malloc(sizeof(struct polynomial));
        printf("Enter one term's power and coefficient respectively : ");
        scanf("%d %d",&temp1->power,&temp1->coefficient);
        temp1->next=NULL;
        if(c1!=0)   
            {
                temp2->next=temp1;
                temp2=temp2->next; 
            }
        c1++;          
    }
    printf("\nHow many terms are there in your second polynomial: ");
    scanf("%d",&term_count2);
    printf("\nEnter the terms highest to lowest power wise.\n\n");
    temp1=pol2;
    temp2=pol2;
    while(term_count2--)
    {
        if(c2!=0)
            temp1=(struct polynomial *)malloc(sizeof(struct polynomial));
        printf("Enter one term's power and coefficient respectively : ");
        scanf("%d %d",&temp1->power,&temp1->coefficient);
        temp1->next=NULL;
        if(c2!=0)   
            {
                temp2->next=temp1;
                temp2=temp2->next; 
            }
        c2++;          
    }
    printf("\nFirst polynomial is : ");
    temp1=pol1;
    while(temp1!=NULL)
        {
            if(temp1->power == 0)
                printf("%d\n",temp1->coefficient);
            else if(temp1->next==NULL)
                printf("%dx^%d\n",temp1->coefficient,temp1->power);
            else
                printf("%dx^%d + ",temp1->coefficient,temp1->power);    
            temp1=temp1->next;
        }
    temp2=pol2;
    printf("Second polynomial is : ");    
    while(temp2!=NULL)
        {
            if(temp2->power == 0)
                printf("%d\n",temp2->coefficient);
            else if(temp2->next==NULL)
                printf("%dx^%d\n",temp2->coefficient,temp2->power);
            else
                printf("%dx^%d + ",temp2->coefficient,temp2->power);
            temp2=temp2->next;    
        }
    printf("\nThe sum of the polynomials is : ");   
    if(pol1->power>=pol2->power)
    {
        add_polynomial(pol1,pol2);
        while(pol1!=NULL)
        {
            if(pol1->power == 0)
                printf("%d\n",pol1->coefficient);
            else if(pol1->next==NULL)
                printf("%dx^%d\n",pol1->coefficient,pol1->power);
            else
                printf("%dx^%d + ",pol1->coefficient,pol1->power);    
            pol1=pol1->next;
        }  
    }
    else
    {
        add_polynomial(pol2,pol1); 
        while(pol2!=NULL)
        {
            if(pol2->power == 0)
                printf("%d\n",pol2->coefficient);
            else if(pol2->next==NULL)
                printf("%dx^%d\n",pol2->coefficient,pol2->power);
            else
                printf("%dx^%d + ",pol2->coefficient,pol2->power); 
            pol2=pol2->next;
        }
    }
    return 0;
}