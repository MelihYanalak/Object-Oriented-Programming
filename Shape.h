#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <fstream>
#include <vector>
#define PI (3.14159265) // the number of pi
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
using namespace std;
namespace Melih{

class Shape{

	public:
		virtual ~Shape()=default;
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual Shape& operator++() = 0;
		virtual Shape& operator++(int ignoreMe) = 0;
		virtual Shape& operator--() = 0;
		virtual Shape& operator--(int ignoreMe) = 0;
		bool operator==(const Shape& other)const;
		bool operator!=(const Shape& other)const;
		virtual void draw(ostream& fp,string color)const = 0;
		bool operator<(const Shape& shape)const ;
		bool operator>(const Shape& shape)const ;
		bool operator<=(const Shape& shape)const ;
		bool operator>=(const Shape& shape)const ;
};
}
#endif

