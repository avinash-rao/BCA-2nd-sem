#include<stdio.h>
#include<conio.h>

int min(int[],int k,int n);

void main()
{
    int a[15],i,n,k,loc,temp;
    
    printf("Enter how many elements: ");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(k=0;k<n;k++)
    {
        loc=min(a,k,n);
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
    printf("Elements after selection sort is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    getch();
}

int min(int a[],int k,int n)
{
    int loc,j,min;
    min=a[k];
    loc=k;
    for(j=k+1;j<n;j++)
    {
        if(a[j]<min)
        {
            min=a[j];
            loc=j;
        }
    }
    return loc;
}