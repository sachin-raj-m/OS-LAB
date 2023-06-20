#include <stdio.h>

void fifo(int string[20],int n, int size){
	
	int frames[n];
	
	for(int i=0;i<n;i++)
	frames[i]= -1;
	
	int index = -1; //index to insert element
	
	int page_miss = 0;
	int page_hit = 0;
	
	for(int i=0;i<size;i++){		
		int symbol = string[i];	
		int flag = 0;
		
		for(int j=0;j<n;j++){
			if(symbol==frames[i]){
				flag = 1;
				break;
			}
		}
		
		if(flag==1){
			printf("/nSymbol: %d Frame: %d ",symbol);
			for(int j=0;j<n;j++)
			printf("%d\t",frames[j]);
			page_hit+=1;
		}
		else{
			index = (index+1)%n;
			frames[index] = symbol;
			page_miss+=1;
			printf("/nSymbol: %d Frame: %d ",symbol);
			for(int j=0;j<n;j++)
			printf("%d\t",frames[j]);
		}
	}
	printf("\nPage Hits: %d",page_hit);
	printf("\nPage Faults: %d",page_miss);
}

void main()
{
	int string[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int no_frames = 3;
	int size = sizeof(string)/sizeof(int);
	fifo(string,no_frames,size);
}

