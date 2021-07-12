// First Come First Served CPU Scheduling without arrival time

#include <iostream>

using namespace std;

int main()
{
    int noOfProcess;
    float averageWaitingTime = 0.0;
    int *burstTime, *waitingTime, *turnAroundTime;

    // Getting number of processes
    cout << "Enter the number of processes: ";
    cin >> noOfProcess;

    burstTime = new int[noOfProcess];
    waitingTime = new int[noOfProcess];
    turnAroundTime = new int[noOfProcess];

    // Input of burst time of all processes
    cout << "Enter the Burst Time of all the processes..." << endl;
    for(int index = 0; index < noOfProcess; ++index)
    {
        cout << "P[" << index + 1 << "] : ";
        cin >> burstTime[index];
        cout << endl; 
    }
    
    // Calculating waiting time and its average for all the processes
    waitingTime[0] = 0;
    for(int index = 1; index < noOfProcess; ++index)
    {
        waitingTime[index] = waitingTime[index - 1] + burstTime[index - 1];
        averageWaitingTime += waitingTime[index];
    }
    averageWaitingTime /= noOfProcess;

    // Calculating turnaround time
    for(int index = 0; index < noOfProcess; ++index)
        turnAroundTime[index] = waitingTime[index] + burstTime[index];

    system("cls");
    
    // Showing information
    cout << "\nInformation...." << endl;
    for(int index = 0; index < noOfProcess; ++index)
        cout << "P[" << index + 1 << "] --> BT: " << burstTime[index] << "  TAT: " << turnAroundTime[index] << "  WT: " << waitingTime[index] << endl;
    
    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    delete[] burstTime, turnAroundTime, waitingTime;

    return 0;
}