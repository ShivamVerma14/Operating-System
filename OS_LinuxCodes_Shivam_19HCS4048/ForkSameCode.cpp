/* Parent and Child Process executes same code
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    fork();

    cout << "Parent and Child Process executes same code!!!\n";
    return 0;
}