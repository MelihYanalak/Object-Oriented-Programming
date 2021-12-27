#include "Triangle.h"	
#include <iostream>
#include <fstream>
#include <vector>

namespace Melih{
using namespace std;

	// member draw function
	void Triangle::draw(ofstream& fp,string color)const{
	fp<<"<polygon points= \""<<getMidX()<<","<<getMidY()<<","<<getLeftX()<<","<<getLeftY()<<","<<getRightX()<<","<<getRightY()<<"\" style=\"fill:"<<color<<";stroke:black;stroke-width:1\" />"<<endl;


}


	Triangle::Triangle(double conSide){ // constructor with parameter
		side = conSide;

	}
	Triangle::Triangle(){// constructor with no parameter
	}
	inline double Triangle::getLeftX()const{
		return leftX;
	}
	inline double Triangle::getLeftY()const{
		return leftY;                           //GETTER FUNCTIONS

	}	
	inline double Triangle::getMidX()const{
		return midX;
	}
	inline double Triangle::getMidY()const{
		return midY;

	}
	inline double Triangle::getRightX()const{
		return rightX;
	}
	inline double Triangle::getRightY()const{
		return rightY;

	}
	double Triangle::getSide()const{
		return side;
	}
	void Triangle::setLeftX(double sLeftX){
		leftX = sLeftX;
	}
	void Triangle::setLeftY(double sLeftY){
		leftY = sLeftY;

	}	
	void Triangle::setMidX(double sMidX){
		midX = sMidX;                              //SETTER FUNCTIONS
	}
	void Triangle::setMidY(double sMidY){
		midY = sMidY;

	}
	void Triangle::setRightX(double sRightX){
		rightX = sRightX;
	}
	void Triangle::setRightY(double sRightY){
		rightY = sRightY;

	}
	void Triangle::setSide(double sSide){
		side = sSide;
	}
}
