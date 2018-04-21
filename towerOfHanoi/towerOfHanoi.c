#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void hanoi(int n,char s,char t,char d);

void main()
{
    int n,count;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("The tower of hanoi involves moves: \n");
    count=pow(2,n)-1;
    hanoi(n,'S','T','D');
    printf("\nNo. of steps involved = %d",count);
    getch();
}

void hanoi(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("Move 1 disk from peg %c to peg %c\n",s,d);
        return;
    }
    hanoi(n-1,s,d,t);
    printf("Move disk %d from peg %c to peg %c\n",n,s,d);
    hanoi(n-1,t,s,d);
}