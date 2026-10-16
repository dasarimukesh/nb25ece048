#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char *buf;

public:
    Text(const char *s = "") {
        buf = new char[strlen(s) + 1];
        strcpy(buf, s);
    }

    Text(const Text &o) {
        buf = new char[strlen(o.buf) + 1];
        strcpy(buf, o.buf);
    }

    Text& operator=(const Text &o) {
        if (this != &o) {
            char *temp = new char[strlen(o.buf) + 1];
            strcpy(temp, o.buf);

            delete[] buf;
            buf = temp;
        }

        return *this;
    }

    ~Text() {
        delete[] buf;
    }

    void show() const {
        cout << buf << endl;
    }
};

int main() {
    Text a("alpha"), b("beta");

    b = a;

    a.show();
    b.show();

    return 0;
}