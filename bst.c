#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
};
void main()
{
	struct node *insert(struct node*,int);
	struct node *delete(struct node*,int);
	int search(struct node*,int);
	void inorder(struct node*);
	int option,ans,data,item;
	struct node *root=(struct node*)0;
	do
	{
		printf("\n1.INSERT\n");
		printf("2.DELETE\n");
		printf("3.SEARCH\n");
		printf("4.TRAVERSE\n");
		printf("5.EXIT\n");
		printf("Option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Data:");
				scanf("%d",&data);
				root=insert(root,data);
				break;
				
			case 2:printf("Data:");
				scanf("%d",&data);
				root=delete(root,data);
				break;
				
			case 3:printf("Item to search:");
				scanf("%d",&data);
				ans=search(root,data);
				if(ans!=0) 
					printf("Found\n");
				else
					printf("Not Found \n");
				break;
			case 4:inorder(root);	
				break;
			case 5:exit(0);		
		}
	}
	while(1);
}

//fn to insert an item
struct node *insert(struct node *root,int data)
{
	struct node *par=(struct node*)0,*t,*troot=root;
	while(root != (struct node*)0 && (data != root->data))
	{
		par=root;
		if(data<root->data)
			root=root->lchild;
		else
		{
			root=root->rchild;
		}
	}
	if(root !=(struct node*)0)
	{
		printf("Duplicate\n");
	}
	else
	{
		t=(struct node*)malloc(sizeof(struct node));
		t->data=data;
		t->lchild=t->rchild=(struct node *)0;
	if(par == (struct node *)0)
	{
		troot=t;
	}
	else if(data<par->data)
	
		par->lchild=t;
	else
		par->rchild=t;
	}
	return troot;
}

//fn to delete an item
struct node *delete(struct node *root,int data)
{
	struct node *par=(struct node*)0,*t,*sucpar,*suc,*lchild,*rchild;
	t=root;
	while(root != (struct node*)0 && data != root->data)
	{
		par=root;
		if(data<root->data)
			root=root->lchild;
		else
			root=root->rchild;
	}
	if(root == (struct node*)0)
		printf("Not Found");
	else
	{
		if(root->lchild==(struct node*)0 && root->rchild==(struct node*)0)//case of 0 child
			if(par==(struct node*)0)//case of root removal
				t=(struct node*)0;
			else if(root->data>par->data)
				par->rchild=(struct node*)0;
			else
				par->lchild=(struct node*)0;
			else if(root->lchild==(struct node*)0 || (root->rchild==(struct node*)0))//case of 1 child
			{
				if(par==(struct node*)0) //root removal
					t=root->lchild==(struct node*)0 ? root->rchild : root->lchild;
				else if(data<par->data)
					par->lchild=root->lchild==(struct node*)0 ? root->rchild : root->lchild;
				else
					par->rchild=root->lchild==(struct node*)0 ? root->rchild : root->lchild;
			}
				else //case of 2 children
				{
					suc=root->rchild;
					sucpar=root;
				while(suc->lchild != (struct node*)0)
				{
					sucpar=suc;
					suc=suc->lchild;
				}
				root->data=suc->data;
				if(suc->data<sucpar->data)
				sucpar->lchild=suc->rchild;
				else
				sucpar->rchild=suc->rchild;
				root=suc;
				}	
				free(root);
		}
		
		
		return t;
}

//fn to search an item
int search(struct node *root,int data)
{
	while(root !=(struct node*)0 && root->data != data)
	{
		if(data<root->data)
			root=root->lchild;
	else
		root=root->rchild;
	}
	if(root==(struct node*)0)
	return 0;
	else
	return 1;					
}

//fn to traverse an item
void inorder(struct node *root)
{
	if(root != (struct node*)0)
	{
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
	}
}
	
