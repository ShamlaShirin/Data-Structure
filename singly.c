#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void main()
{
	struct node*sp=(struct node*)0; //empty stack
	struct node*push(struct node*,int);
	struct node*pop(struct node*,int *);
	int option,item,ans,data;
	int search(struct node *,int);
	do
	{
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.SEARCH\n");
		printf("4.EXIT\n");
		printf("Option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Data:");
				scanf("%d",&item);
				sp=push(sp,item); //call the function push
				break;
				
			case 2:if(sp==(struct node*)0)
				printf("Empty Stack\n");
				else
				{
				sp=pop(sp,&item);
				printf("Popped Item=%d\n",item);
				}
				break;
				
			case 3:printf("Item to search:");
				scanf("%d",&item);
				ans=search(sp,item);
				if(ans != 0)
					printf("Item found\n");
				else
					printf("Not found \n");
				break;
				
			case 4:exit(0);		
		}
	}
	while(1);
}

//fn to push an item in linked stack
struct node*push(struct node*sp,int data)
{
	struct node*t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=data;
	t->next=sp;
	return t;
}

//fn to pop an element
struct node*pop(struct node*sp,int *data)
{
	struct node*t=sp;
	if(sp != (struct node *)0)
	{
		*data=sp->data;
		sp=sp->next;
		free(t);
	}
	return sp;
}

//fn to search an item
int search(struct node*sp,int data)
{
	while(sp != (struct node*)0 && sp->data != data)
	{
		sp=sp->next;
	}
	if(sp==(struct node*)0)
		return 0;
	else 
		return 1;
}

