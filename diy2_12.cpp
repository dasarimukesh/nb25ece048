#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;

    int arr[] = {25, 40, 15, 60, 10, 80, 50};

    for(int i = 0; i < 7; i++)
    {
        pq.push(arr[i]);
    }

    cout << "Top 3 Largest Numbers:\n";

    for(int i = 0; i < 3; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}