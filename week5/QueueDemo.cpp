#include "Queue.hpp"
#include "Stack.hpp"
#include "Customer.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <time.h>

using namespace std;

void printMenu();
bool isPalindrome(string s);
void queueDemo();
void palindromeDemo();
void customerDemo();

int main()
{
    bool end = false;
    int option;

    while (!end)
    {
        printMenu();
        cout << "Option: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 0:
            end = true;
            break;

        case 1:
            queueDemo();
            break;

        case 2:
            palindromeDemo();
            break;

        case 3:
            customerDemo();
            break;

        default:
            cout << option << " is invalid\n"
                 << endl;
            break;
        }
    }
    return 0;
}

void printMenu()
{
    cout << "\n\n[1] Char\n[2] Palindrome\n[3] Customer\n[0] Quit" << endl;
}

bool isPalindrome(string str)
{
    if (str == "")
    {
        return false;
    }

    Queue<char> q;
    Stack<char> s;
    char qTemp, sTemp;

    for (int i = 0, j = str.length(); i < j; i++)
    {
        q.enqueue(str[i]);
        s.push(str[i]);
    }

    while (!q.isEmpty())
    {
        q.dequeue(qTemp);
        s.pop(sTemp);
        if (qTemp != sTemp)
        {
            return false;
        }
    }
    return true;
}

void queueDemo()
{
    Queue<char> q;
    char temp;

    q.enqueue('a');
    q.enqueue('b');
    q.getFront(temp);

    cout << temp << endl;

    q.displayItems();
    q.dequeue();
    q.displayItems();
}

void palindromeDemo()
{
    string input;

    cout << "Input: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    if (isPalindrome(input))
    {
        cout << input << " is a palindrome" << endl;
    }
    else
    {
        cout << input << " is not a palindrome" << endl;
    }
}

void customerDemo()
{
    Queue<Customer *> q;
    int option, served = 0, servedTime = 0, timeSpan = 0, count = 1, limit = 10;

    srand(time(0));

    while (timeSpan < limit)
    {
        timeSpan++;
        cout << "TIME ELAPSED (min): " << timeSpan << endl;
        if (!q.isEmpty())
        {
            Customer *c;
            q.dequeue(c);
            cout << "[DEQUEUE] " << c->getName() << " served in " << timeSpan - c->getQueueNum() << " min(s)" << endl;
            served++;
            servedTime += timeSpan - c->getQueueNum();
        }

        int i = rand() % 3;
        if (option == 0 || option == 3)
        {
            cout << "No customer added to queue" << endl;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                Customer *c = new Customer("Customer " + to_string(count++), timeSpan);
                q.enqueue(c);
                cout << "[ENQUEUE] " << c->getName() << endl;
            }
        }
        cout << "\n\n";
    }
    cout << "Served Time: " << servedTime << "\nServed: " << served << endl;
    cout << "Time elapsed = " << timeSpan << "min(s), Average time to be served = " << float(servedTime) / served << " min(s)" << endl;
}
