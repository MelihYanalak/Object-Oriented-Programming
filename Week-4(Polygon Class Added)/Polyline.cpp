#include "ComposedShape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polyline.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define PI (3.14159265359)
using namespace Melih;

namespace {
	Polyline::Polyline(int size){
		points = new Point2D[size];
		pointNum = size;
	}
	Polyline::Polyline(Circle c1){
		points = new Point2D[100];
		points[0].setX(c1.getOriginX()-c1.getRadius());
		points[0].setY(c1.getOriginY());
		int i = 1;
		int j = 1;

		while(i < 26 && i>0){
			points[i].setX(points[0].getX() + (c1.getRadius()*(1-cos(i*(3.6)*PI/180.0))));
			points[i].setY(points[0].getY() - (c1.getRadius()*sin(i*(3.6)*PI/180.0)));
			i++;
		}
		while(i < 51 && i> 25){
			points[i].setY(points[25].getY() + (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			points[i].setX(points[25].getX() + (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			j++;
			i++;
		}
		j = 1;
		
		while(i < 76 && i > 50 ){
			points[i].setX(points[50].getX() - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			points[i].setY(points[50].getY() + (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			i++;
			j++;
		}
		j = 1;
		while(i < 100 && i > 75){
			points[i].setY(points[75].getY() - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			points[i].setX(points[75].getX() - (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			i++;
			j++;
		}
		
		pointNum = 100;



	}
	Polyline::Polyline(Rectangle r1){
		points = new Point2D[4];
		points[0].setX((r1.getRiDownX())-r1.getWidth());
		points[0].setY((r1.getRiDownY())-r1.getLength());
		points[1].setX(r1.getRiDownX());
		points[1].setY((r1.getRiDownY())-(r1.getLength()));
		points[2].setX(r1.getRiDownX());
		points[2].setY(r1.getRiDownY());
		points[3].setX((r1.getRiDownX())-(r1.getWidth()));
		points[3].setY(r1.getRiDownY());
		pointNum = 4;
	}
	Polyline::Polyline(Triangle t1){
		points = new Point2D[3];
		points[0].setX(t1.getLeftX());
		points[0].setY(t1.getLeftY());
		points[1].setX(t1.getMidX());
		points[1].setY(t1.getMidY());
		points[2].setX(t1.getRightX());
		points[2].setY(t1.getRightY());
		pointNum = 3;
	}
	Polyline::Polyline(Point2D p2d){
		
		points = new Point2D[1];
		points[0] = p2d;
		pointNum = 1;

	}
	Polyline::Polyline(vector<Point2D>& vec){
		int i = 0;
		points = new Point2D[vec.size()];
		while(i<vec.size()){
			points[i] = vec[i];
			i++;
		}
		pointNum = vec.size();
	}
	inline double Polyline::getNum()const{
		return pointNum;
	}
	void Polyline::setNum(int input){
		pointNum = input;
	}
	Polyline::Point2D& Polyline::operator[](int index){
		if(index > getNum()){
			cout<<"Invalid index! Returned first point"<<endl;
			return points[0];
		}
		else{
			return points[index];
		}
	}
	const Polyline::Point2D& Polyline::operator[](int index)const{
		if(index > getNum()){
			cout<<"Invalid index! Returned first point"<<endl;
			return points[0];
		}
		else{
			return points[index];
		}
	}

	bool Polyline::operator==(const Polyline& rPol)const{
		int i = 0;	
		if(getNum() != rPol.getNum()){
			return 0;
		}
		else{
			while(i<getNum()){
				if(this[i] != rPol[i]){
					return 0;
				}
				i++;
			}
			return 1;
		}
	}
	bool Polyline::operator!=(const Polyline& rPol)const{
		return !(*this == rPol);
	}
	Polyline Polyline::operator+(const Polyline& rPol)const{
		if(*this == rPol){
			Polyline p = rPol;
			return p;
		}
		else{
			Polyline p2(getNum()+rPol.getNum());
			int i = 0;
			while(i < rPol.getNum()){
				p2[i] = rPol[i]; 
				i++;
			}
			int j = 0;
			while(j < getNum()){
				p2[i+j] = points[j];
				j++;
			}
			return p2;
		}
	}

	inline double Polyline::Point2D::getX()const{
		return pointX;
	}
	inline double Polyline::Point2D::getY()const{
		return pointY;
	}

	void Polyline::Point2D::setX(double input){
		pointX = input;
	}
	void Polyline::Point2D::setY(double input){
		pointY = input;
	}
	ostream& operator<<(ostream& fp,const Polyline& poly){
		int i = 0;	
		while(i < poly.getNum()-1){
			fp<<"<polygon points=\""<<poly[i].getX()<<","<<poly[i].getY()<<" "<<poly[i+1].getX()<<","<<poly[i+1].getY()<<"\" style=\"fill:white;stroke:black;stroke-width:3;fill-rule:nonzero;\" />"<<endl;
			i++;
		}
		
		return fp;

	}
}


