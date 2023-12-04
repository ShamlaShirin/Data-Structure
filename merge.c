#include<stdio.h>
 void main()
{
	void readarray(int[],int);
	void printarray(int[],int);
	void sortarray(int[],int);
	void merge(int[],int[],int[],int,int);
	int ar1[100],ar2[100],ar3[100],m,n;
	printf("Number of elements in 1st array: ");
	scanf("%d",&m);
	printf("Enter elements of 1st array: ");
	readarray(ar1,m);
	printf("Number of elements in 2nd array: ");
	scanf("%d",&n);
	printf("Enter elements of 2nd array: ");
	readarray(ar2,n);
	sortarray(ar1,m);
	sortarray(ar2,n);
	merge(ar1,ar2,ar3,m,n);
	printf("Merge Array\n");
	printarray(ar3,m+n);
}

//fn to read n elements 
void readarray(int x[],int n)
{	
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&x[i]);
}

//fn to display the content
void printarray(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",x[i]);
	printf("\n");
}

//fn to sort array
void sortarray(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(a[i]>a[j])
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}

//fn to merge array
void merge(int ar1[100],int ar2[100],int ar3[100],int m,int n)
{
	int i,j,k;
	i=j=k=0;

	while(i<m && j<n)
	if(ar1[i]<ar2[j])
	ar3[k++]=ar1[i++];
	else
	ar3[k++]=ar2[j++];

	while(i<m)
	ar3[k++]=ar1[i++];
	
	while(j<n)
	ar3[k++]=ar2[j++];
	return;
}
