#include "Shape.h"
#include <iostream>
using namespace std;
namespace Melih{
bool Shape::operator==(const Shape& other)const{
	if(area() == other.area()){
		return true;
	}
	return false;
}

bool Shape::operator!=(const Shape& other)const{
	if(area() == other.area()){
		return false;
	}
	return true;


}

bool Shape::operator<(const Shape& shape)const {
		if(area()<shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Shape::operator>(const Shape& shape)const {
		if(area()>shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Shape::operator<=(const Shape& shape)const {
		if(area()<= shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Shape::operator>=(const Shape& shape)const {
		if(area()>= shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}

}
