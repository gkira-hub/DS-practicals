
#include <stdio.h>
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

//   transversal in trees
//PREORDER
int preorder(struct node *z)
{
    if(z==NULL)
    {
        return;
    }
    printf("%d\t",z->data);
    preorder(z->left);
    preorder(z->right);
}

//INORDER
int inorder(struct node *z)
{
    if(z==NULL)
    {
        return;
    }
    inorder(z->left);
    printf("%d\t",z->data);
    inorder(z->right);
}

//POSTORDER
int postorder(struct node* z)
{
    if(z==NULL)
    {
        return;
    }
    postorder(z->left);
    postorder(z->right);
    printf("%d\t",z->data);
}

int main()
{
    struct node* root=create();
    struct node* z=root;
    printf("press 1:PREORDER \npress 2:INORDER \npress 3:POSTORDER");
    int x;
    scanf("%d",&x);
    switch(x)
    {
        case 1:preorder(z);
        break;
        case 2:inorder(z);
        break;
        case 3:postorder(z);
        break;
        default:printf("invalid input");
        break;
    }
    return 0;
}
