/* A program to implement execlp() 
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "Hiii\n";
    
    execlp("./HelloWorld.out", "", NULL);

    cout << "Ending!!!";

    return 0;
}