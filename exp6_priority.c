#include<stdio.h>
int main()
{ 
 int bt[20],p[20],pr[20],wt[20],tat[20],i,j,n,total=0,pos,temp; 
 float avg_wt,avg_tat; 
 printf("ENTER number of process:"); 
 scanf("%d",&n); 
 printf("\nEnter Burst time and priority\n"); 
 for( i=0;i<n;i++) 
 { 
 printf("\nP[%d]:\n",i+1); 
 printf("burst time:"); 
 scanf("%d",&bt[i]); 
 printf("priority:"); 
 scanf("%d",&pr[i]); 
 p[i]=i+1; 
 } 
 for(i=0;i<n-1;i++) 
 { 
 
 for(j=1;j<=n-i-1;j++) 
 { 
 if(pr[j-1]>pr[j]) 
 { 
 int t=pr[j-1]; 
 pr[j-1]=pr[j]; 
 pr[j]=t; 
 t=bt[j-1]; 
 bt[j-1]=bt[j]; 
 bt[j]=t; 
 
 t=p[j-1]; 
 p[j-1]=p[j]; 
 p[j]=t; 
 } 
 } 
 } 
 wt[0]=0; 
 for(i=1;i<n;i++) 
 { 
 wt[i]=0; 
 for(j=0;j<i;j++) 
 wt[i]+=bt[j]; 
 total+=wt[i]; 
 } 
 avg_wt=(float)total/n; 
 total=0; 
 printf("/nProcess Burst time waiting time turnaround time"); 
 for(int i=0;i<n;i++) 
 { 
 tat[i]=bt[i]+wt[i]; 
 total+=tat[i]; 
 printf("\n P[%d] %d %d %d",p[i],bt[i],wt[i],tat[i]); 
 } 
 avg_tat=(float)total/n; 
 printf("\n\nAverage waiting time=%f",avg_wt); 
 printf("\nAverage Turnaroun time=%f\n",avg_tat); 
 return(0); 
} 
