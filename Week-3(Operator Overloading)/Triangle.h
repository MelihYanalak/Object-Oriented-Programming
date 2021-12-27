#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "Circle.h"
#include "Rectangle.h"
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;

class Triangle{
	
	public:
	void draw(ostream& fp,string color)const;
	Triangle(double conSide);
	Triangle();
	Triangle(double conSide,double conLX,double conLY,double conMX,double conMY,double conRX,double conRY);
	inline double getLeftX()const;
	inline double getLeftY()const;
	inline double getMidX()const;    //getter functions
	inline double getMidY()const;
	inline double getRightX()const;
	inline double getRightY()const;
	double getSide()const;
	void setLeftX(double sLeftX);
	void setLeftY(double sLeftY);
	void setMidX(double sMidX); //setter functions
	void setMidY(double sMidY);
	void setRightX(double sRightX);
	void setRightY(double sRightY);
	void setSide(double sSide);
	Triangle& operator++();
	Triangle operator++(int ignoreMe);
	Triangle& operator--();
	Triangle operator--(int ignoreMe);
	Triangle operator+(double num)const;
	Triangle operator-(double num)const;
	bool operator==(const Triangle& shape)const;
	bool operator!=(const Triangle& shape)const;
	bool operator<(const Triangle& shape)const;
	bool operator>(const Triangle& shape)const;
	bool operator<=(const Triangle& shape)const;
	bool operator>=(const Triangle& shape)const;
	friend ostream& operator<<(ostream& fp,const Triangle& shape);
	double perimeter()const;
	double area()const;
	//friend ostream& operator<<(ostream& fp,const Triangle& shape);
	private:
	double side;
	double leftX;
	double leftY;  // private members for corners coordinates and side input
	double midX;
	double midY;
	double rightX;
	double rightY;
	
	

};
#endif

