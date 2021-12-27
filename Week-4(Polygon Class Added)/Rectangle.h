#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace Melih{
	class Rectangle{
		public:
		Rectangle(double conWidth,double conLength); // constructors
		Rectangle();

		void draw(ofstream& fp,string color)const;
		double getWidth()const;
		double getLength()const;
		inline double getRiDownX()const;    //getter functions
		inline double getRiDownY()const;
		void setWidth(double sWidth);
		void setLength(double sLength);
		void setRiDownX(double sRiDownX);   // setter functions
		void setRiDownY(double sRiDownY);
		private:
		double width;
		double length;
		double riDownX;   // private members width,length and right down corners coordinates
		double riDownY;
		
	};
}
#endif
