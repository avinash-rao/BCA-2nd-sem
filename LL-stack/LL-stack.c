#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node NODE;
NODE *top=NULL;
void delete_beg();
void insert_beg();
void display();

void main()
{
    int choice;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:insert_beg(); break;
            case 2:delete_beg(); break;
            case 3:display(); break;
            case 4:exit(0); break;
            default: printf("Error in choice\n\n");
        }
    }
}

void insert_beg()
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("Enter the item to push: ");
    scanf("%d",&newnode->info);
    newnode->link=top;
    top=newnode;
    printf("Item inserted\n\n");
}

void delete_beg()
{
    NODE *curptr;
    if(top==NULL)
        printf("Stack Underflow\n\n");
    else
    {
        curptr=top;
        top=top->link;
        free(curptr);
        printf("top element popped\n\n");
    }
}

void display()
{
    NODE *curptr;
    if(top==NULL)
        printf("Stack Underflow\n\n");
    else
    {
        curptr=top;
        while(curptr!=NULL)
        {
            printf("%d->",curptr->info);
            curptr=curptr->link;
        }
        printf("NULL\n\n");
    }   
}