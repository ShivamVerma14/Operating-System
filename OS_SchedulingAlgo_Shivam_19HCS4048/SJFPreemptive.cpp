// SJF scheduling algorithm with preemptive scheduling

#include <iostream>

using namespace std;

class Process
{
    private:
        int processNo;
        int arrivalTime;
        int burstTime;
        int waitingTime;
        int turnAroundTime;

    public:

        // Default Constructor
        Process()
        {
            processNo = 0;
            arrivalTime = 0;
            burstTime = 0;
            waitingTime = 0;
            turnAroundTime = 0;
        }

        // Function to take information
        void takeInformation()
        {
            cout << "Process No.: ";
            cin >> processNo;
            cout << "Burst Time: ";
            cin >> burstTime;
            cout << "Arrival Time: ";
            cin >> arrivalTime;
        }

        // Function to print all information
        void printInformation()
        {
            cout << "P[" << processNo << "] --> BT: " << burstTime << "  AT: " << arrivalTime << "  TAT: " << turnAroundTime << "  WT: " << waitingTime << endl;
        }

        // Function prototype to find waiting time
        friend void calculateWaitingTime(Process array[], int no, float& avgWT);

        // Function prototype to find turn around time
        friend void calculateTurnAroundTime(Process array[], int no);
};

// Function definition to calculate waiting time
void calculateWaitingTime(Process array[], int no, float& avgWT)
{
    int* remainingTime = new int[no];

    // Copying burst time into remaining time
    for(int index = 0; index < no; ++index)
        remainingTime[index] = array[index].burstTime;

    int complete = 0,  time = 0, minBurstTime = INT8_MAX, shortest = 0, finishTime;
    bool check = false;

    // Processing all the processes
    while(complete != no)
    {
        // Finding the process with shortest remaining time
        for(int index = 0; index < no; ++index)
            if((array[index].arrivalTime <= time) && (remainingTime[index] < minBurstTime) && (remainingTime[index] > 0))
            {
                minBurstTime = remainingTime[index];
                shortest = index;
                check = true;
            }
        
        if(check == false)
        {
            time++;
            continue;
        }

        // Updating remaining time with every unit time
        remainingTime[shortest]--;
        minBurstTime = remainingTime[shortest];
        if(minBurstTime == 0)
            minBurstTime = INT8_MAX;

        // When a process is completed
        if(remainingTime[shortest] == 0)
        {
            complete++;
            check = false;

            finishTime = time + 1;

            // waiting time = finish time - burst time - arrival time
            array[shortest].waitingTime = finishTime - array[shortest].burstTime - array[shortest].arrivalTime;
            if(array[shortest].waitingTime < 0)
                array[shortest].waitingTime = 0;
        }

        time++;
    }

    for(int index = 0; index < no; ++index)
        avgWT += array[index].waitingTime;

    avgWT /= no;
}

// Function definition to calculate turn around time
void calculateTurnAroundTime(Process array[], int no)
{
    for(int index = 0; index < no; ++index) 
        array[index].turnAroundTime = array[index].burstTime + array[index].waitingTime;
}

int main()
{
    int noOfProcess;
    float averageWaitingTime = 0.0;

    cout << "Enter the number of processes: ";
    cin >> noOfProcess;

    Process* processes = new Process[noOfProcess];

    // Taking information in objects
    for(int index = 0; index < noOfProcess; ++index)
    {
        system("cls");
        cout << "Enter information..." << endl;
        processes[index].takeInformation();
    }
    system("cls");

    // Function calls to calculate waiting time and turn around time
    calculateWaitingTime(processes, noOfProcess, averageWaitingTime);
    calculateTurnAroundTime(processes, noOfProcess);

    // Printing information
    for(int index = 0; index < noOfProcess; ++index)
        processes[index].printInformation();

    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    return 0;
}