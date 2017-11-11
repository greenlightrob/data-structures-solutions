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

int depth(struct node *node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       int l = depth(node->lptr);
       int r = depth(node->rptr);
       if (l > r) 
           return l+1;
       else 
       	   return r+1;
   }
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
		printf("\nMenu\n1.Insert\n2.Depth\n3.Preorder\n4.Exit\nEnter your choice : ");
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
		   	printf("Depth of the tree : %d \n",depth(root));
		   }
		   break;
		case 3:
		{if(root==NULL)
			printf("Empty tree\n");
		else
		{
		printf("Preorder : \n");
		 preorder(root);
		printf("\n");
		}}
		 break;
		case 4:
		 exit(1);

	}
}
	return 0;
}