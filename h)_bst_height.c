
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *getnode(int x);
struct node *inseartNode(struct node *root,int x);
int height(struct node *p);
void inorder(struct node *root);

struct node *stack[MAX];
int top=-1;
void push(struct node *p);
struct node *pop();
int isEmpty();
int isFull();

int main()
{
    struct node *root=NULL,*p;
    int data,number_of_nodes;
    printf("Enter the number of nodes to be inserted:");
    scanf("%d",&number_of_nodes);
    for(int i=1;i<=number_of_nodes;i++)
    {
        printf("\nEnter the number:");
        scanf("%d",&data);
        root=inseartNode(root,data);
    }

    printf("\nHeight of tree is :%d",height(root));

    printf("\nInorder traversal:");
    inorder(root);
}
struct node *getnode(int x)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
struct node *inseartNode(struct node *root,int x)
{
   struct node *p,*temp,*par;
   p=root;
   par=NULL;
   while(p!=NULL)
   {
       par=p;
       if(x<p->data)
        p=p->left;
       else if(x>p->data)
        p=p->right;
       else
       {
           printf("\nElement %d is already present");
           return root;
       }
   }
   temp=getnode(x);
   if(par==NULL)
    root=temp;
   else if(par->data>x)
    par->left=temp;
   else
    par->right=temp;
   return root;
}
int height(struct node *p)
{
    int hl,hr;
    if(p==NULL)
        return 0;
    hl=height(p->left);
    hr=height(p->right);
    if(hl>hr)
        return 1+hl;
    else
        return 1+hr;
}
void inorder(struct node *root)
{
    struct node *p=root;
    while(!isEmpty() || p!=NULL)
    {
        while(p!=NULL)
        {
            push(p);
            p=p->left;
        }
        p=pop();
        printf("%d ",p->data);
        p=p->right;
    }
}
void push(struct node *p)
{
    if(isFull())
    {
        printf("Stack is full");
        return;
    }
    top=top+1;
    stack[top]=p;
}
struct node *pop()
{
    struct node *p;
    if(isEmpty())
    {
        printf("Stack is empty");
        exit(0);
    }
    p=stack[top];
    top=top-1;
    return p;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
