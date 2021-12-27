#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "Polyline.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>//I used power function to calculate square root of a number
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;
using namespace Melih;


int main(){

	ofstream fp;      // output file pointer

	fp.open("output.svg");  // opening file
	fp<<"<svg>"<<endl;    
	Rectangle r1(300,300);  	
	Rectangle r2(24,13.5);
	ComposedShape cs1(r1,r2);   // creating composedShape object
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
	cs3.optimalFit();
	fp<<cs3;                                  // for situation 3
	fp<<"</svg>";
	fp.close();


	fp.open("output4.svg");
	fp<<"<svg>"<<endl;	
	Circle c2(200);	
	Rectangle r5(24,17);
	ComposedShape cs4(c2,r5);
	cs4.optimalFit();
	fp<<cs4;
	fp<<"</svg>";
	fp.close();


	fp.open("output5.svg");
	fp<<"<svg>"<<endl;	
	Circle c3(200);	
	Circle c4(24);
	ComposedShape cs5(c3,c4);
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
	fp<<cs7;
	fp<<"</svg>";
	fp.close();


	fp.open("output8.svg");
	fp<<"<svg>"<<endl;
	Triangle t4(200);	
	Circle c6(24);
	ComposedShape cs8(t4,c6);
	cs8.optimalFit();
	fp<<cs8;
	fp<<"</svg>";
	fp.close();


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



