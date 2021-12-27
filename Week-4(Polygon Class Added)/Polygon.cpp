#include "ComposedShape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define PI (3.14159265359)
using namespace Melih;
namespace Melih{

	Polygon::Polygon(int size){
		points = new Point2D[size];
		pointNum = size;
	}
	Polygon::Polygon(Circle c1){
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
	Polygon::Polygon(Rectangle r1){
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
	Polygon::Polygon(Triangle t1){
		points = new Point2D[3];
		points[0].setX(t1.getLeftX());
		points[0].setY(t1.getLeftY());
		points[1].setX(t1.getMidX());
		points[1].setY(t1.getMidY());
		points[2].setX(t1.getRightX());
		points[2].setY(t1.getRightY());
		pointNum = 3;
	}
	Polygon::Polygon(Point2D p2d){
		
		points = new Point2D[1];
		points[0] = p2d;
		pointNum = 1;

	}
	Polygon::Polygon(vector<Point2D>& vec){
		int i = 0;
		points = new Point2D[vec.size()];
		while(i<vec.size()){
			points[i] = vec[i];
			i++;
		}
		pointNum = vec.size();
	}
	inline double Polygon::getNum()const{
		return pointNum;
	}
	void Polygon::setNum(int input){
		pointNum = input;
	}
	Polygon::Point2D& Polygon::operator[](int index){
		if(index > getNum()){
			cout<<"Invalid index! Returned first point"<<endl;
			return points[0];
		}
		else{
			return points[index];
		}
	}
	const Polygon::Point2D& Polygon::operator[](int index)const{
		if(index > getNum()){
			cout<<"Invalid index! Returned first point"<<endl;
			return points[0];
		}
		else{
			return points[index];
		}
	}

	bool Polygon::operator==(const Polygon& rPol)const{
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
	bool Polygon::operator!=(const Polygon& rPol)const{
		return !(*this == rPol);
	}
	Polygon Polygon::operator+(const Polygon& rPol)const{
		if(*this == rPol){
			Polygon p = rPol;
			return p;
		}
		else{
			Polygon p2(getNum()+rPol.getNum());
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

	inline double Polygon::Point2D::getX()const{
		return pointX;
	}
	inline double Polygon::Point2D::getY()const{
		return pointY;
	}

	void Polygon::Point2D::setX(double input){
		pointX = input;
	}
	void Polygon::Point2D::setY(double input){
		pointY = input;
	}
		ostream& operator<<(ostream& fp,const Polygon& poly){
		int i = 0;	
		fp<<"<polygon points=\"";
		while(i < poly.getNum()){
			fp<<poly[i].getX()<<","<<poly[i].getY()<<" ";
			i++;
		}
		fp<<"\" style=\"fill:green;stroke:yellow;stroke-width:1;fill-rule:nonzero;\" />"<<endl;
		return fp;

	}
}


