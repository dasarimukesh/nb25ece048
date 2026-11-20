#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Triangle" << endl;
    }
};

int main()
{
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>());
    shapes.push_back(make_unique<Rectangle>());
    shapes.push_back(make_unique<Triangle>());

    for(auto &s : shapes)
    {
        s->draw();
    }

    return 0;
}