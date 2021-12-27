#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <vector>	
using namespace std;

	// draw member function 
	void Rectangle::draw(ofstream& fp,string color)const{
	fp<<"<rect x=\""<<getRiDownX()-(getWidth())<<"\" y=\""<<getRiDownY()-(getLength())<<"\" width=\""<<getWidth()<<"\" height=\""<<getLength()<<"\""<<endl<<"style=\"fill:"<<color<<";stroke:black;stroke-width:1;fill-opacity:1;stroke-opacity:0.9\" />"<<endl; 
		
}	
	Rectangle::Rectangle(double conWidth,double conLength){
		width = conWidth;    // constructor with parameter
		length = conLength;

	}
	Rectangle::Rectangle(){    // constructor with no parameter
	}	
	double Rectangle::getWidth()const{
		return width;  

	}
	double Rectangle::getLength()const{            //getter functions for variables
		return length;

	}
	inline double Rectangle::getRiDownX()const{
		return riDownX;

	}
	inline double Rectangle::getRiDownY()const{
		return riDownY;

	}
	void Rectangle::setWidth(double sWidth){
		width = sWidth;
	}
	void Rectangle::setLength(double sLength){       //setter functions for variables
		length = sLength;
	}
	void Rectangle::setRiDownX(double sRiDownX){
		riDownX = sRiDownX;
	}
	void Rectangle::setRiDownY(double sRiDownY){
		riDownY = sRiDownY;
	}

