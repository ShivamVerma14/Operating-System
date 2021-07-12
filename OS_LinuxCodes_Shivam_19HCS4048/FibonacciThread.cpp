// A program to demonstrate threading

#include <iostream>
#include <pthread.h>
#include <wait.h>

using namespace std;

int n;

void* fibonacci(void* arg)
{
    int c, first = 0, second = 1, next;
    for(c = 0; c < n; c++)
    {
        if(c <= 1)
            next = c;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << " "; 
    }

    cout << endl;
}

int main()
{
    pthread_t t;

    cout << "Enter the number of terms in Fibonacci Series: ";
    cin >> n;

    cout << "First " << n << " terms of Fibonacci Series are...\n";
    pthread_create(&t, NULL, fibonacci, NULL);

    wait(NULL);

    pthread_exit(NULL);

    return 0;
}