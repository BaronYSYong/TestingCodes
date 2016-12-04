/*!
 * @file pthread1.cpp
 * @brief test pthread
 * @date 2013/10/30
 * @author Yong Yoon Seong
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *ThreadFunction(void *argc);
char message[] = "Hello World";
char end[] = "Thank you for the CPU time";

int main(int argc, char *argv[])
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, ThreadFunction, (void *)message);  

	if(res)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish...\n");

	for (int i=0; i<10; i++)
		printf("wait 1-%i\n", i);

	sleep(1);

	for (int i=0; i<10; i++)
		printf("wait 2-%i\n", i);

	res = pthread_join(a_thread, &thread_result);

	if(res)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %s\n",(char *)thread_result);
	printf("Message is now %s\n",message);
	exit(EXIT_SUCCESS);
}

void *ThreadFunction(void *argv)
{
  printf("ThreadFunction is running. Argument was \%s\n", (char *)argv);
  sleep(3);

  strcpy(message, "Bye!!");
  
  pthread_exit(end);
  /// return "Thank you for the CPU time"
}
