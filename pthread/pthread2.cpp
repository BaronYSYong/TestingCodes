/*!
 * @file pthread2.cpp
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
char end[] = "Thank you for the CPU time" ;

int main( int argc, char *argv[] )
{
	pthread_t thread; 
	int pid, res, i; 

	printf("\n---Program start------\n\n");
	pid = getpid();
	printf("1:pid = %d\n", pid);

	
	res = pthread_create( &thread, NULL/*&thread_attr*/,
												ThreadFunction, NULL );
	if( res )
	{
		perror( "pthread creation failed\n" );
		exit( EXIT_FAILURE );
	}
	
	printf( "Next line of pthread_create() called.\
           thread ID = %ld\n", thread );
	for(i=0; i<3; i++)
	{
		sleep(1);
		printf( "main() : count = %d\n", i );
	}
	printf( "\n---Main Program end------\n\n" );
	
	res = pthread_join( thread, NULL );
	if(res)
	{
		perror( "Thread join failed\n" );
		exit(EXIT_FAILURE);
	}
	printf( "Thread joined\n" );

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
	printf( "2:pid=%d\n", pid );

	for(i=0; i<6; i++)
	{
		sleep(1);
		printf( "ThreadFunction() : count = %d\n", i);
	}

	printf( "\n---ThreadFunction end---\n\n" );

	pthread_exit(end);
}
