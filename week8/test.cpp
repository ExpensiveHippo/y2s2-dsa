#include <iostream>

int search(int dataArray[], int arraySize, int target);
int search(int dataArray[], int arraySize, int start, int target);
int binarySearch(int dataArray[], int arraySize, int target);
int binarySearch(int dataArray[], int first, int last, int target);

int main()
{
    const int SIZE = 1000;
    int dataArray[SIZE];
    int target;
    int index;

    for (int i = 0; i < SIZE; i++)
    {
        dataArray[i] = (i + 1) * 2;
    }

    std::cout << "Enter number to search: ";
    std::cin >> target;

    // sequential(target, comparisons): (1, 1), (2, 1), (99, 50), (100, 50), (999, 500), (1000, 500), (1999, 1000), (2000,1000)
    // binary(target, comparisons): (1, 9), (2, 9), (99, 10), (100, 8), (999, 10), (1000, 1), (1999, 10), (2000, 10)

    // index = search(dataArray, SIZE, target);
    // index = binarySearch(dataArray, SIZE, target);
    // index = search(dataArray, SIZE, 0, target);
    index = binarySearch(dataArray, 0, SIZE - 1, target);

    if (index == -1)
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
        std::cout << "Found" << std::endl;
    }
}

int search(int dataArray[], int arraySize, int target)
{
    int i = 0;
    for (; i < arraySize; i++)
    {
        if (dataArray[i] == target)
        {
            std::cout << "Sequential Search: " << i + 1 << std::endl;
            return i;
        }

        if (dataArray[i] > target)
        {
            std::cout << "Sequential Search: " << i + 1 << std::endl;
            return -1;
        }
    }
    std::cout << "Sequential Search: " << i << std::endl;
    return -1;
}

int search(int dataArray[], int arraySize, int start, int target)
{
    if (start > arraySize || dataArray[start] > target)
    {
        return -1;
    }

    if (dataArray[start] == target)
    {
        return start;
    }

    search(dataArray, arraySize, start + 1, target);
}

int binarySearch(int dataArray[], int arraySize, int target)
{
    int comparisons = 0;
    int start = 0;
    int end = arraySize - 1;

    while (start <= end)
    {
        comparisons++;
        int mid = (start + end) / 2;
        if (dataArray[mid] == target)
        {
            std::cout << "Binary Search: " << comparisons << std::endl;
            return mid;
        }

        if (target < dataArray[mid])
        {
            // in first half
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    std::cout << "Binary Search: " << comparisons << std::endl;
    return -1;
}

int binarySearch(int dataArray[], int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (dataArray[mid] == target)
    {
        return mid;
    }

    if (dataArray[mid] < target)
    {
        binarySearch(dataArray, mid + 1, end, target);
    }
    else
    {
        binarySearch(dataArray, start, mid - 1, target);
    }
}