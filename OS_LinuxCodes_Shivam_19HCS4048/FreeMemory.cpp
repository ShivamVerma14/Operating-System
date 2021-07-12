/* A program to print memory information
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <fstream>

using namespace std;

void MemoryInfo()
{
    system("free -m >/tmp/memoryInfo.txt");

    ifstream file;
    file.open("/tmp/memoryInfo.txt");

    string data, temp;

    while(!(file.eof()))
    {
        getline(file, temp);
        data += temp + '\n'; 
    }

    cout << data << endl;

    file.close();
}

int main()
{
    MemoryInfo();

    return 0;
}