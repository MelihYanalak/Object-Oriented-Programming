#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;
namespace Melih{

class Rectangle : public Shape
{
	public:
	double perimeter()const;
	double area()const;
	Rectangle& operator++();
	Rectangle& operator--(int ignoreMe);
	Rectangle& operator--();
	Rectangle& operator++(int ignoreMe);
	Rectangle(double conWidth,double conLength); // constructors
	Rectangle()noexcept;
	Rectangle(double conWidth,double conLength,double conRDX,double conRDY);
	void draw(ostream& fp,string color)const;
	double getWidth()const;
	double getLength()const;
	double getRiDownX()const;    //getter functions
	double getRiDownY()const;
	void setWidth(double sWidth);
	void setLength(double sLength);
	void setRiDownX(double sRiDownX);   // setter functions
	void setRiDownY(double sRiDownY);
	Rectangle& operator+(double num)const;
	Rectangle& operator-(double num)const;
	private:
	double width;
	double length;
	double riDownX;   // private members width,length and right down corners coordinates
	double riDownY;
	
};
}
#endif


