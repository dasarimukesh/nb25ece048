#include <iostream>
using namespace std;

class MathError
{
public:
    virtual const char* what()
    {
        return "General Math Error";
    }
};

class DivideByZero : public MathError
{
public:
    const char* what()
    {
        return "Divide By Zero Error";
    }
};

int main()
{
    try
    {
        throw DivideByZero();
    }
    catch(DivideByZero &e)
    {
        cout << e.what() << endl;
    }
    catch(MathError &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}