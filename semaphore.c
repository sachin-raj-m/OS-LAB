#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

void *fun1();
void *fun2();

int shared = 1;
sem_t s;

int main()
{
	sem_init(&s,0,1);	//address, no of 
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Final Value of Shared is %d\n",shared); //prints the last updated value of shared x
}

void *fun1()
{
	int x;
	sem_wait(&s);
	x = shared; //reading the value of shared variable
	printf("Thread 1 reads the vale as %d\n",x);
	x++; //incrementing the shared variable
	
	printf("Local Updateion by Thread 1: %d\n",x);
	sleep(1);
	shared = x;
	
	printf("Value of Shared Vaiabel updated by Thread1 is: %d\n",shared);
	sem_post(&s);
}

void *fun2()
{
	int y;
	sem_wait(&s);
	y = shared; //reading the value of shared variable
	printf("Thread 2 reads the vale as %d\n",y);
	y--; //incrementing the shared variable
	
	printf("Local Updateion by Thread2: %d\n",y);
	sleep(1);
	shared = y;
	
	printf("Value of Shared Vaiabel updated by Thread2 is: %d\n",shared);
	sem_post(&s);
}
