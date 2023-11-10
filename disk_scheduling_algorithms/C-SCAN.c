#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int head,rno,i,j,sum=0,dist=0,max;
	printf("Enter the maximum no.of cylinders: ");
	scanf("%d",&max);
	printf("Enter the no.of requests: ");
	scanf("%d",&rno);
	int arr[rno];
	for(i=0;i<rno;i++)
	{
		printf("Enter the request %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the current head position: ");
	scanf("%d",&head);
	
	for(i=0;i<rno;i++)
	{
		for(j=0;j<rno-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	int position;
	for(i=0;i<rno;i++)
	{
		if(arr[i]>head)
		{
			position=i;
			break;
		}
	}
	for(i=position;i<rno;i++)
	{
		dist=arr[i]-head;
		printf("head movement from %d to %d is %d cylinders\n",head,arr[i],dist);
		sum=sum+dist;
		head=arr[i];
	}
	if(position!=0)
	{
		dist=max-1-head;
		printf("head movement from %d to %d is %d cylinders\n",head,max-1,dist);
		sum=sum+dist;
		head=max-1;
		dist=head-0;
		sum=sum+dist;
		printf("head movement from %d to %d is %d cylinders\n",max-1,0,dist);
		head=0;
		for(i=0;i<position;i++)
		{
			dist=arr[i]-head;
			printf("head movement from %d to %d is %d cylinders\n",head,arr[i],dist);
			sum=sum+dist;
			head=arr[i];
		}
	}
	printf("Total head movement = %d cylinders\n",sum);
}
