/* Implementation of Round Robin Scheduling 
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Sem 
Roll No.: 19HCS4048
*/

#include <iostream>
#include <queue>

using namespace std;

class Process
{
    private: 
        int processNo;
        int arrivalTime;
        int burstTime;
        int waitingTime;
        int turnAroundTime;
        int remainingTime;
        bool arrived;

    public:
        // A constructor
        Process() : processNo(0), arrivalTime(0), burstTime(0), arrived(false), waitingTime(0), turnAroundTime(0), remainingTime(0) {}

        // Takes the information about the process
        void takeInformation(int processNo)
        {
            this->processNo = processNo;
            cout << "Burst Time: ";
            cin >> burstTime;
            cout << "Arrival Time: ";
            cin >> arrivalTime;
            remainingTime = burstTime;
        }

        // Prints all information about the process
        void printInformation()
        {
            cout << "P[" << processNo << "] --> BT: " << burstTime << "  AT: " << arrivalTime << "  TAT: " << turnAroundTime << "  WT: " << waitingTime << endl;
        }

        // Schedules the processes and calculates the waiting and turn around time of all the process
        friend void schedule(Process[], int, int);

        // Adds new process in the ready queue
        friend void addProcess(Process[], int, int, queue<Process>&);

        // Returns the average waiting time of all processes
        friend void average(Process[], int, float&);
};

void schedule(Process array[], int no, int time)
{
    queue<Process> readyQueue;

    int completed = 0, currentTime = 0;
    addProcess(array, no, currentTime, readyQueue);

    while(completed != no)
    {
        if(readyQueue.empty())
        {
            currentTime++;
            continue;
        }
        int index = readyQueue.front().processNo - 1;
        readyQueue.pop();

        if(array[index].remainingTime <= time)
        {
            currentTime += array[index].remainingTime;
            array[index].remainingTime = 0;
            array[index].turnAroundTime = currentTime - array[index].arrivalTime;
            array[index].waitingTime = array[index].turnAroundTime - array[index].burstTime;

            completed++;
            addProcess(array, no, currentTime, readyQueue);
        }
        else
        {
            currentTime += time;
            array[index].remainingTime -= time;
            addProcess(array, no, currentTime, readyQueue);
            readyQueue.push(array[index]);
        }
    }
}

void addProcess(Process array[], int no, int cTime, queue<Process> &rqueue)
{
    for(int index = 0; index < no; ++index)
        if(array[index].arrived == false && array[index].arrivalTime <= cTime)
        {
            rqueue.push(array[index]);
            array[index].arrived = true;
        }
}

void average(Process array[], int no, float &avgWT)
{
    for(int index = 0; index < no; ++index)
        avgWT += array[index].waitingTime;

    avgWT /= no;
}

int main()
{
    int noOfProcess, timeQuantum;
    float averageWaitingTime;

    cout << "Enter the number of processes: ";
    cin >> noOfProcess;

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    Process *processes = new Process[noOfProcess];

    for(int index = 0; index < noOfProcess; ++index)
    {
        system("cls");
        cout << "****Process" << index + 1 << "****\n";
        processes[index].takeInformation(index + 1);
    }
    system("cls");

    schedule(processes, noOfProcess, timeQuantum);

    average(processes, noOfProcess, averageWaitingTime);

    for(int index = 0; index < noOfProcess; ++index)
        processes[index].printInformation();

    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    return 0;
}