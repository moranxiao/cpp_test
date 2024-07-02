#include <iostream>


using namespace std;

const double pi = 3.1415926;

class IAreaAndPerimeter
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
};

class Circle :public IAreaAndPerimeter
{
public:
	Circle(double r)
		:_r(r)
	{}
	virtual double GetArea()
	{
		return _r*_r * pi;
	}
	virtual double GetPerimeter()
	{
		return 2 * pi * _r;
	}
private:
	double _r;
};

class InscribedSquare : public IAreaAndPerimeter
{
public:
	InscribedSquare(double r)
		:_r(r)
	{}
	virtual double GetArea()
	{
		double l = (_r * 2) / sqrt(2.0);
		return l * l;
	}
	virtual double GetPerimeter()
	{
		return (_r * 2) / sqrt(2.0) * 4;
	}
private:
	double _r;
};

class CircumscribedSquare : public IAreaAndPerimeter
{
public:
	CircumscribedSquare(double r)
		:_r(r)
	{}
	virtual double GetArea()
	{
		return (2 * _r) * (2 * _r);
	}
	virtual double GetPerimeter()
	{
		return 2 * _r * 4;
	}
private:
	double _r;
};

double GetArea(IAreaAndPerimeter* p)
{
	return p->GetArea();
}

double GetPerimeter(IAreaAndPerimeter* p)
{
	return p->GetPerimeter();
}

int main()
{
	Circle cir(5.0);
	InscribedSquare insquare(5.0);
	CircumscribedSquare cirsquare(5.0);
	cout << "Circle Area:" << GetArea(&cir) << endl;
	cout << "Circle Perimeter:" << GetPerimeter(&cir) << endl;

	cout << "InscribedSquare Area:" << GetArea(&insquare) << endl;
	cout << "InscribedSquare Perimeter:" << GetPerimeter(&insquare) << endl;
	
	cout << "CircumscribedSquare Area:" << GetArea(&cirsquare) << endl;
	cout << "CircumscribedSquare Perimeter:" << GetPerimeter(&cirsquare) << endl;
	//Êä³ö£º
	//Circle Area : 78.5398
	//Circle Perimeter : 31.4159
	//InscribedSquare Area : 50
	//InscribedSquare Perimeter : 28.2843
	//CircumscribedSquare Area : 100
	//CircumscribedSquare Perimeter : 40
}