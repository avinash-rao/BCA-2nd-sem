#include<stdio.h>
#include<conio.h>


int fibo(int);

void main()
{
    int i,n,fib0=0,fib1=1;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("%d\t%d",fib0,fib1);
    for(i=2;i<n;i++)
    {
        printf("\t%d",fibo(i));
    }
    getch();
}

int fibo(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return (fibo(n-1)+fibo(n-2));
}