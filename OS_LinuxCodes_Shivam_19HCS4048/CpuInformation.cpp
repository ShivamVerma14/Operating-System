/* Prints CPU Information
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <fstream>
#include <iostream>

using namespace std;

void cpuInfo()
{
    system("uname -r >/tmp/info.txt");
    system("lscpu|head -4 >>/tmp/info.txt");
    system("lscpu|grep name >>/tmp/info.txt");
    system("lscpu|grep MHz >>/tmp/info.txt");

    ifstream file;

    file.open("/tmp/info.txt");

    string data = "Kernel Version: \t", temp;
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
    cpuInfo();

    return 0;
}