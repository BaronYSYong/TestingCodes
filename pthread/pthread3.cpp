/*!
 * @file pthread3.cpp
 * @brief test pthread
 * @date 2013/10/30
 * @author Yong Yoon Seong
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

void *ThreadFunction( void *param );


int main( int argc, char *argv[] )
{
	int pid; 
	pthread_t thread; 
	pthread_attr_t thread_attr; 
	int res, i; 

	printf("\n---Program start------\n\n");
	pid = getpid(); 
	printf("1:pid = %d\n", pid);


	res = pthread_attr_init(&thread_attr);
	if( res!=0 )
	{
		perror( "Attribute creation failed\n" );
		exit(EXIT_FAILURE);
	}

	res = pthread_attr_setdetachstate( &thread_attr, PTHREAD_CREATE_DETACHED);
	if( res!=0 )
	{
		perror( "Stetting detached attribute failed\n" );
		exit(EXIT_FAILURE);
	}


	res = pthread_create( &thread, &thread_attr,ThreadFunction, NULL );
	if( res!=0 )
	{
		perror( "pthread creation failed\n" );
		exit( EXIT_FAILURE );
	}


	pthread_attr_destroy( &thread_attr );

	printf( "Next line of pthread_create() called.\n");
	printf( "thread ID = %ld\n", thread );
	for(i=0; i<3; i++)
	{
		sleep(1);
		printf( "main() : count = %d\n", i );
	}
	printf( "\n---Program end------\n\n" );

	exit( EXIT_SUCCESS );
}


void *ThreadFunction( void *param )
{
	int pid; 
	int i;
	pthread_t threadID;

	threadID = pthread_self();
	printf( "\n---ThreadFunction called---\n\n" );
	printf( "threadID = %ld\n", threadID );
	pid = getpid();
	printf( "2:pid = %d\n", pid );

	for(i=0; i<6; i++)
	{
		sleep(1);
		printf( "ThreadFunction() : count = %d\n", i);
	}

	printf( "\n---ThreadFunction end---\n\n" );

	pthread_exit(NULL);

}
