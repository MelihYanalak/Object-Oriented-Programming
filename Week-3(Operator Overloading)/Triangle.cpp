#include "Triangle.h"	
#include <iostream>
#include <fstream>
#include <vector>
#define SQR (1.7320)

using namespace std;

	// member draw function
	void Triangle::draw(ostream& fp,string color)const{
	fp<<"<polygon points= \""<<getMidX()<<","<<getMidY()<<","<<getLeftX()<<","<<getLeftY()<<","<<getRightX()<<","<<getRightY()<<"\" style=\"fill:"<<color<<";stroke:black;stroke-width:1\" />"<<endl;


}


	Triangle::Triangle(double conSide){ // constructor with parameter
		setSide(conSide);
		setLeftX(0);
		setLeftY(conSide/2*SQR);
		setMidX(conSide/2);
		setMidY(0);
		setRightX(conSide);
		setRightY(conSide/2*SQR);

	}
	Triangle::Triangle(double conSide,double conLX,double conLY,double conMX,double conMY,double conRX,double conRY){
		setSide(conSide);
		setLeftX(conLX);
		setLeftY(conLY);
		setMidX(conMX);
		setMidY(conMY);
		setRightX(conRX);
		setRightY(conRY);

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

	Triangle& Triangle::operator++(){
		setLeftX(getLeftX()+1.0);
		setLeftY(getLeftY()+1.0);
		setMidX(getMidX()+1.0);
		setMidY(getMidY()+1.0);
		setRightX(getRightX()+1.0);
		setRightY(getRightY()+1.0);
		return *this;

	}
	Triangle Triangle::operator++(int ignoreMe){
		double temp1,temp2,temp3,temp4,temp5,temp6;
		temp1 = getLeftX();
		temp2 = getLeftY();
		temp3 = getMidX();
		temp4 = getMidY();
		temp5 = getRightX();
		temp6 = getRightY();
		Triangle newTri(getSide(),temp1,temp2,temp3,temp4,temp5,temp6);
		setLeftX(getLeftX()+1.0);
		setLeftY(getLeftY()+1.0);
		setMidX(getMidX()+1.0);
		setMidY(getMidY()+1.0);
		setRightX(getRightX()+1.0);
		setRightY(getRightY()+1.0);		
		return newTri;


	}
	Triangle& Triangle::operator--(){
		setLeftX(getLeftX()-1.0);
		setLeftY(getLeftY()-1.0);
		setMidX(getMidX()-1.0);
		setMidY(getMidY()-1.0);
		setRightX(getRightX()-1.0);
		setRightY(getRightY()-1.0);
		return *this;



	}
	Triangle Triangle::operator--(int ignoreMe){
		double temp1,temp2,temp3,temp4,temp5,temp6;
		temp1 = getLeftX();
		temp2 = getLeftY();
		temp3 = getMidX();
		temp4 = getMidY();
		temp5 = getRightX();
		temp6 = getRightY();
		Triangle newTri(getSide(),temp1,temp2,temp3,temp4,temp5,temp6);
		setLeftX(getLeftX()-1.0);
		setLeftY(getLeftY()-1.0);
		setMidX(getMidX()-1.0);
		setMidY(getMidY()-1.0);
		setRightX(getRightX()-1.0);
		setRightY(getRightY()-1.0);		
		return newTri;




	}



	Triangle Triangle::operator+(double num)const{
		Triangle newTri(getSide()+num,getLeftX(),getLeftY(),getMidX(),getMidY(),getRightX(),getRightY());
		return newTri;
	}
	Triangle Triangle::operator-(double num)const{
		Triangle newTri(getSide()-num,getLeftX(),getLeftY(),getMidX(),getMidY(),getRightX(),getRightY());
		return newTri;

	}



	double Triangle::perimeter()const{
		return (getSide()*3);
	}
	double Triangle::area()const{
		return (getSide()*getSide()*SQR/4);

	}


	bool Triangle::operator==(const Triangle& shape)const{
		if(area()==shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}
	bool Triangle::operator!=(const Triangle& shape)const{
		if(area()==shape.area()){
			return 0;
		}
		else{
			return 1;
		}


	}
	bool Triangle::operator<(const Triangle& shape)const{
		if(area()<shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Triangle::operator>(const Triangle& shape)const{
		if(area()>shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Triangle::operator<=(const Triangle& shape)const{
		if(area()<= shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Triangle::operator>=(const Triangle& shape)const{
		if(area()>= shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}


	ostream& operator<<(ostream& fp,const Triangle& shape){		
		shape.draw(fp,"red");
		return fp;
	}






