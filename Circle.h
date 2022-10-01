#ifndef CIRCLE_H_   
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"
#include <string>
#include "Shape.h"
using namespace std;
namespace Melih{

class Circle : public Shape
{
	public:
		
		virtual Circle& operator++();
		virtual Circle& operator++(int ignoreMe);
		virtual Circle& operator--();
		virtual Circle& operator--(int ignoreMe);
		virtual double perimeter()const;
		virtual double area()const;
		Circle operator+(double num)const;
		Circle operator-(double num)const;
		void draw(ostream& fp,string color)const;  // draw member function
		Circle();  // no parameter constructor
		Circle(double conRadius); // constructor with radius parameter
		Circle(double conRadius,double conOrX,double conOrY);
		double getRadius()const; // getter function for radius
		double getOriginX()const; // getter function for origin
		double getOriginY()const;
		void setRadius(double sRadius); // setter function for radius
		void setOriginX(double sOriginX); // setter function for originX
		void setOriginY(double sOriginY);  // setter function for originY
	private:
		double radius;	 // radius member private
		double originX; // originX member is the center coordinate in x direction
		double originY;  // originY member is the center coordinate in y direction
		
	
};
}
#endif



