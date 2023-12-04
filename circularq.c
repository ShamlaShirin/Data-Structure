#include<stdio.h>
#include<stdlib.h>
#define size 5
int que[size];
int front=0,rear=0;
void main()
{
	void enque(int);
	int deque();
	int search(int);
	int option,item,ans;
	do
	{
		printf("1.INSERT\n");
		printf("2.DELETE\n");
		printf("3.SEARCH\n");
		printf("4.EXIT\n");
		printf("Option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Item:");
				scanf("%d",&item);
				enque(item);
				break;
				
			case 2:item=deque();
				printf("Item:%d\n",item);
				break;
				
			case 3:printf("Item to search:");
				scanf("%d",&item);
				ans=search(item);
				if(ans != 0) 
					printf("%d found at %d position\n",item,ans);
				else
					printf("%d not found \n",item);
				break;
				
			case 4:exit(0);		
		}
	}
	while(1);
}
	
//fn to insert an item in circular queue
void enque(int item)
{
	int t;
	t=(rear+1)%size;
	if(t==front)
	{  
		printf("Que is full");
		exit(1);
	}	
	else
	{
	rear=t;
	que[rear]=item;
	}
}

//fn to delete an item
int deque()   
{
	if(front==rear)
	{
		printf("Que is empty");   
		exit(2);
	}
	front=(front+1)%size;
	return que[front];
} 
//fn to search an item
int search(int item)
{
	int t1,t2;
	t1=front,t2=rear;
	if(front==rear)
		return 0;
		t1=(t1+1)%size;
	while(t1 != t2 && que[t1] != item)
		t1=(t1+1)%size;
	if(que[t1]==item)
		return t1;
	else
		return 0;
}
	


			
			
