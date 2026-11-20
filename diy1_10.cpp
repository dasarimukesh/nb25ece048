#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("nums.txt");

    int num, count = 0, sum = 0;
    int min, max;

    fin >> num;
    min = max = num;

    count++;
    sum += num;

    while(fin >> num)
    {
        count++;
        sum += num;

        if(num < min)
            min = num;

        if(num > max)
            max = num;
    }

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;
    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;

    fin.close();
    return 0;
}