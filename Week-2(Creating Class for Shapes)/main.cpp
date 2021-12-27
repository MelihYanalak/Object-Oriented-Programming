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



int main(){

	ofstream fp;      // output file pointer
	auto i = 0;
	fp.open("output.svg");  // opening file
	fp<<"<svg>"<<endl;    
	
	Rectangle r1(300,300);  	
	Rectangle r2(24,13.5);
	ComposedShape cs1(r1,r2);   // creating composedShape object
	(cs1.getContainerR()).draw(fp,"red");   // drawing big shape                   // for situation 1 
	cs1.optimalFit();    // call this function to fill vector with small shapes
	
	while(i<cs1.getVectorR().size()){
		(cs1.getVecRec(i)).draw(fp,"green"); // draw small shapes in loop
		i++;
	}
	fp<<"</svg>";
	fp.close();


	i = 0;
	fp.open("output2.svg");
	fp<<"<svg>"<<endl;
	
	Rectangle r3(200,200);	
	Circle c1(24);                                    // for situation 2
	ComposedShape cs2(r3,c1);
	(cs2.getContainerR()).draw(fp,"red");
	cs2.optimalFit();
	
	while(i<cs2.getVectorC().size()){
		(cs2.getVecCirc(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();

	i = 0;
	fp.open("output3.svg");
	fp<<"<svg>"<<endl;
	
	Rectangle r4(200,300);	
	Triangle t1(24);
	ComposedShape cs3(r4,t1);
	(cs3.getContainerR()).draw(fp,"red");
	cs3.optimalFit();                                  // for situation 3
	
	while(i<cs3.getVectorT().size()){
		(cs3.getVecTri(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();

	i = 0;
	fp.open("output4.svg");
	fp<<"<svg>"<<endl;
	
	Circle c2(200);	
	Rectangle r5(24,17);
	ComposedShape cs4(c2,r5);
	(cs4.getContainerC()).draw(fp,"red");            // for situation 4
	cs4.optimalFit();
	
	while(i<cs4.getVectorR().size()){
		(cs4.getVecRec(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();

	i = 0;
	fp.open("output5.svg");
	fp<<"<svg>"<<endl;
	
	Circle c3(200);	
	Circle c4(24);
	ComposedShape cs5(c3,c4);
	(cs5.getContainerC()).draw(fp,"red");            // for situation 5
	cs5.optimalFit();
	
	while(i<cs5.getVectorC().size()){
		(cs5.getVecCirc(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();

	/*
	i = 0;
	fp.open("output6.svg");
	fp<<"<svg>"<<endl;
	
	Circle c5(200);	
	Triangle t2(24);
	ComposedShape cs6(c5,t2);
	(cs6.getContainerC()).draw(fp,"red");                 // for situation 6 but it has some problem :(
	cs6.optimalFit();
	
	while(i<cs6.getVectorT().size()){
		(cs6.getVecTri(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();

	*/
	i = 0;
	fp.open("output7.svg");
	fp<<"<svg>"<<endl;
	
	Triangle t3(200);	
	Rectangle r6(24,22);
	ComposedShape cs7(t3,r6);
	(cs7.getContainerT()).draw(fp,"red");
	cs7.optimalFit();
	
	while(i<cs7.getVectorR().size()){               // for situation 7
		(cs7.getVecRec(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();


	i = 0;
	fp.open("output8.svg");
	fp<<"<svg>"<<endl;
	
	Triangle t4(200);	
	Circle c6(24);
	ComposedShape cs8(t4,c6);
	(cs8.getContainerT()).draw(fp,"red");
	cs8.optimalFit();
	
	while(i<cs8.getVectorC().size()){                   // for situation 8
		(cs8.getVecCirc(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();


	i = 0;
	fp.open("output9.svg");
	fp<<"<svg>"<<endl;
	
	Triangle t5(200);	
	Triangle t6(24);
	ComposedShape cs9(t5,t6);
	(cs9.getContainerT()).draw(fp,"red");
	cs9.optimalFit();                                // for situation 9
	
	while(i<cs9.getVectorT().size()){
		(cs9.getVecTri(i)).draw(fp,"green");
		i++;
	}
	fp<<"</svg>";
	fp.close();


	


	return 1;
}

