#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
    static int count;

public:
    
    Student() : rollNo(0), name("Unknown"), marks(0.0f) {
        count++;
    }

    
    Student(int r, string n, float m)
        : rollNo(r), name(n), marks(m) {
        count++;
    }

    
    Student(const Student& s)
        : rollNo(s.rollNo), name(s.name), marks(s.marks) {
        count++;
    }

    ~Student() {
        count--;
    }

    
    void setMarks(float m) {
        marks = m;
    }

    void setMarks(float m1, float m2, float m3) {
        marks = (m1 + m2 + m3) / 3.0f;
    }

    
    void display() const {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }

    void display(bool showMarks) const {
        cout << "Name: " << name;
        if (showMarks)
            cout << " | Marks: " << marks;
        cout << endl;
    }

    
    static int getCount() {
        return count;
    }

    
    friend void showMarksStatus(const Student& s);

    
    bool operator>(const Student& other) const {
        return marks > other.marks;
    }
};


int Student::count = 0;


void showMarksStatus(const Student& s) {
    cout << s.name << ": ";
    if (s.marks >= 40)
        cout << "PASS";
    else
        cout << "FAIL";
    cout << endl;
}

int main() {
    Student s1(101, "navya", 85.5f);
    Student s2(102, "jaya", 72.0f);
    Student s3;

    s3.setMarks(35.0f);

    cout << "--- Student Details ---" << endl;
    s1.display();
    s2.display();
    s3.display(true);

    cout << "\n--- Overloaded setMarks ---" << endl;
    s3.setMarks(60.0f, 70.0f, 80.0f);
    s3.display();

    cout << "\n--- Friend Function ---" << endl;
    showMarksStatus(s1);
    showMarksStatus(s3);

    cout << "\n--- Operator Overloading ---" << endl;
    cout << "\n--- Operator Overloading ---" << endl;

if (s1 > s2)
    cout << "navya has higher marks than jaya." << endl;
else
    cout << "jaya has higher or equal marks than navya." << endl;
    
    cout << (s1 > s2 ? "navya has higher marks than jaya"
                     : "jaya has higher or equal marks than navya")
         << endl;

    cout << "\n--- Copy Constructor ---" << endl;
    {
        Student s4(s1);
        cout << "Count after copying: " << Student::getCount() << endl;
    }
    cout << "Count after copied object is destroyed: "
         << Student::getCount() << endl;

    cout << "\n--- Dynamic Memory Allocation ---" << endl;
    Student* s5 = new Student(104, "nani", 90.0f);
    cout << "Count after new: " << Student::getCount() << endl;
    s5->display();
    delete s5;
    cout << "Count after delete: " << Student::getCount() << endl;

    return 0;
}