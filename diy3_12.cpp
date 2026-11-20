#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    int product = accumulate(
        v.begin(),
        v.end(),
        1,
        [](int a, int b)
        {
            return a * b;
        });

    int evenSum = accumulate(
        v.begin(),
        v.end(),
        0,
        [](int sum, int num)
        {
            if(num % 2 == 0)
                return sum + num;
            return sum;
        });

    cout << "Product = " << product << endl;
    cout << "Sum of Even Numbers = " << evenSum << endl;

    return 0;
}