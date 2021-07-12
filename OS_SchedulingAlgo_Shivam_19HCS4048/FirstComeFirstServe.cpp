// First Come First Serve CPU Scheduling

#include <iostream>
 
using namespace std;

// A class to represent the information about a process
class Process
{
    int processNo;
    int burstTime;
    int arrivalTime;
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

    // Accessor function to access arrival time
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

    // Function prototype to calculate waiting time
    friend void calculateWaitingTime(Process array[], int no, float& avgWT);

    // Function prototype to calculate turn around time
    friend void calculateTurnAroundTime(Process array[], int no);
};

// Sorting object according to arrival time
void bubbleSort(Process array[], int no)
{
	for(int index = 0; index < no - 1; index++)
	    for(int key = 0; key < no - index - 1; key++)
	        if(array[key].getArrivalTime() > array[key + 1].getArrivalTime())
                swap(array[key], array[key + 1]);
}

// Function to calculate waiting time
void calculateWaitingTime(Process array[], int no, float& avgWT)
{
    int* temp = new int[no];
    temp[0] = 0;

    array[0].waitingTime = 0;

    for(int index = 1; index < no; ++index)
    {
        temp[index] = temp[index - 1] + array[index - 1].burstTime;
        array[index].waitingTime = temp[index] - array[index].arrivalTime;

        // Handling CPU Idle situation
        if(array[index].waitingTime < 0)
        {
            temp[index] += (-array[index].waitingTime);
            array[index].waitingTime = 0;
        }

        avgWT += array[index].waitingTime;
    }

    avgWT /= no;

    delete[] temp;
}

// Function to calculate Turn Around Time
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
        cout << "Enter information..." << endl;
        processes[index].takeInformation();
        system("cls");
    }

    // Calling functions to sort and calculate waiting time and turnaround time
    bubbleSort(processes, noOfProcess);
    calculateWaitingTime(processes, noOfProcess, averageWaitingTime);
    calculateTurnAroundTime(processes, noOfProcess);

    for(int index = 0; index < noOfProcess; ++index)
        processes[index].printInformation();

    cout << "\nAverage Waiting Time: " << averageWaitingTime;

    return 0;
}