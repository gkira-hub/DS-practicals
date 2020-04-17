// ------------Deletion in singly linked list------------------// 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*start;

void dataentry(int x)
{
 start=(struct node*)malloc(sizeof(struct node));
struct node* temp=(struct node*)malloc(sizeof(struct node));
int a;
scanf("%d",&a);
start->data=a;
start->link=NULL;
temp=start;
for(int i=0;i<x-1;i++)
{
struct node* p=(struct node*)malloc(sizeof(struct node));
int y;
scanf("%d",&y);
p->data=y;
p->link=NULL;
temp->link=p;
temp=temp->link;
}
}
void search()
{
    int c,j=0;
    printf("enter the element u want to search");
    scanf("%d",&c);
    struct node* b=(struct node*)malloc(sizeof(struct node));
    b=start;
    while(b!=NULL)
    {
        j++;
        if(b->data==c)
        {
            break;
        }
        b=b->link;
    }
    if(b==NULL)
    {
        printf("NOT FOUND");
    }
    else{
    printf("element:%d\n position:%d\n",b->data,j);
}}

void insertatbegning()
{
    printf("b\n");
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int q=3;
    temp->data=q;
    temp->link=start;
    start=temp;
}

void insertatlast()
{
    printf("l\n");
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int q=8;
    temp->data=q;
    temp->link=NULL;
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=temp;
}

void insertion(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    int pos;
    printf("where do u want to insert");
    scanf("%d",&pos);
    p=start;
    temp->data=6;
    temp->link=NULL;
    if(pos==1)
    {
        insertatbegning();
    }
    else if(pos<x+2 ){
    for(int i=1; i<pos-1 && p!=NULL ;i++)
    {
        p=p->link;
    }
    temp->link=p->link;
    p->link=temp;}
    else{
        printf("not capable");
    }
}

void deletefirstnode()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=start;
    start=temp->link;
    free(temp);
}

void deletelasttnode()
{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        struct node* p=(struct node*)malloc(sizeof(struct node));
        temp->link=NULL;
        p=start;
        while(p->link->link)
        {
            p=p->link;
        }
        temp=p->link;
        p->link=temp->link;
        free(temp);
}

void deletion()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    p=start;
    int z;
    printf("what do u want to delete");
    scanf("%d",&z);
    if(z==start->data)
    {
        deletefirstnode();
    }
    else{
    while(p)
    {
        if(p->link->data==z)
        {
            break;
        }
        p=p->link;
    }
    temp=p->link;
    p->link=p->link->link;
    free(temp);
    }
}

void reverse()
{
    struct node* prev=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* next=(struct nide*)malloc(sizeof(struct node));
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
}

void display()
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp=start;
while(temp)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
int main()
{
int x;
scanf("%d",&x);
dataentry(x);
//transeverse();
//insertion(x);
//insertatbegning();
//insertatlast();
//search();
//deletefirstnode();
//deletelasttnode();
deletion();
//reverse();
display();
}
