#include "Stack.hpp"

int main()
{
    Stack<int> s;
    int temp;

    s.push(3);
    s.push(4);
    s.getTop(temp);
    std::cout << temp << std::endl; // prints 4
    s.displayInOrderOfInsertion();  // prints 3 and 4
    s.pop();
    s.displayInOrderOfInsertion(); // prints 3

    return 0;
}
