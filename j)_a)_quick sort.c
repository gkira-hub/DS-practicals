#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int division_of_array(int a[],int start ,int end)
{
    int temp,i,j,p;
    p=a[end];
    i=start-1;
    for (j = start; j <= end- 1; j++)
    {
        if (a[j] < p)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[end];
    a[end]=temp;
    return (i + 1);
}

void quick_sort(int a[],int start,int end)
{
    int pivot;
    if(start>=end)
    {
        return;
    }
    pivot=division_of_array(a,start,end);
    quick_sort(a,start,pivot-1);
    quick_sort(a,pivot+1,end);

}

int main()
{
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[MAX];
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

    quick_sort(a,0,n-1);

    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
