#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComposedShape.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>//I used power function to calculate square root of a number
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;
ostream& operator<<(ostream& fp,const Circle& shape);
ostream& operator<<(ostream& fp,const Rectangle& shape);
ostream& operator<<(ostream& fp,const Triangle& shape);
ostream& operator<<(ostream& fp,ComposedShape::ShapeElen& shape);
ostream& operator<<(ostream& fp,ComposedShape& shape);

int main(){

	int i = 0;
	ofstream fp;      // output file pointer
	Circle ca(300);
	Circle cb(24);
	ca++;
	ca--;
	cb = cb + 20;
	cb = cb - 20;
	cout<<"Comparision"<<(ca==cb)<<"-"<<(ca!=cb)<<"-"<<(ca<cb)<<"-"<<(ca<=cb)<<"-"<<(ca>cb)<<"-"<<(ca>=cb)<<endl;	
	Triangle ta(300);
	Triangle tb(24);
	ta++;
	ta--;
	tb = tb + 20;
	tb = tb - 20;
	cout<<"Comparision"<<(ta==tb)<<"-"<<(ta!=tb)<<"-"<<(ta<tb)<<"-"<<(ta<=tb)<<"-"<<(ta>tb)<<"-"<<(ta>=tb)<<endl;
	Rectangle ra(300,300);
	Rectangle rb(24,24);
	ra++;
	ra--;
	rb = rb + 20;
	rb = rb - 20;
	cout<<"Comparision"<<(ra==rb)<<"-"<<(ra!=rb)<<"-"<<(ra<rb)<<"-"<<(ra<=rb)<<"-"<<(ra>rb)<<"-"<<(ra>=rb)<<endl;	
cout<<"Perimeters "<<ca.perimeter()<<"-"<<cb.perimeter()<<"-"<<ta.perimeter()<<"-"<<tb.perimeter()<<"-"<<ra.perimeter()<<"-"<<rb.perimeter()<<endl;
cout<<"Areas "<<ca.area()<<"-"<<cb.area()<<"-"<<ta.area()<<"-"<<tb.area()<<"-"<<ra.area()<<"-"<<rb.area()<<endl;

	fp.open("output1.svg");
	fp<<"<svg>"<<endl;
	Rectangle r1(300,300);  	
	Rectangle r2(24,13.5);
	ComposedShape cs1(r1,r2);   // creating composedShape object                 // for situation 1 
	cs1.optimalFit();    // call this function to fill vector with small shapes
	fp<<cs1;
	fp<<"</svg>";
	fp.close();


	fp.open("output2.svg");
	fp<<"<svg>"<<endl;
	Rectangle r3(200,200);	
	Circle c1(24);                                    // for situation 2
	ComposedShape cs2(r3,c1);
	cs2.optimalFit();
	fp<<cs2;
	fp<<"</svg>";
	fp.close();


	fp.open("output3.svg");
	fp<<"<svg>"<<endl;
	Rectangle r4(200,300);	
	Triangle t1(24);
	ComposedShape cs3(r4,t1);
	cs3.optimalFit();                                  // for situation 3
	fp<<cs3;
	fp<<"</svg>";
	fp.close();


	fp.open("output4.svg");
	fp<<"<svg>"<<endl;
	Circle c2(200);	
	Rectangle r5(24,17);
	ComposedShape cs4(c2,r5);         // for situation 4
	cs4.optimalFit();
	fp<<cs4;
	fp<<"</svg>";
	fp.close();


	fp.open("output5.svg");
	fp<<"<svg>"<<endl;	
	Circle c3(200);	
	Circle c4(24);
	ComposedShape cs5(c3,c4);         // for situation 5
	cs5.optimalFit();
	fp<<cs5;
	fp<<"</svg>";
	fp.close();


	fp.open("output7.svg");
	fp<<"<svg>"<<endl;
	Triangle t3(200);	
	Rectangle r6(24,22);
	ComposedShape cs7(t3,r6);
	cs7.optimalFit();
	fp<<cs7;                                 // for situation 7
	fp<<"</svg>";
	fp.close();


	fp.open("output8.svg");
	fp<<"<svg>"<<endl;
	Triangle t4(200);	
	Circle c6(24);
	ComposedShape cs8(t4,c6);
	cs8.optimalFit();
	fp<<cs8;	           // for situation 8
	fp<<"</svg>";
	fp.close();


	i = 0;
	fp.open("output9.svg");
	fp<<"<svg>"<<endl;
	Triangle t5(200);	
	Triangle t6(24);
	ComposedShape cs9(t5,t6);
	cs9.optimalFit();                                // for situation 9
	fp<<cs9;
	fp<<"</svg>";
	fp.close();

	return 1;
}




