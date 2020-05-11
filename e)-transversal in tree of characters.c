
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char name;
    struct node* left;
    struct node* right;
}*Node;

struct node *createNode(char x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(x==' ')
        return NULL;
    temp->name=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}


struct node* insert(char x,struct node* p)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=p;
    while(1)
        {
        if(temp)
        {
            if(temp->name > x)
            {
                if(temp->left)
                    temp=temp->left;
                else
                {
                    temp->left=createNode(x);
                    return;
                }
            }
            else
                {
                if(temp->right)
                    temp=temp->right;
                else{
                    temp->right=createNode(x);
                    return;
                    }
                }
        }
        }
}

int preorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%c\t",p->name);
    preorder(p->left);
    preorder(p->right);

}

int inorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    printf("%c\t",p->name);
    inorder(p->right);

}

int postorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right);
    printf("%c\t",p->name);
}
int main()
{
        int n;
        printf("ENTER THE NUMBER OF ELEMENTS:-");
        scanf("%d",&n);
        char a;
        printf("enter root element:-");
        scanf(" %c",&a);
        struct node* root=createNode(a);
        for(int i=1;i<n;i++)
        {
            char b;
            printf("enter element:-");
            getchar();
            scanf("%c",&b);
            insert(b,root);
        }
        printf("PREORDER TRANSVERSAL OF BST :-");
        preorder(root);
        printf("\nINORDER TRANSVERSAL OF BST :-");
        inorder(root);
        printf("\nPOSTORDER TRANSVERSAL OF BST :-");
        postorder(root);
}
