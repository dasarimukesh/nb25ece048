#include <iostream>
using namespace std;

template <class T>
class Queue
{
    T arr[10];
    int front1, rear;

public:
    Queue()
    {
        front1 = 0;
        rear = -1;
    }

    void enqueue(T value)
    {
        arr[++rear] = value;
    }

    void dequeue()
    {
        if(front1 <= rear)
            front1++;
    }

    T front()
    {
        return arr[front1];
    }
};

int main()
{
    Queue<string> q;

    q.enqueue("Kavya");
    q.enqueue("Anu");
    q.enqueue("Riya");

    cout << "Front Element: " << q.front() << endl;

    q.dequeue();

    cout << "Front Element After Dequeue: "
         << q.front() << endl;

    return 0;
}
