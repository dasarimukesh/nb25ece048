#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> freq;

    string words[] = {"apple", "banana", "apple",
                      "orange", "banana", "apple"};

    int n = 6;

    for(int i = 0; i < n; i++)
    {
        freq[words[i]]++;
    }

    cout << "Word Frequencies:" << endl;

    for(auto x : freq)
    {
        cout << x.first << " : "
             << x.second << endl;
    }

    string mostWord;
    int maxFreq = 0;

    for(auto x : freq)
    {
        if(x.second > maxFreq)
        {
            maxFreq = x.second;
            mostWord = x.first;
        }
    }

    cout << "\nMost Frequent Word: "
         << mostWord << endl;

    cout << "Frequency: "
         << maxFreq << endl;

    return 0;
}
