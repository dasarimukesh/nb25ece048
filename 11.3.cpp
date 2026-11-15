#include <iostream>
#include <string>
using namespace std;

// Class template with TWO independent type parameters
template <typename K, typename V>
struct Pair {
    K key;
    V value;

    void show() const {
        cout << key << "-> " << value << endl;
    }
};

// Function template with TWO type parameters
template <typename A, typename B>
auto bigger(A a, B b) {
    return (a > b) ? a : b;
}

int main() {

    // Create Pair object
    Pair<string, int> p;

    p.key = "Age";
    p.value = 20;

    p.show();

    // Function template with two types
    cout << "Bigger = " << bigger(10, 20.5) << endl;

    return 0;
}