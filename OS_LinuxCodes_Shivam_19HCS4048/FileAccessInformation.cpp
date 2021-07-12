/* File Access Information
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

void fileInfo()
{
    string fileName, command;
    
    cout << "Enter the File Name to get its information: ";
    cin >> fileName;

    command = "ls -l " + fileName + " >/tmp/FileInfo.txt";

    int value = system(command.c_str());

    if(value == 0)
    {
        ifstream file;
        file.open("/tmp/FileInfo.txt");

        string data[9];

        int index = 0;
        while(!(file.eof()))
            file >> data[index++];

        system("clear");

        cout << "**** " << fileName << " ****\n\n\n";
        cout << "Date of Last Access/Modification: " << data[5] << " " << data[6] << "\n";
        cout << "Time of Last Access/Modification: " << data[7] << "\n\n";

        cout << "Owner Permission...\n";
        if(data[0][1] == 'r')
            cout << "Read\n";
        if(data[0][2] == 'w')
            cout << "Write\n";
        if(data[0][3] == 'x')
            cout << "Execute\n";
        cout << "\n";

        cout << "Group Permission...\n";
        if(data[0][4] == 'r')
            cout << "Read\n";
        if(data[0][5] == 'w')
            cout << "Write\n";
        if(data[0][6] == 'x')
            cout << "Execute\n";
        cout << "\n";

        cout << "Others Permission...\n";
        if(data[0][7] == 'r')
            cout << "Read\n";
        if(data[0][8] == 'w')
            cout << "Write\n";
        if(data[0][9] == 'x')
            cout << "Execute\n";
        cout << "\n";
    }
    else
    {
        cout << "Error in system call!!!\n";
    }
}

int main()
{
    fileInfo();
    return 0;
}