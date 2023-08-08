#include <stdlib.h>
#include <stdio.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *p,*q,*root,*temp;
int n;
int find_min(struct BST*root)
{
    if(root==0)
    {
        printf("It dont have a child\n");
        return -1;
    }
    else
    {
        struct BST *current=root;
        while(current->left!=0)
        {
            current=current->left;
        }
        return current->data;
    }
}
void insertion()
{
  int val;
  printf("Enter the insertion value : ");
  scanf("%d",&val);
    p=(struct BST*)malloc(sizeof(struct BST));
    p->data=val;
    p->left=0;
    p->right=0;
    
    q=root;
    
    while(1)
    {
        if(p->data<=q->data)
        {
            if(q->left==0)
            {
                q->left=p;
                break;
            }
            else
            {
                q=q->left;
            }
        }
        else
        {
           if(q->right==0)
           {
               q->right=p;
               break;
           }
           else
           {
               q=q->right;
           }
        }
    }
}
struct BST* deletion(struct BST*root,int num)
{
    if(root==0)
    {
        printf("Element not found\n");
    }
    else if(num<root->data)
    {
        root->left=deletion(root->left,num);
    }
    else if(num>root->data)
    {
        root->right=deletion(root->right,num);
    }
    else
    {
        if(root->left==0 && root->right==0)
        {
            printf("In deletion : Leaf node deletion\n");
            root=0;
            free(root);
        }
        else if(root->left==0)
        {
            printf("In deletion : Node with one child(Right child)\n");
            temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==0)
        {
            printf("In deletion : Node with one child(Left child)\n");
            temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            printf("In deletion : Node with Two Children\n");
            int val;
            val=find_min(root->right);
            root->data=val;
            root->right=deletion(root->right,val);
        }
    }
    return root;
}
void preorder(struct BST *root)
{
   if(root!=0)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
 
}
void inorder(struct BST *root)
{
    if(root!=0)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}
void postorder(struct BST *root)
{
    if(root!=0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

}
void creating()
{
  int arr[100];
  printf("Enter the size of array : ");
  scanf("%d",&n);
  printf("Enter the array elements one by one\n");
  for(int i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  
  p=(struct BST*)malloc(sizeof(struct BST));
  p->data=arr[0];
  p->left=0;
  p->right=0;
  root=p;
  
  for(int i=1;i<n;i++)
  {
    p=(struct BST*)malloc(sizeof(struct BST));
    p->data=arr[i];
    p->left=0;
    p->right=0;
    
    q=root;
    
    while(1)
    {
        if(p->data<=q->data)
        {
            if(q->left==0)
            {
                q->left=p;
                break;
            }
            else
            {
                q=q->left;
            }
        }
        else
        {
           if(q->right==0)
           {
               q->right=p;
               break;
           }
           else
           {
               q=q->right;
           }
        }
    }
  }
}
int main()
{
    printf("To creating the BST\n");
    creating();
    int choice;
    printf("If you want to insert then PRESS-1\nIf ypu want to Delete then PRESS-2\nIf you want to Display then PRESS-3\nIf you want to Exit then PRESS-4\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=4)
    {
        if(choice==1)
        {
            insertion();
        }
        else if(choice==2)
        {
            int num;
            printf("Enter the deletiong value : ");
            scanf("%d",&num);
            deletion(root,num);
        }
        else if(choice==3)
        {
            printf("For Preorder traversal PRESS-31\nFor Inorder traversal PRESS-32\nFor Postorder traversal PRESS-33\n");
            printf("Enter your choice : ");
            scanf("%d",&choice);
            if(choice==31)
            {
                printf("Preorder traversal of given BST is : ");
                preorder(root);
                printf("\n");
            }
            else if(choice==32)
            {
                printf("Inorder traversal of given BST is : ");
                inorder(root);
                printf("\n");
            }
            else if(choice==33)
            {
                printf("Postorder traversal of given BST is : ");
                postorder(root);
                printf("\n");
            }
            else
            {
                printf("Invalid choice\n");
            }
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
}