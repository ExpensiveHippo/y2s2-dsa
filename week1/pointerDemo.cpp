#include <iostream>

int main()
{

    // 1).
    int value1 = 200'000;

    // 2).
    int value2;

    // 3).
    int *ptr = &value1;

    // 4).
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // 5).
    value2 = *ptr;

    // 6). The value of value2 is the same as the value pointed by ptr.
    std::cout << "Value of value2: " << value2 << std::endl;

    // 7).
    std::cout << "Address of value1: " << &value1 << std::endl;

    // 8). The value printed is the same as value1's address.
    std::cout << "Address stored in ptr: " << ptr << std::endl;

    // 9).
    ptr = &value2;

    // 10).
    *ptr += 2000;

    /*
    11).
    value2 is 202'000 while value1 is 200'000.
    value1 and value2 has separate addresses.
    Since ptr points to value2 after step j, the 2000 in step k was only added to value2.
    */
    std::cout << "\n(After Addition)\n"
              << "Value of value1: " << value1 << "\nValue of value2: " << value2 << std::endl;

    return 0;
}