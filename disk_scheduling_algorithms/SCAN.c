#include<stdio.h>
void main()
{
int head, reqno, i, dist, sum = 0;
printf("Enter the current head position: ");
scanf("%d", &head);

printf("Enter the number of requests: ");
scanf("%d", &reqno);
printf("Enter the requests:\n");
int arr[reqno];
for(i=0;i<reqno;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<reqno-1;i++)
{
for(int j=i+1;j<reqno;j++)
{
if(arr[i]>arr[j])
{
int temp=arr[i];
arr[i]=arr[j];
arr[j] = temp;
}
}
}
int position;
for(i=0;i<reqno;i++)
{
if(head<arr[i])
{
position=i;
break;
}
}
for(i=position-1;i>=0;i--)
{
dist=head-arr[i];
sum+=dist;
printf("Head movement from %d to %d: %d cylinders\n",head,arr[i],dist);
head=arr[i];
}
dist=head;
sum+=dist;
printf("Head movement from %d to %d: %d cylinders\n", head,0,dist);
head=0;
for(i=position;i<reqno;i++)
{
dist=arr[i]-head;

sum+=dist;
printf("Head movement from %d to %d: %d cylinders\n",head,arr[i],dist);
head=arr[i];
}
printf("Total head movement: %d cylinders\n",sum);
}
