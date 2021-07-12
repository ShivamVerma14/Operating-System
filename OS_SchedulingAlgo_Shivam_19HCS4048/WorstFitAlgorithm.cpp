/* Program to implement Worst-Fit Algorithm
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

void worstFit(int* blockSize, int m, int* processSize, int n)
{
    int* allocation = new int[n];
    for(int i = 0; i < n; ++i)
        allocation[i] = -1;

    for(int i = 0; i < n; ++i)
    {
        int worstIndex = -1;
        for(int j = 0; j < m; ++j)
            if(blockSize[j] >= processSize[i])
            {
                if(worstIndex == -1)
                    worstIndex = j;
                else if(blockSize[worstIndex] < blockSize[j])
                    worstIndex = j;
            }

        if(worstIndex != -1)
        {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    cout << "\nProcess No. \tProcess Size \tBlock No\n";
    for(int i = 0; i < n; i++)
    {
        cout << "  " << i + 1 << "\t\t" << processSize[i] << "\t\t";
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
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);

    return 0;
}