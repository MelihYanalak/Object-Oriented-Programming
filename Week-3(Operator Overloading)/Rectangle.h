#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"
using namespace std;


class Rectangle{
	public:
	Rectangle(double conWidth,double conLength); // constructors
	Rectangle();
	Rectangle(double conWidth,double conLength,double conRDX,double conRDY);
	void draw(ostream& fp,string color)const;
	double getWidth()const;
	double getLength()const;
	inline double getRiDownX()const;    //getter functions
	inline double getRiDownY()const;
	void setWidth(double sWidth);
	void setLength(double sLength);
	void setRiDownX(double sRiDownX);   // setter functions
	void setRiDownY(double sRiDownY);
	Rectangle& operator++();
	Rectangle operator--(int ignoreMe);
	Rectangle& operator--();
	Rectangle operator++(int ignoreMe);
	Rectangle operator+(double num)const;
	Rectangle operator-(double num)const;

	bool operator==(const Rectangle& shape)const;
	bool operator!=(const Rectangle& shape)const;
	bool operator<(const Rectangle& shape)const;
	bool operator>(const Rectangle& shape)const;
	bool operator<=(const Rectangle& shape)const;
	bool operator>=(const Rectangle& shape)const;
	double perimeter()const;
	double area()const;
	friend ostream& operator<<(ostream& fp,const Rectangle& shape);
	private:
	double width;
	double length;
	double riDownX;   // private members width,length and right down corners coordinates
	double riDownY;
	
};

#endif
