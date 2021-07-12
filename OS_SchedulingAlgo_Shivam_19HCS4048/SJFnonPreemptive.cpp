// SJF scheduling algorithm for non-preemptive scheduling

#include <iostream>

using namespace std;

// A class to represent all the information about processes
class Process
{
    private:
        int processNo;
        int burstTime;
        int arrivalTime;
        int waitingTime;
        int turnAroundTime;
        int completionTime;

    public:

        // Default Constructor
        Process()
        {
            processNo = 0;
            arrivalTime = 0;
            burstTime = 0;
            waitingTime = 0;
            turnAroundTime = 0;
            completionTime = 0;
        }

        // Accessor function for arrival time
        int getArrivalTime() const
        {
            return arrivalTime;
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

        // Function prototype for method to schedule SJF
        friend void determineSJF(Process array[], int no);

        // Function to calculate average waiting time
        friend void calculateAvgWT(Process array[], int no, float& avgWT);
};

// Sorting object according to arrival time
void sortArrivalTime(Process array[], int no)
{
	for(int index = 0; index < no - 1; index++)
	    for(int key = 0; key < no - index - 1; key++)
	        if(array[key].getArrivalTime() > array[key + 1].getArrivalTime())
                swap(array[key], array[key + 1]);
}

// Determining SJF and swapping array of process according to burst time 
void determineSJF(Process array[], int no)
{
    int temp, lowerBurstTimeIndex;

    array[0].completionTime = array[0].arrivalTime + array[0].burstTime;
    array[0].turnAroundTime = array[0].completionTime - array[0].arrivalTime;
    array[0].waitingTime = array[0].turnAroundTime - array[0].burstTime;

    for(int index = 1; index < no; ++index)
    {
        temp = array[index - 1].completionTime;
        int lowerBurstTime = array[index].burstTime;

        for(int j = index; j < no; ++j)
        {
            if(temp >= array[j].arrivalTime && lowerBurstTime >= array[j].burstTime)
            {
                lowerBurstTime = array[j].burstTime;
                lowerBurstTimeIndex = j;
            }
        }

        array[lowerBurstTimeIndex].completionTime = temp + array[lowerBurstTimeIndex].burstTime;
        array[lowerBurstTimeIndex].turnAroundTime = array[lowerBurstTimeIndex].completionTime - array[lowerBurstTimeIndex].arrivalTime;
        array[lowerBurstTimeIndex].waitingTime = array[lowerBurstTimeIndex].turnAroundTime - array[lowerBurstTimeIndex].burstTime;

        swap(array[lowerBurstTimeIndex], array[index]);
    }
}

// Function definition to calculate average waiting time
void calculateAvgWT(Process array[], int no, float& avgWT)
{
    for(int index = 0; index < no; ++index)
        avgWT += array[index].waitingTime;

    avgWT /= no;
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
        cout << "Enter information..." << endl;
        processes[index].takeInformation();
        system("cls");
    }

    // Calling functions to sort and calculate waiting time and turnaround time
    sortArrivalTime(processes, noOfProcess);
    determineSJF(processes, noOfProcess);
    calculateAvgWT(processes, noOfProcess, averageWaitingTime);

    for(int index = 0; index < noOfProcess; ++index)
        processes[index].printInformation();

    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    return 0;
}