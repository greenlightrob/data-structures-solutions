#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *lptr,*rptr;
};

struct node *root=NULL;
struct node *getNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->lptr = temp->rptr = NULL;
    return temp;
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) 
    	return getNode(data);

    if (data <= node->data)
        node->lptr  = insert(node->lptr, data);
    else if (data > node->data)
        node->rptr = insert(node->rptr, data);   
    return node;
}

int max(struct node *root)
{
	if(root->rptr==NULL)
		return root->data;
	else
		return max(root->rptr);
	
}
int min(struct node *root)
{
	if(root->lptr==NULL)
		return root->data;
	else
		return min(root->lptr);
	
}
void preorder(struct node *root)
{
     if (root != NULL)
       {
     printf("%d -> ", root->data);  
     preorder(root->lptr);  
     preorder(root->rptr);
 }
}
int main()
{
	int ch;

	while(1)
	{	
		printf("\nMenu\n1.Insert\n2.Max element\n3.Min element\n4.Preorder\n5.Exit\nEnter your choice : ");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
		int n;
		printf("\nEnter data : ");
		scanf("%d",&n);
		if(root==NULL)
			root= insert(root,n);
		else
		insert(root,n);
		 }
		 break;
		case 2:
		   {
		   	if(root==NULL)
		   		printf("Empty tree\n");
		   	printf("Maximum element of the tree : %d ",max(root));
		   }
		   break;
		  case 3:
		   {
		   	if(root==NULL)
		   		printf("Empty tree\n");
		   	printf("Minimum element of the tree : %d ",min(root));
		   }
		   break; 
		case 4:
		{if(root==NULL)
			printf("Empty tree\n");
		else
		{
		printf("Preorder : \n");
		 preorder(root);
		printf("\n");
		}}
		 break;
		case 5:
		 exit(1);

	}
}
	return 0;
}