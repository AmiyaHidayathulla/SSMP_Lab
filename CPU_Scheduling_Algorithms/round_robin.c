#include<stdio.h> 
struct process{ 
int pid,bt,ct,tat,wt,rt; 
}; 
void main() 
{ 
int n,i,slice,sumbt=0,k=0,currt=0; 
float sumtat=0,sumwt=0; 
printf("Enter the number of process: "); 
scanf("%d",&n); 
struct process p[n]; 
for(i=0;i<n;i++) 
{ 
p[i].pid=i; 
printf("Enter the burst time of process P%d :",p[i].pid); scanf("%d",&p[i].bt); 
sumbt+=p[i].bt; 
p[i].rt=p[i].bt; 
} 
printf("Enter the time slice :"); 
scanf("%d",&slice); 
int arr[sumbt]; 
int flag=0; 
printf("\nGantt Chart"); 
printf("\n--------------------------------\n"); 
while(flag!=n) 
{ 
for(i=0;i<n;i++) 
{ 
if(p[i].rt>0) 
{ 
if(p[i].rt>slice) 
{ 
p[i].rt-=slice; 
currt+=slice; 
arr[k++]=currt; 
printf("|P%d\t",p[i].pid);
} 
else if(p[i].rt<=slice) 
{ 
currt+=p[i].rt; 
p[i].rt=0; 
p[i].ct=currt; 
arr[k++]=currt; 
p[i].tat=p[i].ct; 
p[i].wt=p[i].tat-p[i].bt; 
flag+=1; 
printf("|P%d\t",p[i].pid); 
} 
} 
} 
} 
printf("|\n--------------------------------\n0"); 
for(i=0;i<k;i++) 
{ 
printf("\t%d",arr[i]); 
} 
printf("\n\nProcess\tBT\tTAT\tWT\n"); 
for(i=0;i<n;i++) 
{ 
sumtat+=p[i].tat; 
sumwt+=p[i].wt; 
printf("P%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].tat,p[i].wt); } 
printf("\nTotal turn around time = %.2f ms",sumtat); printf("\nTotal waiting time = %.2f ms",sumwt); printf("\nAverage turn around time = %.2f ms",sumtat/n); printf("\nAverage waiting time = %.2f ms\n",sumwt/n); 
}
