
#ifndef POLYLINE_H_
#define POLYLINE_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComposedShape.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace Melih;
namespace {
class Polyline{

	public:
		class Point2D{
			public:
				inline double getX()const;
				void setX(double input);
				inline double getY()const;
				void setY(double input);
				
			private:
				double pointX;
				double pointY;
		};
		Polyline(int size);
		Polyline(Rectangle r1);
		Polyline(Circle c1);
		Polyline(Triangle t1);   // Convertion constructors
		Polyline(Point2D p2d);
		Polyline(vector<Point2D>& vec);
		inline double getNum()const;
		void setNum(int input);
		Point2D& operator[](int index); // for left hand side
		const Point2D& operator[](int index)const; // for left hand side
		bool operator==(const Polyline& rPol)const; // checks if two polylines are equal
		bool operator!=(const Polyline& rPol)const; // checks if two polylines are equal
		Polyline operator+(const Polyline& rPol)const;
		friend ostream& operator<<(ostream& fp,const Polyline& poly);

	private:
		Point2D* points;
		int pointNum;


};
}
#endif
