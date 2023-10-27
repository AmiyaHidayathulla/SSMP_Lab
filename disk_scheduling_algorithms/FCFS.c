#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
int head,rno,i,j,sum=0,dist=0;
printf("Enter the no.of requests: ");
scanf("%d",&rno);
int arr[rno];
for(i=0;i<rno;i++)
{
printf("enter the request %d: ",i+1);
scanf("%d",&arr[i]);
}
printf("Enter the current head position: ");
scanf("%d",&head);
for(i=0;i<rno;i++)
{
dist=abs(arr[i]-head);
printf("head postion from %d to %d is %d cylinders\n",head,arr[i],dist);
sum=sum+dist;
head=arr[i];
}
printf("Toatal head movement = %d cylinders",sum);
}
