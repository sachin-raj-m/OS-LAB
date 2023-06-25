#include<stdio.h>
struct PCB
{
 int pid,arrival,burst,tat,completion,wt,priority;
};
void pline(int x);
void main()
{
 int i,num,j;
 int total_tat=0,total_wt=0;
 int sum=0;
 struct PCB p[20],temp;
 printf("enter the number of processes:\n");
 scanf("%d",&num);
 // get arrival and burst time from user
 for(i=0;i<num;i++)
 {
  printf("enter the arrival time,burst time and priority for the process %d:\n",i+1);
  scanf("%d%d%d",&p[i].arrival,&p[i].burst,&p[i].priority);
  p[i].pid=i+1;
 }
 // set values to 0
 for(i=0;i<num;i++)
 {
  p[i].tat=0;
  p[i].wt=0;
  p[i].completion=0;
 }
// swap order of processes according to priority
 for(i=0;i<num;i++)
 {
  for(j=0;j<num-1;j++)
  {
    if(p[j].priority>p[j+1].priority)
    {
     temp=p[j];
     p[j]=p[j+1];
     p[j+1]=temp;
    }
  } 
}
 // calculate completion time
 for(i=0;i<num;i++)
 {
  sum = sum + p[i].burst;
  p[i].completion = p[i].completion + sum + 1;
 }
 // calculate total tat and total wt
 for(i=0;i<num;i++)
 {
  p[i].tat = p[i].completion - p[i].arrival;
  total_tat+=p[i].tat;
  p[i].wt = p[i].tat - p[i].burst;
  total_wt += p[i].wt;
 }
 // print the table heading row
 pline(54);
 printf("PID \t AT \t BT \t TAT \t WT \t CT \t PRIORITY \n");
 pline(54);
 // print the details of each processes
 for(i=0;i<num;i++)
 {
  printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].pid,p[i].arrival,p[i].burst,p[i].tat,p[i].wt,p[i].completion,p[i].priority);
 }
 pline(54);
 printf("Avg TAT = %d ",total_tat/num);
 printf("Average wt : %d ",total_wt/num);
}
// function to print large numbers of '-'(dash).
void pline(int x)
{ 
 for(int i = 0;i<x;i++)
 {
  printf("-");
 }
 printf("\n");
}

