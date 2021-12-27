#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;

class ComposedShape{
	public:
	void optimalFit();
	ComposedShape(Rectangle bigR,Rectangle smallR);
	ComposedShape(Rectangle bigR,Circle smallC);
	ComposedShape(Rectangle bigR,Triangle smallT);
	ComposedShape(Circle bigC,Rectangle smallR);   // constructors for 9 situation
	ComposedShape(Circle bigC,Circle smallC);
	ComposedShape(Circle bigC,Triangle smallT);
	ComposedShape(Triangle bigT,Rectangle smallR);
	ComposedShape(Triangle bigT,Circle smallC);
	ComposedShape(Triangle bigT,Triangle smallT);
	int getSituation()const;
	Rectangle getInnerR();    // gets big and small shapes
	Rectangle getContainerR();
	Circle getInnerC();
	Circle getContainerC();
	Triangle getInnerT();
	Triangle getContainerT();
	double centerX;
	decltype(centerX) centerY; // to calculate the place we declare centerY
	decltype(centerX) center;
	class ShapeElen{
		public:
			enum typeOfShape{
				RECTANGLE,CIRCLE,TRIANGLE
			};
			ShapeElen();
			ShapeElen(void* ptr,typeOfShape type);	
			inline double perimeter();
			inline double area();
			void* smallS;
			typeOfShape t1;
			friend ostream& operator<<(ostream& fp,ShapeElen& shape);
			

	};
	//void operator+=(ShapeElen shape);
	inline const ShapeElen& operator[](int index)const;
	friend ostream& operator<<(ostream& fp,ComposedShape& shape);
	vector<ShapeElen> innerVec;
	private:
	int situation;
	Rectangle innerR;
	Rectangle containerR;
	Triangle innerT;        
	Triangle containerT;
	Circle innerC;
	Circle containerC;
};
#endif
