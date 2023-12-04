#include<stdio.h>
typedef struct
{
	unsigned char x:1;
}bit;
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
	void readset(bit[],int n);
	void printset(bit[]);
	void unionset(bit[],bit[],bit[]);
	void intersect(bit[],bit[],bit[]);
	void difference(bit[],bit[],bit[]);
	bit a[10]={0},b[10]={0},c[10]={0};
	int n;
	printf("No. of elements in set A: ");
	scanf("%d",&n);
	readset(a,n);
	printf("No. of elements in set B: ");
	scanf("%d",&n);
	readset(b,n);
	printf("set A:");
	printset(a);
	printf("set B:");
	printset(b);
	unionset(a,b,c);
	printf("AUB=");
	printset(c);
	intersect(a,b,c);
	printf("AnB=");
	printset(c);
	difference(a,b,c);
	printf("A-B=");
	printset(c);
}

//fn to read a set and store as bit string
void readset(bit a[],int n)
{
	int i,k,x;
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(k=0;k<size;k++)
		{
			if(uset[k]==x)
			{
				a[k].x=1;
				break;
			}
		}
	}
	return;
}

//fn to print a set from bit string
void printset(bit a[])
{
	int k;
	printf("{");
	for(k=0;k<size;k++)
	{
		if(a[k].x==1)
			printf("%d,",uset[k]);
	}
	printf("\b}\n");
	return;
}

//fn to union of 2 sets using bit string
void unionset(bit a[],bit b[],bit c[])
{
	int k;
	for(k=0;k<size;k++)
	c[k].x=a[k].x | b[k].x;
	return;
}

//fn to find intersection of 2 sets
void intersect(bit a[],bit b[],bit c[])
{
	int k;
	for(k=0;k<size;k++)
	c[k].x=a[k].x & b[k].x;
	return;
}

//fn to find difference of 2 sets
void difference(bit a[],bit b[],bit c[])
{
	int k;
	for(k=0;k<size;k++)
	{
		if(a[k].x==1)
			c[k].x=a[k].x ^ b[k].x;
	}
	return;
}

	
	
