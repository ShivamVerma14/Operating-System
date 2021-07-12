/* Implementation of Preemptive Priority Scheduling
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;

class Process
{
    private: 
        int processNo;
        int arrivalTime;
        int burstTime;
        int priority;
        int waitingTime;
        int turnAroundTime;
        int remainingTime;

    public:
        // A constructor
        Process() : processNo(0), arrivalTime(0), burstTime(0), priority(0), waitingTime(0), turnAroundTime(0), remainingTime(0) {}

        // Takes the information about the process
        void takeInformation(int processNo)
        {
            this->processNo = processNo;
            cout << "Burst Time: ";
            cin >> burstTime;
            cout << "Arrival Time: ";
            cin >> arrivalTime;
            cout << "Priority: ";
            cin >> priority;
            remainingTime = burstTime;
        }

        // Prints all information about the process
        void printInformation()
        {
            cout << "P[" << processNo << "] --> BT: " << burstTime << "  AT: " << arrivalTime << "  TAT: " << turnAroundTime << "  WT: " << waitingTime << " Priority: " << priority << endl;
        }

        // Schedules the processes and calculates the waiting and turn around time of all the process
        friend void schedule(Process[], int);

        // Returns the average waiting time of all processes
        friend void average(Process[], int, float&);
};

void schedule(Process array[], int no)
{
    int currentTime = 0, completed = 0;

    while(completed != no)
    {
        int maxPriority = INT8_MAX;
        int index = -1;

        for(int iterate = 0; iterate < no; ++iterate)
            if(array[iterate].arrivalTime <= currentTime && array[iterate].remainingTime != 0)
            {
                if(array[iterate].priority < maxPriority)
                {
                    maxPriority = array[iterate].priority;
                    index = iterate;
                }

                if(array[iterate].priority == maxPriority)
                    if(array[iterate].arrivalTime < array[index].arrivalTime)
                        index = iterate;
            }

        if(index != -1)
        {
            array[index].remainingTime--;
            currentTime++;

            if(array[index].remainingTime == 0)
            {
                completed++;

                array[index].turnAroundTime = currentTime - array[index].arrivalTime;
                array[index].waitingTime = array[index].turnAroundTime - array[index].burstTime;
            }
        }
        else
            currentTime++;
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
    int noOfProcess;
    float averageWaitingTime;

    cout << "Enter the number of process: ";
    cin >> noOfProcess;

    Process *processes = new Process[noOfProcess];

    for(int index = 0; index < noOfProcess; ++index)
    {
        system("cls");
        cout << "****Process" << index + 1 << "****\n";
        processes[index].takeInformation(index + 1);
    }
    system("cls");

    schedule(processes, noOfProcess);

    average(processes, noOfProcess, averageWaitingTime);

    for(int index = 0; index < noOfProcess; ++index)
        processes[index].printInformation();

    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    return 0;
}