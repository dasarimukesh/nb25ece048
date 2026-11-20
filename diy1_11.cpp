#include <iostream>
using namespace std;


template <typename T>
void swapVals(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <typename T>
T findMax(T arr[], int n)
{
    T max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    int a = 10, b = 20;
    swapVals(a, b);
    cout << "After swapping ints: " << a << " " << b << endl;

    double x = 5.5, y = 8.8;
    swapVals(x, y);
    cout << "After swapping doubles: " << x << " " << y << endl;

    int intArr[] = {12, 45, 7, 89, 34};
    cout << "Max int = " << findMax(intArr, 5) << endl;

    double doubleArr[] = {2.5, 8.7, 4.3, 9.1, 6.8};
    cout << "Max double = " << findMax(doubleArr, 5) << endl;

    return 0;
}