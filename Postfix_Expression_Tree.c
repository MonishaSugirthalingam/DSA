#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	char data;
	struct node* left;
	struct node* right;
	struct node* next;
};
struct node *head=NULL;
struct node* newNode(char data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	
	return (node);
}
void printInorder(struct node* node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
	}
}

void push(struct node* x)
{
	if(head==NULL)
	{
	head = x;
	}
	else
	{
		(x)->next = head;
		head = x;
	}
}
struct node* pop()
{
	struct node* p = head;
	head = head->next;
	return p;
}
int main()
{
    printf("Enter the postfix expression : ");
    char s[100];
    scanf("%s",s);
	int len=strlen(s);
	struct node *x, *y, *z;
	for (int i=0; i<len;i++) 
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*'|| s[i] == '/' || s[i] == '^') 
		{
			z = newNode(s[i]);
			x = pop();
			y = pop();
			z->left = y;
			z->right = x;
			push(z);
		}
		else 
		{
			z = newNode(s[i]);
			push(z);
		}
	}
	printf(" The Inorder Traversal of Expression Tree: ");
	printInorder(z);
	return 0;
}
