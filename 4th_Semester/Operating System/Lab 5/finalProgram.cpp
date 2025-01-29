#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, AT, BT, WT, TAT;
};

struct process a[10];
int queue[100];
int front = -1;
int rear = -1;

void inputArrivalTime(int n, int *arrivalTime);
void inputBurstTime(int n, int *burstTime, int *p);
void swap(int *x, int *y);
void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime);
void sortingSJF(int n, int *at, int *bt, int *p);
float calculateAvgTATime(int *TATime, int n);
float calculateAvgWaitingTime(int *WaitingTime, int n);
void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SRTN(int n);
void insert(int n);
int delete();
void RR(int n);

int main() {
    int choice;

    while (1) {
        printf("\nProcess scheduling algorithm:\n");
        printf("1. First Come First Serve\n");
        printf("2. Shortest Job First (non-preemptive)\n");
        printf("3. Shortest Remaining Time Next (preemptive)\n");
        printf("4. Round Robin\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int n;
        float avgWaiting, avgTA;

        if (choice == 5) {
            printf("Terminating program!!\n");
            exit(0);
        }

        printf("Enter the number of processes: ");
        scanf("%d", &n);

        int *arrivalTime = malloc(n * sizeof(int));
        int *burstTime = malloc(n * sizeof(int));
        int *waitingTime = malloc(n * sizeof(int));
        int *TATime = malloc(n * sizeof(int));
        int *Process = malloc(n * sizeof(int));
        system("clear");

        switch (choice) {
            case 1:
                printf(">>>>First Come First Serve<<<<\n");
                printf("Number of processes: %d\n", n);
                printf("Enter the arrival time: ");
                inputArrivalTime(n, arrivalTime);
                printf("Enter the burst time: ");
                inputBurstTime(n, burstTime, Process);
                FCFS(n, TATime, arrivalTime, burstTime, waitingTime, Process);
                printf("\n=====================================================================================\n\n");
                break;

            case 2:
                printf(">>>>Shortest Job First (non-preemptive)<<<<\n");
                printf("Number of processes: %d\n", n);
                printf("Enter the arrival time: ");
                inputArrivalTime(n, arrivalTime);
                printf("Enter the burst time: ");
                inputBurstTime(n, burstTime, Process);
                SJF(n, TATime, arrivalTime, burstTime, waitingTime, Process);
                printf("\n=====================================================================================\n\n");
                break;

            case 3:
                printf(">>>>Shortest Remaining Time Next (preemptive)<<<<\n");
                printf("Number of processes: %d\n", n);
                SRTN(n);
                printf("\n=====================================================================================\n\n");
                break;

            case 4:
                printf(">>>>Round Robin<<<<\n");
                printf("Number of processes: %d\n", n);
                RR(n);
                printf("\n=====================================================================================\n\n");
                break;

            default:
                printf("\n=====================================================================================\n\n");
                printf("Please enter a correct option!\n\n");
        }

        free(arrivalTime);
        free(burstTime);
        free(waitingTime);
        free(TATime);
        free(Process);
    }

    return 0;
}

void inputArrivalTime(int n, int *arrivalTime) {
    for (int i = 0; i < n; ++i)
        scanf("%d", (arrivalTime + i));
}

void inputBurstTime(int n, int *burstTime, int *p) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", (burstTime + i));
        p[i] = i + 1;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivalTime[i] > arrivalTime[j]) {
                swap(&p[i], &p[j]);
                swap(&arrivalTime[i], &arrivalTime[j]);
                swap(&burstTime[i], &burstTime[j]);
            }
        }
    }
}

float calculateAvgTATime(int *TATime, int n) {
    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += *(TATime + i);
    return sum / n;
}

float calculateAvgWaitingTime(int *WaitingTime, int n) {
    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += *(WaitingTime + i);
    return sum / n;
}

void sortingSJF(int n, int *at, int *bt, int *p) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            } else if (at[i] == at[j] && bt[i] > bt[j]) {
                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }
}

void insert(int n) {
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = n;
}

int delete() {
    int n = queue[front];
    front = front + 1;
    return n;
}

void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p) {
    float avgWaiting, avgTA;
    int *completionTime = malloc(n * sizeof(int));
    int temp;

    sortingFCFS(p, n, arrivalTime, burstTime);

    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++) {
        temp = 0;
        if (completionTime[i - 1] < arrivalTime[i]) {
            temp = arrivalTime[i] - completionTime[i - 1];
        }
        completionTime[i] = completionTime[i - 1] + burstTime[i] + temp;
    }

    printf("\nProcess\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurnAround Time\t\tWaiting Time");
    for (int i = 0; i < n; ++i) {
        *(TATime + i) = *(completionTime + i) - *(arrivalTime + i);
        *(waitingTime + i) = *(TATime + i) - *(burstTime + i);
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", *(p + i), *(arrivalTime + i), *(burstTime + i), *(completionTime + i), *(TATime + i), *(waitingTime + i));
    }

    avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    avgTA = calculateAvgTATime(TATime, n);

    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average TurnAround time is %.3f\n", avgTA);

    free(completionTime);
}

void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p) {
    float avgWaiting, avgTA;
    int *completionTime = malloc(n * sizeof(int));
    int pos;
    int min = 1000;

    sortingSJF(n, arrivalTime, burstTime, p);

    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arrivalTime[j] <= completionTime[i - 1]) {
                if (burstTime[j] < min) {
                    min = burstTime[j];
                    pos = j;
                }
            }
        }
        swap(&p[i], &p[pos]);
        swap(&arrivalTime[i], &arrivalTime[pos]);
        swap(&burstTime[i], &burstTime[pos]);
        min = 1000;
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    printf("\nProcess\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurnAround Time\t\tWaiting Time");
    for (int i = 0; i < n; ++i) {
        *(TATime + i) = *(completionTime + i) - *(arrivalTime + i);
        *(waitingTime + i) = *(TATime + i) - *(burstTime + i);
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", *(p + i), *(arrivalTime + i), *(burstTime + i), *(completionTime + i), *(TATime + i), *(waitingTime + i));
    }

    avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    avgTA = calculateAvgTATime(TATime, n);

    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average TurnAround time is %.3f\n", avgTA);

    free(completionTime);
}

void SRTN(int n) {
    int *at = malloc(n * sizeof(int));
    int *bt = malloc(n * sizeof(int));
    int *p = malloc(n * sizeof(int));
    int *flag = malloc(n * sizeof(int));
    int *RemainingTime = malloc(n * sizeof(int));
    int *CompletionTime = malloc(n * sizeof(int));
    int *waitingTime = malloc(n * sizeof(int));
    int *TATime = malloc(n * sizeof(int));
    int count = 0, short_p;
    int time, sum_wait = 0, sum_turnaround = 0;
    float avgWait, avgTurnaround;
    int min;

    for (int i = 0; i < n; i++) {
        printf("Process[%d]\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        RemainingTime[i] = bt[i];
        p[i] = i + 1;
        flag[i] = 0;
    }

    RemainingTime[9] = 9999;
    for (time = 0; count != n; time++) {
        min = 9;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && RemainingTime[i] < RemainingTime[min] && RemainingTime[i] > 0) {
                min = i;
            }
        }
        RemainingTime[min]--;
        if (RemainingTime[min] == 0) {
            count++;
            CompletionTime[min] = time + 1;
            sum_wait += CompletionTime[min] - bt[min] - at[min];
            waitingTime[min] = CompletionTime[min] - bt[min] - at[min];
            sum_turnaround += CompletionTime[min] - at[min];
            TATime[min] = CompletionTime[min] - at[min];
        }
    }

    avgWait = (float)sum_wait / n;
    avgTurnaround = (float)sum_turnaround / n;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], CompletionTime[i], TATime[i], waitingTime[i]);
    }

    printf("Average waiting time = %.3f\n", avgWait);
    printf("Average turnaround time = %.3f\n", avgTurnaround);

    free(at);
    free(bt);
    free(p);
    free(flag);
    free(RemainingTime);
    free(CompletionTime);
    free(waitingTime);
    free(TATime);
}

void RR(int n) {
    int *at = malloc(n * sizeof(int));
    int *bt = malloc(n * sizeof(int));
    int *p = malloc(n * sizeof(int));
    int *RemainingTime = malloc(n * sizeof(int));
    int *CompletionTime = malloc(n * sizeof(int));
    int *waitingTime = malloc(n * sizeof(int));
    int *TATime = malloc(n * sizeof(int));
    int Quantum, sum_wait = 0, sum_turnaround = 0;
    int time, flag = 0;
    float avgWait, avgTurnaround;

    for (int i = 0; i < n; i++) {
        printf("Process[%d]\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        RemainingTime[i] = bt[i];
        p[i] = i + 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &Quantum);

    for (time = 0, flag = 0; time < Quantum; flag++) {
        if (flag == n)
            flag = 0;
        if (RemainingTime[flag] > 0) {
            if (RemainingTime[flag] > Quantum) {
                time += Quantum;
                RemainingTime[flag] -= Quantum;
            } else {
                time += RemainingTime[flag];
                RemainingTime[flag] = 0;
                CompletionTime[flag] = time;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        TATime[i] = CompletionTime[i] - at[i];
        waitingTime[i] = TATime[i] - bt[i];
        sum_wait += waitingTime[i];
        sum_turnaround += TATime[i];
    }

    avgWait = (float)sum_wait / n;
    avgTurnaround = (float)sum_turnaround / n;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], CompletionTime[i], TATime[i], waitingTime[i]);
    }

    printf("Average waiting time = %.3f\n", avgWait);
    printf("Average turnaround time = %.3f\n", avgTurnaround);

    free(at);
    free(bt);
    free(p);
    free(RemainingTime);
    free(CompletionTime);
    free(waitingTime);
    free(TATime);
}
