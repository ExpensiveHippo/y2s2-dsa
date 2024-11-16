#include <iostream>

using namespace std;

void changeValue(int x, int *y);

int main()
{
    int x = 30;
    int y;
    y = x;

    changeValue(x, &y);

    // x = 30, y = 40.
    // No changes were made to x as it was passed by value.
    // Changes were made to Y as it was passed by reference.
    cout << "x: " << x << "\ny: " << y << endl;
    return 0;
}

void changeValue(int x, int *y)
{
    x += 10;
    *y += 10;
}