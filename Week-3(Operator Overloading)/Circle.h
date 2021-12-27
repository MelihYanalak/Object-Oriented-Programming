#ifndef CIRCLE_H_   
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"
#include <string>
using namespace std;


class Circle{
	public:
	Circle& operator++();
	Circle operator++(int ignoreMe);
	Circle& operator--();
	Circle operator--(int ignoreMe);
	Circle operator+(double num)const;
	Circle operator-(double num)const;
	friend ostream& operator<<(ostream& fp,const Circle& shape);
	bool operator==(const Circle& shape)const;
	bool operator!=(const Circle& shape)const;
	bool operator<(const Circle& shape)const;
	bool operator>(const Circle& shape)const;
	bool operator<=(const Circle& shape)const;
	bool operator>=(const Circle& shape)const;

	double perimeter()const;
	inline double area()const;
	void draw(ostream& fp,string color)const;  // draw member function
	Circle();  // no parameter constructor
	Circle(double conRadius); // constructor with radius parameter
	Circle(double conRadius,double conOrX,double conOrY);
	double getRadius()const; // getter function for radius
	inline double getOriginX()const; // getter function for origin
	inline double getOriginY()const;
	void setRadius(double sRadius); // setter function for radius
	void setOriginX(double sOriginX); // setter function for originX
	void setOriginY(double sOriginY);  // setter function for originY
	private:
	double radius;	 // radius member private
	double originX; // originX member is the center coordinate in x direction
	double originY;  // originY member is the center coordinate in y direction
	
	
};

#endif
