#include <stdio.h>


void main()
{
	int i,NOP,ct=0,count=0,y,quant,wt=0,tat=0,at[10],bt[10],rembt[10];
	float avg_wt,avg_tat;
	printf("Enter the Total Number of Process in the System:");
	scanf("%d",&NOP);
	y = NOP;
	
	for(i=0;i<NOP;i++)
	{
		printf("Enter the arrival and burst time for the process[%d]\n",i+1);
		printf("Arrival Time is:");
		scanf("%d",&at[i]);
		printf("\nBurst Time is:");
		scanf("%d",&bt[i]);
		rembt[i] = bt[i]; //storing burst time in temp array
	}

	
	printf("Enter the Time Quantum for the process:");
	scanf("%d",&quant);
	printf("\n Process No \t\tBurst Time \t\tTAT \t\tWaiting Time");
	for(ct=0,i=0;y!=0;)
	{
		if(rembt[i]<=quant && rembt[i]>0)
		{
			ct = ct + rembt[i];
			rembt[i] = 0;
			count=1;
		}
   		else if(rembt[i]>0)
		{
			rembt[i]-= quant;
			ct+= quant;
		}
		if(rembt[i]==0 && count ==1)
		{
			y--; //decrementing proccess no
			printf("\nProcess No[%d] \t\t %d \t\t%d  \t\t%d",(i+1), bt[i], ct-at[i], ct-at[i]-bt[i]);
			wt = wt+ct-at[i]-bt[i];
			tat = tat+ct-at[i];
			count = 0;
		}
		if(i==NOP-1)
		{
			i=0;
		}
		else if(at[i+1]<=ct)
		{
			i++;
		}
		else
		{
			i=0;
		}
		
	}
	
	avg_wt = wt* 1.0/NOP;
	avg_tat = tat * 1.0/NOP;
	printf("\n Average Turn Around Time:%f",avg_tat);
	printf("\n Average Waiting Time:%f\n",avg_wt);
}
	











	
