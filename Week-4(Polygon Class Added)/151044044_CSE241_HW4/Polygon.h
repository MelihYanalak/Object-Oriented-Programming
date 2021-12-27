#ifndef POLYGON_H_
#define POLYGON_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComposedShape.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
namespace Melih{
	class Polygon{

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
			Polygon(int size);
			Polygon(Rectangle r1);	
			Polygon(Circle c1);
			Polygon(Triangle t1);   // Convertion constructors
			Polygon(Point2D p2d);
			Polygon(vector<Point2D>& vec);
			inline double getNum()const;
			void setNum(int input);
			Point2D& operator[](int index); // for left hand side
			const Point2D& operator[](int index)const; // for left hand side
			bool operator==(const Polygon& rPol)const; // checks if two polygons are equal
			bool operator!=(const Polygon& rPol)const; // checks if two polygons are equal
			Polygon operator+(const Polygon& rPol)const;
			friend ostream& operator<<(ostream& fp,const Polygon& poly);

		private:
			Point2D* points;
			int pointNum;


	};
}
#endif
