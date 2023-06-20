#include<stdio.h>
int absoluteValue(int);

void main()
{
    int queue[25],n,headposition,i,j,k,seek=0, maxrange;
    int difference,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    float averageSeekTime;

    printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);   
    printf("Enter the number of queue requests: ");
    scanf("%d",&n);
    printf("Enter the initial head position: ");
    scanf("%d",&headposition);
    
    printf("Enter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++)   
    {
        scanf("%d",&temp);  //Reading position value to a temporary variable
        
        //Now if the requested position is greater than current headposition,
        //then pushing that to array queue1
        if(temp>headposition){
            queue1[temp1]=temp; 
            temp1++;
        }
        else{   
            queue2[temp2]=temp; 
            temp2++;
        }
    }
    
    
    //SORTING array queue1[] in ascending order
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    
    //SORTING array queue2[] in descending order
    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]<queue2[j])
            {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    
    //Copying first array queue1[] into queue[]
    for(i=1,j=0;j<temp1;i++,j++)
    {
        queue[i]=queue1[j]; 
    }
    queue[i]=maxrange;
    
    for(i=temp1+2,j=0;j<temp2;i++,j++)
    {
        queue[i]=queue2[j];
    }
    
    //Setting queue[i] to 0. Because that is the innermost cylinder.
    queue[i]=0;

    //At this point, we have the queue[] with the requests in the 
    //correct order of execution as per scan algorithm.
    //Now we have to set 0th index of queue[] to be the initial headposition. 
    queue[0]=headposition;
    
    
    for(j=0; j<=n; j++)
    {   
        difference = absoluteValue(queue[j+1]-queue[j]);
        seek = seek + difference;
        printf("Disk head moves from position %d to %d with Seek %d \n", queue[j], queue[j+1], difference);
    }
    averageSeekTime = seek/(float)n;
    
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);
}

int absoluteValue(int x)
{
    if(x>0)
    {
        return x;
    }
    else
    {
        return x*-1;
    }
}
