#include<stdio.h>
#include<stdlib.h>

int x=0,s=0,l=0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*Node;

//  creation of tree
int create()
{
     int x;
     Node=(struct node*)malloc(sizeof(struct node));
     struct node* p=(struct node*)malloc(sizeof(struct node));
     printf("Enter the data for the nodes(-1 for no data)");
     scanf("%d", &x);
        if(x==-1)
           {
             return NULL;
           }
      p->data=x;
      printf("Enter the left child data rooted at %d \n",p->data);
      p->left=create();
      printf("Enter the right child data rooted at %d\n",p->data);
      p->right=create();
      return p;
}


int no_of_nodes(struct node *new)
{
    int a,b;
    if(new->left)
    {
        a=no_of_nodes(new->left);
    }
    if(new->right)
    {
        b=no_of_nodes(new->right);
    }
    if(new->left == NULL & new->right == NULL)
    {
        l++;
        return 1;
    }
    else
    {
        return 1+a+b;
    }
}

int main()
{
    struct node *root;
    root=create();
    int n=no_of_nodes(root);
    printf("\n No.of Nodes=%d",n);
 }
