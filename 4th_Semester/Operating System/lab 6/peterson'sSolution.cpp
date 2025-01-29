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
	th = 0;
	lock(&th);

	while((flag[1-th] == true) && (turn == 1-th)) {
		// WHILE CASE TO MAKE FUNCITON WAIT
	}
	// CRITICAL SECTION
	*(int*)val = *(int*)val * *(int*)val;
	printf("Performing ans * ans: %d",*(int)val);
	// END OF CRITICAL SECTION
	unlock(&th);
//	return (int*)val;
}

void* thread2(void* val) {
	th = 1;
	lock(&th);

	while((flag[1-th] == true) && (turn == 0)) {
		// WHILE CASE TO MAKE FUNCITON WAIT
	}
	// CRITICAL SECTION
	*(int*)val = *(int*)val + *(int*)val;
	printf("Performing ans + ans: %d",*(int)val);
	// END OF CRITICAL SECTION
	unlock(&th);
//	return (int*)val;
}

int main() {
	int ans = 5;
	thread2(&ans);//	THREAD 2 MULTIPLIES ANS TO ITSELF		
	thread1(&ans);//	THREAD 1 ADDS ANS TO ITSELF
	printf("thread2(&ans): %d",ans);
}