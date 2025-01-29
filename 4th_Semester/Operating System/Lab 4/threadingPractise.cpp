#include<stdio.h>	//for printf, scanf
#include<stdlib.h>	//exit(0)
#include<pthread.h>	//pthread_create, pthread_join
#include<unistd.h>	//sleep etc

/*
	IF FUNCITONS RETURNS 0 IT IS SUCCESS
	IF VARIABLES OR NUMBERS ARE 0 IT IS FALSE I.E UNSUCCESSFULL
*/

void *myThreadFun(void* vargp) {
	sleep(1);
	printf("Printing from thread\n");
	return NULL;
}

int main() {
	// THREAD CREATION
	pthread_t thread_id;
	printf("Before Thread\n");
	// TWO LINES BELOW ARE THE MAIN PART
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n %d",myThreadFun());
	exit(0);
}
