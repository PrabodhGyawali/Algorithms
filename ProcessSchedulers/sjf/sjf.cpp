#include "MinHeap.cpp"

struct Process {
    int processId;
    int burstTime;
    int waitingTime;         
    int turnaroundTime;    
};

void inputProcessDetails(Process* processes, int n) {
    int waitingTime = 0;
    for(int i = 0; i < n; i++) {
        (processes + i)->processId = i;     // Pointer Syntax
        cout << "Enter the burst time: ";
        cin >> processes[i].burstTime;
        processes[i].waitingTime = waitingTime;
        processes[i].turnaroundTime = processes[i].burstTime + waitingTime;
        // Increase waitingTime for next process
        waitingTime += processes[i].burstTime;
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process *processes = new Process[n];
    
    // Create a tree with burstTime as key
    MinHeap minHeap(n);
    for (int i = 0; i < n; i++) {
        minHeap.insertKey(processes[i].burstTime);
    }
    // Sort the processes based on burstTime
    for (int i = 0; i < n; i++) {
        processes[i].burstTime = minHeap.extractMin();
    }
    // Display Results
    return 1;
}