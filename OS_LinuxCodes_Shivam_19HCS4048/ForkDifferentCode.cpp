/* Parent and Child Process executes different code
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int value = fork();

    if(value == 0)
    {
        cout << "Child Process will execute this statement.\n";
        cout << "Child Process ID: " << getpid() << '\n';
    }

    else if(value > 0)
    {
        cout << "Parent Process will execute this statement.\n";
        cout << "Parent Process ID: " << getpid() << '\n';
    }

    else
        cout << "Fork has failed!!!";
    
    return 0;
}