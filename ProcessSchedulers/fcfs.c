#include <stdio.h>
#include <stdlib.h>

// only stack variables in struct, no heap variables
typedef struct process {
    int processId;
    int burstTime;
    int waitingTime;         
    int turnaroundTime;    
} Process;

void inputProcessDetails(Process* processes, int n) {
    int waitingTime = 0;
    for(int i = 0; i < n; i++) {
        processes[i].processId = i;
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].waitingTime = waitingTime;
        processes[i].turnaroundTime = processes[i].burstTime + waitingTime;
        // Increase waitingTime for next process
        waitingTime += processes[i].burstTime;
    }
}

void calculateAverageTime(Process* processes, int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    for(int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    printf("Average waiting time: %f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time: %f\n", (float)totalTurnaroundTime / n);
}
// Sole purpose is to learn algorithms so no error testing is done
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));    
    inputProcessDetails(processes, n);
    calculateAverageTime(processes, n);
}