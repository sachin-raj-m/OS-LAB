#include<stdio.h>
struct PCB
{
int pid,arrival,burst,tat,completion,wt;
};
void pline(int x);
void main()
{
int i,num,j;
int total_tat=0,total_wt=0;
int sum = 0;
struct PCB p[20],temp;
printf("Enter the number of processes :\n");
scanf("%d",&num);
// Get arrival and burst time from user
for(i=0;i<num;i++)
{
printf("Enter the Arrival Time and Burst Time for the process %d: \n",i+1);
scanf("%d %d",&p[i].arrival,&p[i].burst);
p[i].pid = i+1;
}
// Set values to 0
for(i = 0; i<num; i++)
{
p[i].tat = 0;
p[i].wt = 0;
p[i].completion = 0;
}
// Swap order of processes according to arrival time
for(i=0;i<num;i++)
{
for(j=0;j<num-1;j++)
{
if(p[j].arrival > p[j+1].arrival)
{
temp = p[j];
p[j] = p[j+1];
p[j+1] = temp;
}
}
}
// Calculate completion time
for(i=0;i<num;i++)
{
sum = sum + p[i].burst;
p[i].completion = p[i].completion + sum +1;
}
// Calculate Total TAT and Total WT
for(i=0;i<num;i++)
{
p[i].tat = p[i].completion - p[i].arrival;
total_tat += p[i].tat;
p[i].wt = p[i].tat - p[i].burst;
total_wt += p[i].wt;
}
//Print the table heading row
pline(44);
printf("PID \t AT \t BT \t TAT \t WT \t CT \n");
pline(44);
//Print the details of each process
for(i = 0; i<num; i++)
{
printf("%d \t %d \t %d \t %d \t %d \t %d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].tat,p[i].wt,p[i].completion);
}
pline(44);
printf("Avg TAT = %d",total_tat / num);
printf("Average wt : %d", total_wt / num);
}
// Function used for printing large number of '-'(dash).
void pline(int x)
{
for(int i =0;i<x;i++)
{
printf("-");
}
printf("\n");
}

