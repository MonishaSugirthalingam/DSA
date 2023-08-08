#include <stdlib.h>
#include <stdio.h>

struct BinaryTree
{
    int val;
    struct BinaryTree *left,*right;
};
void preorder(struct BinaryTree *r)
{
    if(r!=0)
    {
        printf("%d ",r->val);
        preorder(r->left);
        preorder(r->right);
    }
    
}
void inorder(struct BinaryTree *r)
{
    if(r!=0)
    {
        inorder(r->left);
        printf("%d ",r->val);
        inorder(r->right);
    }
}
void postorder(struct BinaryTree *r)
{
    if(r!=0)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->val);
    }
}
struct BinaryTree *create()
{
    int data;
    struct BinaryTree *nnode;
    nnode=(struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    printf("Enter the node : ");
    scanf("%d",&data);
    if(data==-1)
    {
        return 0;
    }
    else
    {
        nnode->val=data;
        printf("Enter the left child of %d \n",data);
        nnode->left=create();
        printf("Enter the right child of %d \n",data);
        nnode->right=create();
        return nnode;
    }
}
struct BinaryTree *root;
int main()
{
    printf("To creating the binary tree\n");
    root=0;
    root=create();
    printf("If you want to perform Preoder then PRESS-1\nIf you want to perform Inorder then PRESS-2\nIf you want to perform Postorder then PRESS-3\nIf you want to Exit then PRESS-4\n");
    printf("Enter your choice : ");
    int choice;
    scanf("%d",&choice);
    while(choice!=4)
    {
       if(choice==1)
       {
           printf("Preorder traversal of given tree is : ");
           preorder(root);
           printf("\n");
       }
       
       else if(choice==2)
       {
           printf("Inordere treaversal of given tree is : ");
           inorder(root);
           printf("\n");
       }
       
       else if(choice==3)
       {
           printf("Postorder traversal of given tree is :");
           postorder(root);
           printf("\n");
       }
       else
       {
           printf("Invalid choice\n");
       }
       printf("Enter your choice : ");
       scanf("%d",&choice);
    }
    return 0;
}
