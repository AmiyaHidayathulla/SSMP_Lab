#include<stdio.h>
#include<stdlib.h>
void main()
{
    int pno,resno,i,j,k,ind=0;
    printf("Enter the no.of processes: ");
    scanf("%d",&pno);
    printf("Enter the no.of resources: ");
    scanf("%d",&resno);
    int alloc[pno][resno], max[pno][resno], need[pno][resno],avail[resno],f[pno],a[pno];
    for(i=0;i<pno;i++)
    {
        printf("Enter the maximum resources of P%d: ",i);
        for(j=0;j<resno;j++)
        {
             scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<pno;i++)
    {
        printf("Enter the allocated resources of P%d: ",i);
        for(j=0;j<resno;j++)
        {
             scanf("%d",&alloc[i][j]);
        }
    }
     printf("Enter the available resources: ");
     for(i=0;i<resno;i++)
     {
         scanf("%d",&avail[i]);
     }
     for(i=0;i<pno;i++)
     {
         f[i]=0;
     }
     for(i=0;i<pno;i++)
     {
         for(j=0;j<resno;j++)
         {
             need[i][j]=max[i][j]-alloc[i][j];
         }
     }
     printf("\n\tALLOCATION\tMAX\tNEED\n");
     for(i=0;i<pno;i++)
     {
         printf("p%d\t",i);
         for(j=0;j<resno;j++)
         {
             printf("%d ",alloc[i][j]);
         }
         printf("\t\t");
         for(j=0;j<resno;j++)
         {
             printf("%d ",max[i][j]);
         }
         printf("\t");
         for(j=0;j<resno;j++)
         {
             printf("%d ",need[i][j]);
         }
         printf("\t\n");
     }
     for(k=0;k<pno;k++)
     {
         for(i=0;i<pno;i++)
         {
             if(f[i]==0)
             {
                int flag=0;  
                for(j=0;j<resno;j++)
                 {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                 }
                 if(flag==0)
                 {
                     a[ind++]=i;
                     for(j=0;j<resno;j++)
                     {
                        avail[j]=avail[j]+alloc[i][j];
                     }
                     f[i]=1;
                 }
             }
         }
     }
      int flag=1;
     for(i=0;i<pno;i++)
     {
         if(f[i]==0)
         {
             flag=0;
             printf("the system is not in a safe sequence!!");
             break;
         }
     }
     if(flag==1)
     {
         printf("the system is in safe sequence\nSAFE SEQUENCE\n");
         for(i=0;i<pno-1;i++)
         {
             printf("P%d->",a[i]);
         }
         printf("P%d ",a[pno-1]);
     }
}
