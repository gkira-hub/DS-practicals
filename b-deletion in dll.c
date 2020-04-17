// --------------dobly linked list----------------
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    struct node* plink;
    int data;
    struct node* nlink;
}*start;

//let's create a list

void createalist(int x)
{
    start=(struct node*)malloc(sizeof(struct node));
    int a;
    scanf("%d",&a);
    start->data=a;
    start->plink=NULL;
     struct node* temp=(struct node*)malloc(sizeof(struct node));
     temp=start;
    for(int i=1;i<x;i++)
    {
        struct node* p=(struct node*)malloc(sizeof(struct node));
        int a;
        scanf("%d",&a);
        p->data=a;
        p->nlink=NULL;
        temp->nlink=p;
        p->plink=temp;
        temp=temp->nlink;
    }
}

//insertion

void insertatbegning(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("enter the element u want to insert");
    scanf("%d",&d);
    temp->data=d;
    temp->plink=NULL;
    temp->nlink=start;
    temp->nlink->plink=temp;
    start=temp;

}

void insertatlast(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p=start;
    int d;
    printf("enter the element u want to insert");
    scanf("%d",&d);
    temp->data=d;
    temp->nlink=NULL;
    while(p->nlink!=NULL)
    {
        p=p->nlink;
    }
    p->nlink=temp;
    temp->plink=p;

}

void insertion(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    int d,pos;
    printf("enter the place where u want to insert");
    scanf("%d",&pos);
    p=start;
    if(pos==1)
    {
        insertatbegning(x);
    }
    else if(pos<x+2 && pos!=0)
    {
        printf("enter the element u want to insert");
        scanf("%d",&d);
        temp->data=d;
        temp->plink=NULL;
        temp->nlink=NULL;
        for(int i=1;i<pos-1;i++)
        {
            p=p->nlink;
        }
        temp->nlink=p->nlink;
        temp->plink=p;
        p->nlink->plink=temp;
        p->nlink=temp;
    }
    else if(pos==x+1)
    {
        insertatlast(x);
    }
    else if(pos>x+1 || pos==0)
    {
        printf("wrong input");
    }
}

//deletion

void deletefirstnode(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->plink=NULL;
    temp->nlink=NULL;
    temp=start;
    start=start->nlink;
    start->plink=NULL;
    free(temp);

}
void deletelastnode(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p=start;
    while(p->nlink->nlink)
    {
        p=p->nlink;
    }
    temp=p->nlink;
    p->nlink=NULL;
    free(temp);

}

void deletion(int x)
{
    int d;
    printf("which node do u want 2 delete");
    scanf("%d",&d);
    if(d==1)
    {
        deletefirstnode(x);
    }
    else if(d<x && d!=0)
    {
        struct node* p=(struct node*)malloc(sizeof(struct node));
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->plink=NULL;
        temp->nlink=NULL;
        p=start;
        for(int i=1;i<d-1;i++)
        {
            p=p->nlink;
        }
        temp=p->nlink;
        p->nlink=temp->nlink;
        temp->nlink->plink=p;
        free(temp);

    }
    else if(d==x)
    {
       deletelastnode(x);
    }
    else
    {
        printf("wrong input");
    }
}

//Reverse the list

void reverse()
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* end=(struct node*)malloc(sizeof(struct node));
      p=start;
        while(p->nlink)
        {
            p=p->nlink;
        }
        while(p)
        {
            printf("%d\n",p->data);
            p=p->plink;
        }
}

//display the list

void display()
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp=start;
while(temp)
{
printf("%d\n",temp->data);
temp=temp->nlink;
}
}

int main()
{

        int x,y;
        scanf("%d",&x);
        createalist(x);
        insertatbegning(x);
        ++x;
        insertatlast(x);
        ++x;
        insertion(x);
        ++x;
        display();
        //deletefirstnode(x);
        //--x;
        //deletelastnode(x);
        //--x;
        deletion(x);
        --x;
        printf("do u want to reverse the list/npress 1 for yes/npress 2 for no");
        scanf("%d",&y);
        switch(y)
        {
            case 1:reverse();
                   break;
            case 2:display();
                   break;
            default:printf("wrong input");
        }
}
