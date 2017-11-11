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

int nodeno(struct node* node) 
{  
  if (node==NULL) 
    return 0;
  else    
    return nodeno(node->lptr) + 1 + nodeno(node->rptr);  
}

int main()
{
	int ch;

	while(1)
	{	
		printf("\nMenu\n1.Insert\n2.Number of nodes\n3.Exit\nEnter your choice : ");
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
		   	printf("No. of nodes in the tree : %d \n",nodeno(root));
		   }
		   break;
		case 3:
		 exit(1);

	}
}
	return 0;
}