#include <iostream>
#include <memory>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "Object Created" << endl;
    }

    ~Student()
    {
        cout << "Object Destroyed" << endl;
    }

    void display()
    {
        cout << "Student Information" << endl;
    }
};

int main()
{
    unique_ptr<Student> ptr = make_unique<Student>();

    ptr->display();

    return 0;
}
