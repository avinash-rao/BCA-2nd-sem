#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int gcd(int a,int b);
void main()
{
    int a,b;
    printf("Enter value of a and b\n");
    scanf("%d %d",&a,&b);
    printf("GCD of %d and %d is %d",a,b,gcd(a,b));
}

int gcd(int a,int b)
{
    if(a==0||b==0)
    {
        if(a==0)
            return b;
        else
            return a;
    }
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}

/*Another way to write the same function
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else if(b>a)
        return (gcd(b,a));
    else
        return (gcd(b,a%b));
}*/