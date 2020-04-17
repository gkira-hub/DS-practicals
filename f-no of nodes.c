#include<stdio.h>
#include<stdlib.h>

int x=0,space=0,leaf=0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf ("\n Enter the data for node(Enter -1 for no Data Entry)\n");
    scanf ("%d",&x);
    if(x==-1)
    {
        printf("\n You have not entered any data");
        return NULL;
    }

    new->data=x;
    printf ("\n Enter the data for left node of %d",new->data);
    new->left=create();
    printf ("\n Enter the data for the right node of %d",new->data);
    new->right=create();
    return new;
}

int nn(struct node *temp)
{
    int x,y;
    if(temp->left)
    {
        x=nn(temp->left);
    }
    if(temp->right)
    {
        y=nn(temp->right);
    }
    if(temp->left == NULL & temp->right == NULL)
    {
        leaf++;
        return 1;
    }
    else
    {
        return 1+x+y;
    }
}

int main()
{
    struct node *root;
    root=create();
    printf ("\n Root node = %d",root->data);
    traverse(root);
    printf ("\n");
    int n=nn(root);
    printf("\n No.of Nodes=%d",n);
 }