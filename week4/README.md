# Week 4 (Stacks)

## Question 1
1. Implement the operations of the Stack ADT 

	Note : You should implement (and test) one operation at a time.

<br>

2.	Write a sample program, StackDemo.cpp, to do the following:
    1. Create an empty stack, s

    2.	  Push ‘3’ on top of the stack

    3.	  Push ‘4’ on top of the stack

    4.	  Get top item of the stack and display

    5.	  Display all the items in the stack in order of insertion

    6.	  Pop top item from stack

    7.	  Display all the items in the stack in order of insertion

<br>

## Question 2
 
1.	Write a program to keep track of visited URLs in a web browser by implementing a back button. 
A skeleton program is given below:
```cpp
#include <iostream>
#include <string>
#include "Stack.h"
int main()
{
    Stack back_stack;
    string temp;
    while (temp != "0")
    {
        cout << "[1] Visit URL\n[2] Back\n[0] Exit\nYour Choice: ";
        cin >> temp;
        if (temp == "0")
            break;
    }
    return 0;
}
```



2.	Add a forward button functionality to the web browser program in Q4.  The forward button keeps a history of the URLs visited each time the back button is pressed.  This history is cleared when a new address is entered.

<br>

3. Test your program with the following series of actions:
    1. Enter a series of URLs (10, for example)
    2. Go back to some URLs (7, for example)
    3. Go forward a few, but not to the last (3, for example)
    4. Enter a new URL
    5. Check that the forward stack is empty by trying to go forward
    6. Go back a few URLs (2, for example)
