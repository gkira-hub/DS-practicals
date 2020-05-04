#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,temp,x,y;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("unsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    for( x=1;x<n;x++)
    {
        temp=a[x];
        for(y=x-1;y>=0 && a[y]>temp;y--)
        {
            a[y+1]=a[y];
        }
        a[y+1]=temp;
    }
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
