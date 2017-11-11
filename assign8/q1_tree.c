#include <stdio.h>
#include <stdlib.h>
struct node
{
	char data;
	struct node *lptr,*rptr;
};

struct node *root=NULL;
struct node *getNode(char item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->lptr = temp->rptr = NULL;
    return temp;
}

struct node* insert(struct node* node, char data)
{
    if (node == NULL) 
    	return getNode(data);

    if (data <= node->data)
        node->lptr  = insert(node->lptr, data);
    else if (data > node->data)
        node->rptr = insert(node->rptr, data);   
    return node;
}

void inorder(struct node *root)
{ 
    if (root!= NULL)
    {
        inorder(root->lptr);
        printf("%c -> ", root->data);
        inorder(root->rptr);
    }
}
void postorder(struct node *root)
{
     if (root != NULL)
     {
     postorder(root->lptr);
     postorder(root->rptr);
     printf("%c -> ", root->data);
 	}
}
void preorder(struct node *root)
{
     if (root != NULL)
       {
     printf("%c -> ", root->data);  
     preorder(root->lptr);  
     preorder(root->rptr);
 }
}
void search(struct node *root,char value)
{
	if(root==NULL)
	{
		printf("Element not found\n");
	}
	else
	{
		if(value==root->data)
			{printf("Element found\n");
		    return;}
		else if(value<root->data)
			search(root->lptr,value);
		else
			search(root->rptr,value);

	}
} 
int main()
{
	int ch;

	while(1)
	{	
		printf("\nMenu\n1.Insert\n2.Search\n3.Preorder traverse\n4.Postorder traverse\n5.Inorder traverse\n6.Exit\nEnter your choice : ");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
		char n;
		printf("\nEnter data : ");
		scanf("%s",&n);
		if(root==NULL)
			root= insert(root,n);
		else
		insert(root,n);
		 }
		 break;
		case 2:
		{
		char s;
		printf("\nEnter data : ");
		scanf("%s",&s);
		if(root==NULL)
			printf("Empty tree\n");
		else
		search(root,s);
		 }
		 break;
		case 3:
		if(root==NULL)
			printf("Empty tree\n");
		else
		{
		printf("Preorder : \n");
		 preorder(root);
		printf("\n");
		}
		 break;
		case 4:
		if(root==NULL)
			printf("Empty tree\n");
		else
			{
		printf("Postorder : \n");
		 postorder(root);
		printf("\n");
		}
		 break;
		case 5:
		if(root==NULL)
			printf("Empty tree\n");
		else
			{
		printf("Inorder : \n");
		 inorder(root);
		 printf("\n");
		 	}
		 break;
		case 6:
		 exit(1);

	}
}
	return 0;
}