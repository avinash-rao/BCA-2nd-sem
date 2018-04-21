#include<stdio.h>
#include<conio.h>

int fact(int);
void main()
{
    int n,r,ncr;
    printf("Enter value for n: ");
    scanf("%d",&n);
    printf("Enter value for r: ");
    scanf("%d",&r);
    ncr=fact(n)/(fact(r)*fact(n-r));
    printf("ncr = %d",ncr);
    getch();
}

int fact(int n)
{
    int f=1,i;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}