/* Calculating sum of n numbers using Thread
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <sys/wait.h>
#include <pthread.h>

using namespace std;

int size;

void* sum(void* numbers)
{
    int sum = 0;
    int* array = (int*) numbers;

    for(int index = 0; index < ::size; ++index)
        sum += array[index];

    cout << "Sum:: " << sum;
    cout << endl;
}

int main()
{
    int *array;
    pthread_t thread;

    cout << "Enter the total number of digits to add: ";
    cin >> ::size;

    array = new int[::size];

    cout << "Enter the numbers to add...\n";
    for(int index = 0; index < ::size; ++index)
        cin >> array[index];

    pthread_create(&thread, NULL, sum, array);
    wait(NULL);
    pthread_exit(NULL);
}