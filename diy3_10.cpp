#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    string name;
    int marks;
};

int main()
{
    ofstream fout("students.txt");

    fout << "Kavya 90\n";
    fout << "Anu 85\n";
    fout << "Riya 95\n";

    fout.close();

    Student s[10];

    ifstream fin("students.txt");

    int n = 0;

    while(fin >> s[n].name >> s[n].marks)
    {
        n++;
    }

    fin.close();

    int topper = 0;

    for(int i = 1; i < n; i++)
    {
        if(s[i].marks > s[topper].marks)
            topper = i;
    }

    cout << "Topper: " << s[topper].name << endl;
    cout << "Marks : " << s[topper].marks << endl;

    return 0;
}