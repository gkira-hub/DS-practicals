#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void merging(int a[],int temp[],int start1,int end1,int start2,int end2)
{
    int p=start1;
    int q=start2;
    int r=start1;

    while((p<=end1) && (q<=end2))
    {
        if(a[p]>a[q])
        {
            temp[r++]=a[q++];
        }
        else
        {
            temp[r++]=a[p++];
        }
    }
    while(p<=end1)
    {
        temp[r++]=a[p++];
    }
    while(q<=end2)
    {
        temp[r++]=a[q++];
    }
}
void merge_sort(int a[],int start,int end)
{
    int temp[MAX];
    int middle;
    middle=(start+end)/2;

    if(start==end)
    {
        return;
    }
    merge_sort(a,start,middle);
    merge_sort(a,middle+1,end);

    merging(a,temp,start,middle,middle+1,end);
    for(int i=start;i<=end;i++)
    {
        a[i]=temp[i];
    }
}

int main()
{
    int n;
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

    merge_sort(a,0,n-1);

    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
