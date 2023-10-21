#include<stdio.h> 
struct process{ 
int pid,bt,ct,tat,wt; 
}; 
void main() 
{ 
    int n,i; 
    float sumtat=0,sumwt=0; 
    printf("Enter the number of process: "); 
    scanf("%d",&n); 
    struct process p[n]; 
    for(i=0;i<n;i++) 
    { 
        p[i].pid=i; 
        printf("Enter the burst time of process P%d :",p[i].pid); scanf("%d",&p[i].bt); 
    } 
    printf("\nGantt Chart"); 
    printf("\n-------------------------------------------\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("|P%d\t",p[i].pid); 
        if(i==0) 
        { 
            p[i].ct=p[i].bt; 
        } 
        else 
        { 
            p[i].ct=p[i-1].ct+p[i].bt; 
        } 
        p[i].tat=p[i].ct; 
        p[i].wt=p[i].tat-p[i].bt; 
    } 
    printf("|\n-------------------------------------------\n0"); 
    for(i=0;i<n;i++) 
    {
        printf("\t%d",p[i].ct); 
        sumtat+=p[i].tat; 
        sumwt+=p[i].wt; 
    } 
    printf("\n\nPROCESS\tBT\tTAT\tWT\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("P%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].tat,p[i].wt); } 
        printf("\nTotal turn around time = %.2f ms",sumtat); 
        printf("\nTotal waiting time = %.2f ms",sumwt); 
        printf("\nAverage turn around time = %.2f ms",sumtat/n); printf("\nAverage waiting time = %.2f ms\n",sumwt/n); 
} 
