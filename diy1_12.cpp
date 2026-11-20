#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<string, int>> v;

    v.push_back({"Kavya", 85});
    v.push_back({"Anu", 92});
    v.push_back({"Riya", 78});
    v.push_back({"Pooja", 88});

    sort(v.begin(), v.end(),
         [](pair<string,int> a, pair<string,int> b)
         {
             return a.second < b.second;
         });

    cout << "Sorted Pairs:\n";

    for(auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}