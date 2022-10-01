#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <stdexcept>


using namespace std;
namespace Melih{
class Triangle : public Shape
{
	
	public:
		double perimeter()const;
		double area()const;
		Triangle& operator++() ;
		Triangle& operator++(int ignoreMe) ;
		Triangle& operator--() ;
		Triangle& operator--(int ignoreMe) ;
		void draw(ostream& fp,string color)const;
		Triangle(double conSide);
		Triangle();
		Triangle(double conSide,double conLX,double conLY,double conMX,double conMY,double conRX,double conRY);
		double getLeftX()const noexcept;
		double getLeftY()const noexcept;
		double getMidX()const noexcept;    //getter functions
		double getMidY()const noexcept;
		double getRightX()const noexcept;
		double getRightY()const noexcept;
		double getSide()const noexcept;
		void setLeftX(double sLeftX);
		void setLeftY(double sLeftY);
		void setMidX(double sMidX); //setter functions
		void setMidY(double sMidY);
		void setRightX(double sRightX);
		void setRightY(double sRightY);
		void setSide(double sSide);
		Triangle& operator+(double num)const;
		Triangle& operator-(double num)const;
		
	private:
		double side;
		double leftX;
		double leftY;  // private members for corners coordinates and side input
		double midX;
		double midY;
		double rightX;
		double rightY;
	
	

};
}
#endif

