#include <stdio.h>
#include <conio.h>
int BSearch(int[],int,int,int);

void main()
{
    int a[15],pos=-1,key,i,n;
    printf("Enter how many items: ");
    scanf("%d",&n);
    
    printf("Enter the list of items\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Enter the key to find: ");
    scanf("%d",&key);
    
    pos=BSearch(a,key,0,n-1);
    
    if(pos==-1)
        printf("Element not found");
    else
        printf("Element found at position %d",pos);
}

int BSearch(int a[],int key,int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
            return (mid+1);
        else if(key<a[mid])
            return (BSearch(a,key,low,mid-1));
        else if(key>a[mid])
            return (BSearch(a,key,mid+1,high));
    }
    return -1;
}