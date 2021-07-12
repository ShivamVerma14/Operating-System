/* OS Practical code to implement first-fit allocation strategy
Name: Shivam Verma
Course: B.Sc. (H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;

// Function to allocate memory blocks for process using First-Fit strategy
void first_fit(int *blockSize, int m, int *processSize, int n)
{
    // Declaring an array to track which memory block has been for a particular process 
    int *allocation = new int[n];
    for(int i = 0; i < n; ++i)
        allocation[i] = -1;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            // Searching for efficient memory block which comes first
            if(blockSize[j] >= processSize[i])
            {
                // Updating the allocation array and the size of remaining block
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

    // Printing the results...
    cout << "\nProcess No. \tProcess Size \tBlock No.\n";
    for(int i = 0; i < n; i++)
    {
        cout << "  " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        // If the memory block has been allocated, then prints the memory block else prints 'Not Allocated'
        if(allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        
        cout << endl;        
    }

    delete[] allocation;
    
}

int main()
{
    // Initialising block size array
    int blockSize[] = {100, 500, 200, 300, 600};

    // Initialising process size array
    int processSize[] = {212, 417, 112, 426};

    // Calculating the size of the above arrays
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    // Calling the function to allocate the memory block
    first_fit(blockSize, m, processSize, n);

    return 0;
}