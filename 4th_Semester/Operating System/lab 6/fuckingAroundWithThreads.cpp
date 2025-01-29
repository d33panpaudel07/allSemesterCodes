#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

const int threads = 2;
bool flag[threads] = {false,false};
int th;
int turn;

void lock_init() {
	for(int i; i < threads; i++) {
		flag[i] = false;
	}
	th = -1;
	turn = -1;
}

void lock(void* self) {
	int* threads = (int*)self;
	printf("Thread %d will be locked \n",*(int*)self);
	flag[*threads] = true;
	printf("Thread %d will get turn \n",*(int*)self);
	turn = 1 - *threads;
	sleep(1);
	printf("Thread %d locked successfully \n",*(int*)self);
}

void unlock(void* self) {
	int* threads = (int*)self;
	flag[*threads] = false;
}

void* thread1(void* val) {
	int th = 0;
//	lock(&th);

	while((flag[1-th] == 0) && (turn == 1-th)) {
		// WHILE CASE TO MAKE FUNCITON WAIT
	}
	// CRITICAL SECTION
	*(int*)val = *(int*)val * *(int*)val;
	printf("val: %d\n",*(int*)val);
	// END OF CRITICAL SECTION

	return (int*)val;
}

void* thread2(void* val) {

	*(int*)val = *(int*)val + *(int*)val;
	printf("val: %d\n",*(int*)val);

	return (int*)val;

}

int main() {
	int ans = 5;
//	pthread_t t1,t2;
//	pthread_create(&t1, NULL, thread1, &ans);
//	pthread_create()
//	lock(&haha);
	thread1(&ans);
//	printf("thread2(&ans): %d",*(int*)thread1(&ans));
	printf("thread2(&ans): %d",ans);
}