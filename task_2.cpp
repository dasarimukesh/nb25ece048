#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Student {
public:
    int roll;
    string name;
    virtual void display() = 0;
};

class Result : public Student {
    int marks;
public:
    Result(int r, string n, int m) {
        roll = r; name = n; marks = m;
    }

    void display() override {
        cout << roll << " " << name << " "
             << marks << " ";
        cout << (marks >= 40 ? "Pass" : "Fail") << endl;
    }

    int getMarks() { return marks; }
};

int main() {
    vector<Result> students;
    int n, r, m;
    string name;

    cout << "Enter number of students: ";
    cin >> n;

    try {
        for (int i = 0; i < n; i++) {
            cout << "Enter roll, name and marks: ";
            cin >> r >> name >> m;

            if (m < 0 || m > 100)
                throw "Invalid Marks!";

            students.emplace_back(r, name, m);
        }

        ofstream file("result.txt");
        for (auto &s : students) {
            s.display();
        }
        file.close();

        sort(students.begin(), students.end(),
             [](Result a, Result b) {
                 return a.getMarks() > b.getMarks();
             });

        cout << "\nSorted Results:\n";
        for (auto &s : students)
            s.display();

    }
    catch (const char* e) {
        cout << e;
    }

    return 0;
}