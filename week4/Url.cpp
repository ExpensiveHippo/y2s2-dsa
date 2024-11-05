#include <string>
#include <limits>
#include "Stack.hpp"

using namespace std;

int main()
{
    bool end = false;

    Stack<string> history;
    Stack<string> forward;
    int choice;
    string currentUrl = "Home";
    string url;

    while (!end)
    {
        cout << "CURRENT URL: " << currentUrl << endl
             << endl;
        cout << "[1] Visit URL\n[2] Back\n[3] Forward\n[0] Exit\nYour Choice: " << flush;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter url: " << flush;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, url);
            cout << "\n\n";
            history.push(currentUrl);
            while (!forward.isEmpty())
            {
                forward.pop();
            }
            currentUrl = url;
            break;
        case 2:
            forward.push(currentUrl);
            history.pop(currentUrl);
            break;
        case 3:
            if (!forward.isEmpty())
            {
                history.push(currentUrl);
                forward.pop(currentUrl);
            }
            break;
        case 0:
            end = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
