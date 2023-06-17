#include<sys/types.h>
#include<unistd.h>

void main()
{
   int q;
   printf("Before Fork\n");
   q = fork();
   if(q==0){
   printf("I'm from child process %d\n",getpid());
   printf("My Parent ID: %d\n",getppid());
   printf("My q value: %d\n",q);
   }
   else{
   wait();	//If wait is not used first parent process will be printed and then child process.
   printf("I'm from Parent process %d\n",getpid());
   printf("My Parent ID: %d\n",getppid());
   printf("My q value: %d\n",q);
   }
}

	



