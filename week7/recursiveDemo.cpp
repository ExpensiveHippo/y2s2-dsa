#include <iostream>

long power(int a, int n);
void printBackward(int array[], int n);
int maxArray(int array[], int start, int end);

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 23, 523, 231, -123, 42, 123523};
    std::cout << power(2, -4) << std::endl;
    printBackward(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << maxArray(arr2, 0, sizeof(arr2) / sizeof(arr2[0]) - 1) << std::endl;
}

// Calculates the value of a given integer raised to the power of a second integer
// param a – the base integer (to be raised to a power).
// param n – the power
// pre: a > 0, n > 0
// post: return the value of a raised to the nth power.

long power(int a, int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 1;
    }
    return a * power(a, n - 1);
}

// print the numbers in an array in the backward manner
// param array – the array in concern
// param n – number of elements in the array

void printBackward(int array[], int n)
{
    if (n == 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << array[n - 1];
    printBackward(array, n - 1);
}

// return the maximum value in an array of integers
// param array – the array in concern
// param start – start index of the array
// param end   – last index of the array

int maxArray(int array[], int start, int end)
{
    if (start == end)
    {
        return array[start];
    }

    int maxLeft = maxArray(array, start, start + (end - start) / 2);
    int maxRight = maxArray(array, start + (end - start) / 2 + 1, end);
    if (maxRight > maxLeft)
    {
        return maxRight;
    }
    return maxLeft;
};