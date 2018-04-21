#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
struct student
{
    int rollno;
    char name[20];
    struct student *link;
};

typedef struct student node;
node *start=NULL;

void create();
void insert();
void delete();
void display();
void main()
{
    int choice;
    
    while(1)
    {
        printf("\n1.Create\n");
        printf("2.Insert at beginning\n");
        printf("3.Delete a roll no\n");
        printf("4.Display\n");
        printf("5.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default: printf("Error in choice\n");
        }
    }
}

void create()
{
    node *curptr,*newnode;
    int i=0;
    char ch;
    curptr=(node*)malloc(sizeof(node));
    start=curptr;
    while(1)
    {
        printf("\nEnter the node %d details\n",i+1);
        printf("Enter Roll no.: ");
        scanf("%d",&curptr->rollno);
        printf("Enter name: ");
        scanf("%s",curptr->name);
        printf("Do you wish to continue(y/n)");
        ch=getche();
        if(tolower(ch)=='y')
        {
            newnode=(node*)malloc(sizeof(node));
            curptr->link=newnode;
            curptr=newnode;
        }
        else
        {
            curptr->link=NULL;
            break;
        }
        i++;
    }
}

void insert()
{
    node *newnode;
    printf("Enter the roll no.: ");
    scanf("%d",&newnode->rollno);
    printf("Enter the name: ");
    scanf("%s",newnode->name);
    newnode->link=start;
    start=newnode;
    printf("the new node inserted");
}

void delete()
{
    int item;
    node *curptr=start,*prevptr=NULL;
    
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    
    printf("Enter the roll no to delete: ");
    scanf("%d",&item);
    
    if(start->rollno==item)
    {
        start=start->link;
        free(curptr);
        printf("the node with %d roll no. deleted",item);
        return;
    }
    else
    {
        while((curptr->rollno!=item)&&(curptr!=NULL))
        {
            prevptr=curptr;
            curptr=curptr->link;
        }
        if(curptr==NULL)
        {
            printf("The roll no. does not exist");
        }
        else
        {
            prevptr->link=curptr->link;
        }
    }
}

void display()
{
    node *curptr=start;
    if(start==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        while(curptr!=NULL)
        {
            printf("%d->",curptr->rollno);
            printf("%s->",curptr->name);
            curptr=curptr->link;
        }
        printf("NULL");
    }
}