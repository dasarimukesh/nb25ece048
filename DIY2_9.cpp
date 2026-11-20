#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Overflow!";
    }
};

class Underflow : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Underflow!";
    }
};

class Stack
{
    int arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == 4)
            throw Overflow();

        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
    }

    void pop()
    {
        if (top == -1)
            throw Underflow();

        cout << arr[top--] << " popped from stack" << endl;
    }
};

int main()
{
    Stack s;

    try
    {
        s.pop();
    }
    catch (Underflow &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
    }
    catch (Overflow &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}