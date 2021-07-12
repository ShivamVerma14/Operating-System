/* Copy File using System Call
Name: Shivam Verma
Course: B.Sc. (H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()
{
    string source_file, target_file;
    int s_file, t_file, n;
    char buffer[50];

    try
    {
        cout << "Enter the name of Source File: ";
        cin >> source_file;

        cout << "Enter the name of Target File: ";
        cin >> target_file;

        s_file = open(source_file.c_str(), O_RDONLY);
        t_file = open(target_file.c_str(), O_CREAT | O_WRONLY);

        if(s_file == -1)
            throw "Error opening in Source File.";
        if(t_file == -1)
            throw "Error opening in Target File.";

        while((n = read(s_file, buffer, 50)) > 0)
            write(t_file, buffer, n);

        write(t_file, "\0", 1);

        if(n < 0)
            throw "Can't read the content of the Source File.";

        close(s_file);
        close(t_file);

        cout << "File has been successfully copied.\n";
    }
    catch(const char* exception)
    {
        cerr << exception << '\n';
    }

    return 0;
}