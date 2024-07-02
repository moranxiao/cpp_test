#include <iostream>

class Rectangle{
    friend double getPerimeter(const Rectangle& rect);  
    friend double getArea(const Rectangle& rect);  
public:
    Rectangle(double lx,double ly,double rx,double ry)
    :_left_x(lx),
    _left_y(ly),
    _right_x(rx),
    _right_y(ry)
    {}
    
private:
    double _left_x;
    double _left_y;
    double _right_x;
    double _right_y;
};

double getArea(const Rectangle& rect)
{
    return (rect._right_x-rect._left_x)*(rect._right_y-rect._left_y);
}

double getPerimeter(const Rectangle& rect)
{
    return (rect._right_x-rect._left_x)*2+(rect._right_y-rect._left_y)*2;
}

using namespace std;
int main()
{
    Rectangle rect(0,0,5,5);
    cout << "Area:" << getArea(rect) << "  Perimeter:" << getPerimeter(rect);
    return 0;
}