#include <iostream>
using namespace std;

void swapRef(int &a, int &b) { int t=a; a=b; b=t;}
void swapPtr(int *a, int *b) { int t=*a; *a=*b; *b=t; } 
int main() {
    int x=10, y=20;
    swapRef(x,y);

cout<<"After swapRef: x=" << x << "y= " <<y<<endl;g++

    swapPtr(&x,&y);
    cout<<"After swapPtr: x=" <<x<< "y=" <<y<< endl;
    int &alis = x;
    alis=99;
    cout<<"x via alis= "<<x<<endl;
    return 0;
}


