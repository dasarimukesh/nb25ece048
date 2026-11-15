#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {

    vector<Student> v = {
        {"Asha", 88},
        {"Ravi", 95},
        {"Meera", 72}
    };

    // Sort in descending order
    sort(v.begin(), v.end(),
         [](const Student& a, const Student& b) {
             return a.marks > b.marks;
         });

    // Display students
    for (auto& s : v) {
        cout << s.name << " " << s.marks << endl;
    }

    // Count passed students
    int pass = count_if(v.begin(), v.end(),
                        [](const Student& s) {
                            return s.marks >= 75;
                        });

    cout << "Passed: " << pass << endl;

    // Calculate total marks
    int total = accumulate(v.begin(), v.end(), 0,
                           [](int sum, const Student& s) {
                               return sum + s.marks;
                           });

    cout << "Total: " << total << endl;

    return 0;
}