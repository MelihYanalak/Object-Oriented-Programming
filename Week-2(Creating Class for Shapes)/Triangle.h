#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;

class Triangle{
	
	public:
	void draw(ofstream& fp,string color)const;
	Triangle(double conSide);
	Triangle();
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

