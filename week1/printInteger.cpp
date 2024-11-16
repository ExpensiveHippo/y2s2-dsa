#include <iostream>
#include <vector>

void printInteger(int num)
{
    std::vector<int> digits;

    // store each digit in vector
    while (num > 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    // iterate through vector and print separator
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        std::cout << digits[i];
        if (i > 0)
        {
            std::cout << "   ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int num;

    std::cout << "Enter 5 digit number: " << std::flush;
    std::cin >> num;

    printInteger(num);
    return 0;
}