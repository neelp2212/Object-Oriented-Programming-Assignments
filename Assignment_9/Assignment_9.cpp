#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Point
{
private:
    double m_x;
    double m_y;

public:
    Point(double xcoord = 0.0, double ycoord = 0.0)
    {
        m_x = xcoord;
        m_y = ycoord;
    }
    virtual ~Point() {}
    virtual void input(const char *prompt)
    {
        cout << prompt << endl;
        cout << "Enter x:";
        cin >> m_x;
        cout << "Enter y:";
        cin >> m_y;
    }
    virtual void output() const
    {
        cout << "Coordinates: "
             << "(" << m_x << "," << m_y << ")" << endl;
        ;
    }
    virtual double area() const
    {
        return 0.0;
    }
};

class Circle : public Point
{
private:
    double radius;

public:
    Circle(double xcoord = 0.0, double ycoord = 0.0, double r = 0.0) : Point(xcoord, ycoord)
    {
        radius = r;
    }
    virtual ~Circle() {}
    void input(const char *prompt)
    {
        cout << prompt;
        Point::input("");
        cout << "Enter radius:";
        cin >> radius;
    }
    void output() const
    {
        cout << "Circle's area: " << area() << " ";
        Point::output();
    }
    double area() const
    {
        double pi = 3.14;
        return pi * radius * radius;
    }
};

class Square : public Point
{
private:
    double width;
    double height;

public:
    Square(double xcoord = 0.0, double ycoord = 0.0, double w = 0.0, double h = 0.0) : Point(xcoord, ycoord)
    {
        width = w,
        height = h;
    }
    virtual ~Square() {}
    void input(const char *prompt)
    {
        cout << prompt;
        Point::input("");
        cout << "Enter height:";
        cin >> height;
        cout << "Enter width:";
        cin >> width;
    }
    void output() const
    {
        cout << "Square's area: " << area() << " ";
        Point::output();
    }
    double area() const
    {
        return width * height;
    }
};

bool compareArea(shared_ptr<Point> p1, shared_ptr<Point> p2)
{
    return p1->area() < p2->area();
}

int main()
{
    vector<shared_ptr<Point>> shapes;
    shapes.push_back(make_shared<Point>(1.0, 1.0));
    shapes.push_back(make_shared<Circle>(2.0, 2.0, 2.0));
    shapes.push_back(make_shared<Square>(5.0, 5.0, 2.0, 2.0));

    Square sq;
    sq.input("Square:");
    shapes.push_back(make_shared<Square>(sq));

    Circle cl;
    cl.input("Circle:");
    shapes.push_back(make_shared<Circle>(cl));

    Point pt;
    pt.input("Point:");
    shapes.push_back(make_shared<Point>(pt));

    cout << endl
         << "Vector before sorting:" << endl;
    for (auto i : shapes)
    {
        i->output();
    }

    sort(shapes.begin(), shapes.end(), compareArea);
    cout << endl
         << "Sorted:" << endl;

    for (auto point : shapes)
    {
        point->output();
    }

    return 0;
}
