#include <iostream>
#include <string>//i used string to input color
#include <fstream>
#include <math.h>//I used power function to calculate square root of a number
using namespace std;
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
int drawTri(double side,double leftX,double leftY,double midX,double midY,double rightX,double rightY,string color);//draws triangle
int drawCirc(double radius,double originX,double originY,string color);  // draws circle
int drawRec(double width,double length,double riDownX,double riDownY,string color); // draws rectangle
int circInCirc(double center,double radInput,double radInput2); // draws circles in a circle
int recInCirc(double center,double radInput,double widInput2,double lenInput2); // draws rectangles in a circle
int triInCirc(double center,double radInput,double triInput2); // draws triangle in a circle
int circInRec(double centerX,double centerY,double widInput,double lenInput,double radInput2);//draws circle in a rectangle
int recInRec(double centerX,double centerY,double widInput,double lenInput,double widInput2,double lenInput2);//draws rectangle in a rectangle
int triInRec(double centerX,double centerY,double widInput,double lenInput,double triInput2); // draws triangle in a rectangle
int circInTri(double centerX,double centerY,double triInput,double radInput2);// draws circle in a triangle
int recInTri(double centerX,double centerY,double triInput,double widInput2,double lenInput2); // draws rectangle in a triangle
int triInTri(double centerX,double centerY,double triInput,double triInput2);// draws triangle in a triangle
enum class Shape{CIRCLE,TRIANGLE,RECTANGLE}; // enum class to seperate shapes
ofstream fp; // file pointer(its global because i wrote in file in functions)
int main(){
	double center; // Depends on the container value that user entered,center changes
	double centerX,centerY; // If container is not a symmetric i use these variables
	Shape container; // big shape
	Shape inside; // small shape
	char cont; // user input container
	char small; // user input small shape
	fp.open("output.svg"); // opening file
	
	cout<<"Please enter the main container shape (R, C, T)"<<endl;
	cin>>cont;
	if('R' == cont || 'r' == cont){
		container = Shape::RECTANGLE;
		
	}
	else if('C' == cont || 'c' == cont){           // Determining which shape user entered
		container = Shape::CIRCLE;
	
	}
	else if('T' == cont || 't' == cont){
		container = Shape::TRIANGLE;
	
	}
	switch(container){

		case Shape::CIRCLE:
			double radInput;
			cout<<"Please enter the radius of circle"<<endl;
			cin>>radInput;                                       // I asked the value of Circle
			fp<<"<svg height=\""<<radInput*2<<"\" width=\""<<radInput*2<<"\">"<<endl;  // Creating svg image as big as include circle
			center = radInput; //center of circle is x = radius y = radius
			if(radInput<= 0){
				cout<<"It's not valid value"; // if user enter invalid
				return 0;
			}
			drawCirc(radInput,center,center,"red"); // draw container
			cout<<"Please enter the small shape (R, C, T)"<<endl;
			cin>>small; // ask small shape
			if('R' == small || 'r' == small){
				inside = Shape::RECTANGLE;
		
			}
			else if('C' == small || 'c' == small){
				inside = Shape::CIRCLE;         // determine small shape
	
			}
			else if('T' == small || 't' == small){
				inside = Shape::TRIANGLE;
	
			}
			switch(inside){
				case Shape::CIRCLE:
					double radInput2; 
					cout<<"Please enter the radius of small circle"<<endl;
					cin>>radInput2;
					if(radInput2<= 0){
						cout<<"It's not valid value";
						return 0;
					}
					circInCirc(center,radInput,radInput2);
					break;
				case Shape::RECTANGLE:
					double widInput2,lenInput2;       // depending on second shape we call one of these functions
					cout<<"Please enter the width of small rectangle"<<endl;
					cin>>widInput2;
					cout<<"Please enter the length of small rectangle"<<endl;
					cin>>lenInput2;
					if(lenInput2<= 0){
						cout<<"It's not valid value";
						return 0;
					}
					recInCirc(center,radInput,widInput2,lenInput2);
					break;
				case Shape::TRIANGLE:
					double triInput2;
					cout<<"Please enter the side of small triangle "<<endl;
					cin>>triInput2;
					if(triInput2<= 0){
						cout<<"It's not valid value";
						return 0;
					}
					triInCirc(center,radInput,triInput2);
					break;

			}		

			break;

		case Shape::TRIANGLE:
			double triInput;
			cout<<"Please enter the side of triangle "<<endl;
			cin>>triInput;
			if(triInput<=0){
				cout<<"It's not valid value"<<endl;
				return 0;	
			}
			fp<<"<svg height=\""<<triInput*SQR/2<<"\" width=\""<<triInput<<"\">"<<endl;
			centerX = triInput/2;
			centerY = triInput*SQR/3;
			drawTri(triInput,centerX-(triInput/2),centerY+((triInput*SQR)/6),centerX,centerY-(triInput*SQR/3),centerX+(triInput/2),centerY+(triInput*SQR/6),"red"); // drawing triangle and calculating the points of triangle
			cout<<"Please enter the small shape (R, C, T)"<<endl;
			cin>>small;
			if('R' == small || 'r' == small){
				inside = Shape::RECTANGLE;
		
			}
			else if('C' == small || 'c' == small){   // determining shape
				inside = Shape::CIRCLE;
	
			}
			else if('T' == small || 't' == small){
				inside = Shape::TRIANGLE;
	
			}
			switch(inside){
				case Shape::CIRCLE:
					double radInput2;
					cout<<"Please enter the radius of small circle"<<endl;
					cin>>radInput2;
					if(radInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					circInTri(centerX,centerY,triInput,radInput2);
					break;
				case Shape::RECTANGLE:
					double widInput2,lenInput2;
					cout<<"Please enter the width of small rectangle"<<endl;
					cin>>widInput2;
					if(widInput2<=0){
						cout<<"It's not valid value"<<endl;        // calling one of functions depending on input 
						return 0;	
					}
					cout<<"Please enter the length of small rectangle"<<endl;
					cin>>lenInput2;
					if(lenInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					recInTri(centerX,centerY,triInput,widInput2,lenInput2);
					break;
				case Shape::TRIANGLE:
					double triInput2;
					cout<<"Please enter the side of small triangle "<<endl;
					cin>>triInput2;
					if(triInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					triInTri(centerX,centerY,triInput,triInput2);
					break;

			}
			break;


		case Shape::RECTANGLE:
			double widInput,lenInput;
			cout<<"Please enter the width of rectangle"<<endl;
			cin>>widInput;
			if(widInput<=0){
				cout<<"It's not valid value"<<endl;
				return 0;	
			}
			cout<<"Please enter the length of rectangle"<<endl;
			cin>>lenInput;
			if(lenInput<=0){
				cout<<"It's not valid value"<<endl;
				return 0;	
			}
			centerX = widInput/2;
			centerY = lenInput/2;
			fp<<"<svg height=\""<<lenInput<<"\" width=\""<<widInput<<"\">"<<endl;
			drawRec(widInput,lenInput,centerX+(widInput/2),centerY+(lenInput/2),"red");
			cout<<"Please enter the small shape (R, C, T)"<<endl;
			cin>>small;
			if('R' == small || 'r' == small){
				inside = Shape::RECTANGLE;
		
			}
			else if('C' == small || 'c' == small){    // determining shape
				inside = Shape::CIRCLE;
	
			}
			else if('T' == small || 't' == small){
				inside = Shape::TRIANGLE;
	
			}
			switch(inside){
				case Shape::CIRCLE:
					double radInput2;
					cout<<"Please enter the radius of small circle"<<endl;
					cin>>radInput2;
					if(radInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					circInRec(centerX,centerY,widInput,lenInput,radInput2);
					break;
				case Shape::RECTANGLE:
					double widInput2,lenInput2;
					cout<<"Please enter the width of small rectangle"<<endl;
					cin>>widInput2;
					if(widInput2<=0){
						cout<<"It's not valid value"<<endl;  // calling function for input
						return 0;	
					}
					cout<<"Please enter the length of small rectangle"<<endl;
					cin>>lenInput2;
					if(lenInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					recInRec(centerX,centerY,widInput,lenInput,widInput2,lenInput2);
					break;
				case Shape::TRIANGLE:
					double triInput2;
					cout<<"Please enter the side of small triangle "<<endl;
					cin>>triInput2;
					if(triInput2<=0){
						cout<<"It's not valid value"<<endl;
						return 0;	
					}
					triInRec(centerX,centerY,widInput,lenInput,triInput2);
					break;

			}		
			break;
		default:
			return 0;

	}
	fp<<"</svg>"; // at the end we close svg file like that
	fp.close(); // closing file 
}

int drawTri(double side,double leftX,double leftY,double midX,double midY,double rightX,double rightY,string color){
	//this function draws the triangle by getting our corner points
	fp<<"<polygon points= \""<<midX<<","<<midY<<","<<leftX<<","<<leftY<<","<<rightX<<","<<rightY<<"\" style=\"fill:"<<color<<";stroke:black;stroke-width:1\" />"<<endl;	
	return 0;
}


int drawCirc(double radius,double originX,double originY,string color){
	// draws circle using origin point and radius
	fp<<"<circle cx=\""<<originX<<"\" cy=\""<<originY<<"\" r=\""<<radius<<"\" stroke=\"black\" stroke-width=\"1\" fill=\""<<color<<"\" />"<<endl;
	return 0;
}


int drawRec(double width,double length,double riDownX,double riDownY,string color){
	//draws rectangle by using right bottom point
	fp<<"<rect x=\""<<riDownX-(width)<<"\" y=\""<<riDownY-(length)<<"\" width=\""<<width<<"\" height=\""<<length<<"\""<<endl<<"style=\"fill:"<<color<<";stroke:black;stroke-width:1;fill-opacity:1;stroke-opacity:0.9\" />"<<endl; 
	return 0;

}



int circInCirc(double center,double radInput,double radInput2){
	int control = 0;
	int count = 0;
	double result;
	double rightBorder = (center+(radInput*2)/2);
	double leftBorder = center-((radInput*2)/2);     // i created imaginary smallest square shape that include container circle 
	double upBorder = center-((radInput*2)/2);	// i calculated the borders coordinates
	double downBorder = center+((radInput*2)/2);
	double currX = leftBorder + radInput2;  // we will move with these 2 variables in loop
	double currY = upBorder + radInput2;
	while((downBorder-currY)>=((radInput2)*SQR)){
		if(control%2 == 1){
			currX = leftBorder + (2*radInput2); // control variable for determine starting point of every column
		}
		else if(control%2 == 0){
			currX = leftBorder + radInput2;
		}
		while((rightBorder-currX)>= (radInput2)){
			if(pow((center-currX)*(center-currX)+(center-currY)*(center-currY),0.5)<=(radInput-radInput2)){
			// I used geometrical distance formula to determine if the circuit inside a container or not
			drawCirc(radInput2,currX,currY,"green");
			count++;
			}
			currX = currX + (2*radInput2);
		}
		control++;
		currY = currY + ((radInput2)*SQR);
	}

	result = (PI*radInput*radInput)-(count)*(PI*radInput2*radInput2);
	cout<<"I could fit at most "<<count<<" circles in container circle"<<endl;
	cout<<"The area of red zone is = "<<result<<endl;



}
int recInCirc(double center,double radInput,double widInput2,double lenInput2){
	double rightBorder = (center+radInput/SQR2);
	double leftBorder = center-(radInput/SQR2);
	double upBorder = center-(radInput/SQR2);
	double downBorder = center+(radInput/SQR2);
	int countA = 0;
	double result;
	int countB = 0;                         // I created imaginary the biggest square inside circle and fill like it's a square
	double temp;
	double endOfL;
	double currX;
	double upB;
	double currY;
	currX= leftBorder+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){
			countA++;                       // I don't draw here i just count
			currX = currX + widInput2;	// Horizontal

		}
		endOfL = currX-widInput2;
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}
	
	//endOfL = endOfL - widInput2;	
	temp = widInput2;
	widInput2 = lenInput2;    // SWAP SIDES
	lenInput2 = temp;
	
	currX= endOfL+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){                  //Finished horizontal but trying to fill it with vertical
		while((rightBorder-currX)>=(0)){     
			countA++;
			currX = currX + widInput2;

		}
		currX = endOfL + widInput2;
		currY = currY + lenInput2;

	}

	//-------------------------------------
	
	currX= leftBorder+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){        // Vertical starting
			countB++;
			currX = currX + widInput2;

		}
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}
	upB = currY-lenInput2;
	
		
	temp = widInput2;
	widInput2 = lenInput2;
	lenInput2 = temp;
	
	currX= leftBorder+widInput2;
	currY = upB + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){     //Filling missing parts vertically
			countB++;
			currX = currX + widInput2;

		}
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}
	if(countA >= countB){
			currX= leftBorder+widInput2;
		currY = upBorder + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green"); // If A>B it means that i will place horizontally
				currX = currX + widInput2;

			}
			endOfL = currX-widInput2;
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		
		currX= endOfL+widInput2;
		currY = upBorder + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");
				currX = currX + widInput2;

			}
			currX = endOfL + widInput2;
			currY = currY + lenInput2;

		}

		 result = (radInput*radInput*PI)-(countA)*(widInput2*lenInput2);
		cout<<"I could fit at most "<<countA<<" rectangles in container circle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;

	}
	
	else if(countB > countA){
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		currX= leftBorder+widInput2;
		currY = upBorder + lenInput2;      // IF B > A    I FILL VERTICALLY
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");
				currX = currX + widInput2;

			}
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}
		upB = currY-lenInput2;
		
			
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		
		currX= leftBorder+widInput2;
		currY = upB + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");  // TRY TO FILL HORIZONTAL IN THE END
				currX = currX + widInput2;

			}
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}

		result = (radInput*radInput*PI)-(countB)*(widInput2*lenInput2); // Calculating area
		cout<<"I could fit at most "<<countB<<" rectangles in container circle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;
	}

}
int triInCirc(double center,double radInput,double triInput2){
	int control = 0;
	int count = 0;
	double result;
	double rightBorder = (center+radInput*SQR2/2);
	double leftBorder = center-(radInput*SQR2/2);
	double upBorder = center-(radInput*SQR2/2);    // I drawed imaginary biggest square in circle and fill it
	double downBorder = center+(radInput*SQR2/2);
	double cLeftX = leftBorder;
	double cLeftY = upBorder+((triInput2/2)* SQR); // Calculating corner points
	double cMidX = leftBorder + (triInput2/2);
	double cMidY = upBorder;
	double cRightX = leftBorder + (triInput2);
	double cRightY = upBorder + ((triInput2/2)*SQR);
	while((downBorder-cLeftY)>=((triInput2/2)*SQR)||(downBorder-cMidY) >= ((triInput2/2)* SQR) || (downBorder-cRightY)>=((triInput2/2)* SQR)){
		while((rightBorder-cMidX) >= (triInput2*1)/2){
			if(control%2==1){
				cLeftY = cLeftY- ((triInput2/2)*SQR);
				cMidY = cMidY + ((triInput2/2)*SQR);				
				cRightY = cRightY - ((triInput2/2)*SQR);
			}
			else if(control%2 == 0 && control != 0){
				cLeftY = cLeftY+ ((triInput2/2)*SQR);
				cMidY = cMidY - ((triInput2/2)*SQR);				
				cRightY = cRightY + ((triInput2/2)*SQR);
			}
			drawTri(triInput2,cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY,"green"); // drawing
			count++;  // counting to calculate area
			cLeftX = cLeftX + (triInput2/2);
			cMidX = cMidX + (triInput2/2);
			cRightX = cRightX + (triInput2/2);
			control++;
		}
		control = 0;
		cLeftX = leftBorder;
		cMidX = leftBorder + (triInput2/2);
		cRightX = leftBorder + (triInput2);
		cLeftY = cLeftY + ((triInput2/2)*SQR);
		cMidY = cMidY + ((triInput2/2)*SQR);
		cRightY = cRightY + ((triInput2/2)*SQR);


	}
		result = (radInput*radInput*PI)-(count)*(triInput2*triInput2*SQR/4);
		cout<<"I could fit at most "<<count<<" triangles in container circle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;

}
int circInRec(double centerX,double centerY,double widInput,double lenInput,double radInput2){
	int control = 0;
	double result;
	double countA = 0;
	double countB = 0;
	double rightBorder = (centerX+widInput/2);
	double leftBorder = centerX-(widInput/2);   // calculating borders
	double upBorder = centerY-(lenInput/2);
	double downBorder = centerY+(lenInput/2);
	double currX = leftBorder + radInput2;
	double currY = upBorder + radInput2;
	while((downBorder-currY)>=((radInput2)*SQR/2)){
		if(control%2 == 1){
			currX = leftBorder + (2*radInput2);
		}
		else if(control%2 == 0){
			currX = leftBorder + radInput2;
		}
		while((rightBorder-currX)>= (radInput2)){    // I just count and compare below if it's better algorithm or not for input
			countA++;
			currX = currX + (2*radInput2);
		}
		control++;
		currY = currY + ((radInput2)*SQR);
	}

	control = 0;
	currX = leftBorder + radInput2;
	currY = upBorder + radInput2;
	while((downBorder-currY)>=((radInput2)*SQR/2)){
		if(control%2 == 1){
			currX = leftBorder + (2*radInput2);
		}
		else if(control%2 == 0){                       // second algorithm to place them
			currX = leftBorder + radInput2;
		}
		while((rightBorder-currX)>= (radInput2)){
			countB++;
			currX = currX + (2*radInput2);
		}
		currY = currY + ((radInput2)*2);
	}
	if(countA >= countB){
		currX = leftBorder + radInput2;
		currY = upBorder + radInput2;
		while((downBorder-currY)>=((radInput2)*SQR/2)){
			if(control%2 == 1){
				currX = leftBorder + (2*radInput2);
			}
			else if(control%2 == 0){
				currX = leftBorder + radInput2;    // choosing which algorithm is better
			}
			while((rightBorder-currX)>= (radInput2)){
				drawCirc(radInput2,currX,currY,"green");
				currX = currX + (2*radInput2);
			}
			control++;
			currY = currY + ((radInput2)*SQR);
		}
		result = (widInput*lenInput)-(countA)*(radInput2*radInput2*PI);
		cout<<"I could fit at most "<<countA<<" circles in container rectangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;
	}
	else if(countB > countA){
		currX = leftBorder + radInput2;
		currY = upBorder + radInput2;
		while((downBorder-currY)>=((radInput2)*SQR/2)){
			if(control%2 == 1){
				currX = leftBorder + (2*radInput2);
			}
			else if(control%2 == 0){
				currX = leftBorder + radInput2;           // If B > A we place normally
			}
			while((rightBorder-currX)>= (radInput2)){
				drawCirc(radInput2,currX,currY,"green");
				currX = currX + (2*radInput2);
			}
			currY = currY + ((radInput2)*2);
		}
		result = (widInput*lenInput)-(countB)*(radInput2*radInput2*PI);
		cout<<"I could fit at most "<<countB<<" circles in container rectangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;

	}



	return 0;

}
int recInRec(double centerX,double centerY,double widInput,double lenInput,double widInput2,double lenInput2){
	double rightBorder = (centerX+widInput/2);
	double leftBorder = centerX-(widInput/2);
	double upBorder = centerY-(lenInput/2); // calculating borders
	double downBorder = centerY+(lenInput/2);
	int countA = 0;
	int countB = 0;
	double result;
	double temp;
	double endOfL;
	double currX;
	double upB;
	double currY;
	currX= leftBorder+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){
			countA++;
			currX = currX + widInput2;

		}
		endOfL = currX-widInput2; // endOfL is to know where the row ends
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}

	temp = widInput2;
	widInput2 = lenInput2; // swapping values
	lenInput2 = temp;
	
	currX= endOfL+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){   // trying to fill empty places with swapping 
			countA++;
			currX = currX + widInput2;

		}
		currX = endOfL + widInput2;
		currY = currY + lenInput2;

	}

	//-------------------------------------
	
	currX= leftBorder+widInput2;
	currY = upBorder + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){      // changed sides and try like this
			countB++;
			currX = currX + widInput2;

		}
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}
	upB = currY-lenInput2;
	
		
	temp = widInput2;
	widInput2 = lenInput2;
	lenInput2 = temp;
	
	currX= leftBorder+widInput2;
	currY = upB + lenInput2;
	while((downBorder-currY)>= 0){
		while((rightBorder-currX)>=(0)){
			countB++;
			currX = currX + widInput2;

		}
		currX = leftBorder + widInput2;
		currY = currY + lenInput2;

	}
	if(countA >= countB){
			currX= leftBorder+widInput2;
		currY = upBorder + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green"); // Choosing which algorithm is better
				currX = currX + widInput2;

			}
			endOfL = currX-widInput2;
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}
					
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		
		currX= endOfL+widInput2;
		currY = upBorder + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");
				currX = currX + widInput2;

			}
			currX = endOfL + widInput2;
			currY = currY + lenInput2;

		}

		result = (widInput*lenInput)-(countA)*(widInput2*lenInput2);
		cout<<"I could fit at most "<<countA<<" rectangles in container rectangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;

	}
	
	else if(countB > countA){
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		currX= leftBorder+widInput2;
		currY = upBorder + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");
				currX = currX + widInput2;

			}
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}
		upB = currY-lenInput2;
		
			
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		
		currX= leftBorder+widInput2;
		currY = upB + lenInput2;
		while((downBorder-currY)>= 0){
			while((rightBorder-currX)>=(0)){
				drawRec(widInput2,lenInput2,currX,currY,"green");
				currX = currX + widInput2;

			}
			currX = leftBorder + widInput2;
			currY = currY + lenInput2;

		}
		result = (widInput*lenInput)-(countB)*(widInput2*lenInput2);
		cout<<"I could fit at most "<<countB<<" rectangles in container rectangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;



	}

}
int triInRec(double centerX,double centerY,double widInput,double lenInput,double triInput2){
	int control = 0;
	int count = 0;
	double result;
	double rightBorder = (centerX+widInput/2);
	double leftBorder = centerX-(widInput/2); // calculating borders
	double upBorder = centerY-(lenInput/2);
	double downBorder = centerY+(lenInput/2);
	double cLeftX = leftBorder;
	double cLeftY = upBorder+((triInput2/2)* SQR);	// calculating corner points of starting small triangle
	double cMidX = leftBorder + (triInput2/2);
	double cMidY = upBorder;
	double cRightX = leftBorder + (triInput2);
	double cRightY = upBorder + ((triInput2/2)*SQR);
	
	while((downBorder-cLeftY)>=((triInput2/2)*SQR)||(downBorder-cMidY) >= ((triInput2/2)* SQR) || (downBorder-cRightY)>=((triInput2/2)* SQR)){
		while((rightBorder-cMidX) >= (triInput2*1)/2){
			
			if(control%2==1){
				cLeftY = cLeftY- ((triInput2/2)*SQR);
				cMidY = cMidY + ((triInput2/2)*SQR);	  // I rotate the triangle degree of 180 here 			
				cRightY = cRightY - ((triInput2/2)*SQR);
			}
			else if(control%2 == 0 && control != 0){
				cLeftY = cLeftY+ ((triInput2/2)*SQR);
				cMidY = cMidY - ((triInput2/2)*SQR);				
				cRightY = cRightY + ((triInput2/2)*SQR);
			}
			drawTri(triInput2,cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY,"green");
			count++;
			cLeftX = cLeftX + (triInput2/2);
			cMidX = cMidX + (triInput2/2);
			cRightX = cRightX + (triInput2/2);
			control++;
		}
		control = 0;
		cLeftX = leftBorder;
		cMidX = leftBorder + (triInput2/2);
		cRightX = leftBorder + (triInput2);
		cLeftY = cLeftY + ((triInput2/2)*SQR); // after finishing row,changing coordinates
		cMidY = cMidY + ((triInput2/2)*SQR);
		cRightY = cRightY + ((triInput2/2)*SQR);


	}

		result = (widInput*lenInput)-(count)*(triInput2*triInput2*SQR/4);//calculating area
		cout<<"I could fit at most "<<count<<" triangles in container rectangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;

}
int circInTri(double centerX,double centerY,double triInput,double radInput2){
	double leftX = centerX-(triInput/2);
	double leftY = centerY + (triInput*SQR/6);
	double midX = centerX;                      // calculating coordinates of triangle
	double midY = centerY-(triInput*SQR/3);
	double rightX =  centerX+(triInput/2);
	double rightY = centerY + (triInput*SQR/6);
	int i = 0;
	double result;
	int count = 0;
	double currX = leftX + (radInput2*SQR);   
	double currY = leftY - radInput2;
	
	while((currY-midY)>=radInput2){
		while((rightX-currX)>=(radInput2*SQR)){
			drawCirc(radInput2,currX,currY,"green");
			count++;
			currX = currX+ (radInput2*2); // it moves horizontally

		}
		i++;
		rightX = rightX - (radInput2); // right corner getting shorter each row
		currX = leftX + (radInput2*SQR)+ (i*radInput2);
		currY = currY - (radInput2*SQR);

	}

		result = (triInput*triInput*SQR/4)-(count)*(radInput2*radInput2*PI);//calculating area
		cout<<"I could fit at most "<<count<<" circles in container triangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;



	
}
int recInTri(double centerX,double centerY,double triInput,double widInput2,double lenInput2){
	int countA = 0;
	int countB = 0;
	double result;
	double rPX;
	double temp;
	double leftX = centerX-(triInput/2);
	double leftY = centerY + (triInput*SQR/6);
	double midX = centerX;
	double midY = centerY-(triInput*SQR/3); // calculating corner points of triangle
	double rightX =  centerX+(triInput/2);
	rPX = rightX;
	double rightY = centerY + (triInput*SQR/6)- ((lenInput2)/SQR);
	double currX = leftX + ((lenInput2)/SQR);
	double currY = leftY - lenInput2;
	int i = 1;
	while((currY-midY)>=lenInput2/2){
		while((rPX-currX)>=(widInput2*2)){
			countA++;
			currX = currX + widInput2;
		}                                      // counting to choose better algorithm
		i++;
		rPX = rPX - (lenInput2/SQR);
		currX = leftX + i*(lenInput2/SQR);
		currY = currY - (lenInput2);

	}
	temp = widInput2;
	widInput2 = lenInput2;
	lenInput2 = temp;
	rPX = rightX;
	currX = leftX + ((lenInput2)/SQR);
	currY = leftY - lenInput2;
	while((currY-midY)>=lenInput2/2){
		while((rPX-currX)>=(widInput2*2)){   
			countB++;
			currX = currX + widInput2;
		}
		i++;					// counting to choose better algorithm
		rPX = rPX - (lenInput2/SQR);
		currX = leftX + i*(lenInput2/SQR);
		currY = currY - (lenInput2);

	}
	i = 1;
	if(countA >= countB){
		temp = widInput2;
		widInput2 = lenInput2;
		lenInput2 = temp;
		rPX = rightX;
		currX = leftX + ((lenInput2)/SQR);
		currY = leftY - lenInput2;			// if A > B place them horizontally
		while((currY-midY)>=lenInput2/2){
			while((rPX-currX)>=(widInput2*2)){
				drawRec(widInput2,lenInput2,currX+widInput2,currY+lenInput2,"green");
				currX = currX + widInput2;
			}
			i++;
			rPX = rPX - (lenInput2/SQR);
			currX = leftX + i*(lenInput2/SQR);
			currY = currY - (lenInput2);

		}

		result = (triInput*triInput*SQR/4)-(countA)*(widInput2*lenInput2);
		cout<<"I could fit at most "<<countA<<" rectangles in container triangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;


	}
	else if(countA < countB){
		rPX = rightX;
		currX = leftX + ((lenInput2)/SQR);
		currY = leftY - lenInput2;
		while((currY-midY)>=lenInput2/2){
			while((rPX-currX)>=(widInput2*2)){
				drawRec(widInput2,lenInput2,currX+widInput2,currY+lenInput2,"green");
				currX = currX + widInput2;	// if B > A place them vertically
			}
			i++;
			rPX = rPX - (lenInput2/SQR);
			currX = leftX + i*(lenInput2/SQR);
			currY = currY - (lenInput2);

		}
		result = (triInput*triInput*SQR/4)-(countB)*(widInput2*lenInput2);
		cout<<"I could fit at most "<<countB<<" rectangles in container triangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;


	}

}
int triInTri(double centerX,double centerY,double triInput,double triInput2){
	double leftX = centerX-(triInput/2);
	double leftY = centerY + (triInput*SQR/6);
	double midX = centerX;
	double midY = centerY-(triInput*SQR/3);
	double rightX =  centerX+(triInput/2);
	double rightY = centerY + (triInput*SQR/6); // we calculate big triangle coordinates and also for starting one
	double cLeftX = leftX;
	double cLeftY = leftY;
	double cMidX = leftX + (triInput2/2);
	double cMidY = leftY - ((triInput2)*SQR/2);
	double cRightX = cLeftX + (triInput2);
	double cRightY = cLeftY;
	int control = 0;
	double result;
	int count = 0;
	int i = 0;
	while((cMidY-midY)>=0 ){
		while((rightX-cRightX) >= 0){
			
			if(control%2==1){
				cLeftY = cLeftY- ((triInput2/2)*SQR);
				cMidY = cMidY + ((triInput2/2)*SQR);		//rotating triangle to place more		
				cRightY = cRightY - ((triInput2/2)*SQR);
			}
			else if(control%2 == 0 && control != 0){
				cLeftY = cLeftY+ ((triInput2/2)*SQR);
				cMidY = cMidY - ((triInput2/2)*SQR);				
				cRightY = cRightY + ((triInput2/2)*SQR);
			}
			drawTri(triInput2,cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY,"green");
			count++;
			cLeftX = cLeftX + (triInput2/2);
			cMidX = cMidX + (triInput2/2); // moving horizontally
			cRightX = cRightX + (triInput2/2);
			control++;
		}
		control = 0;
		i++;
		rightX = rightX - (triInput2/2);
		cLeftX = leftX + (i*triInput2/2);
		cMidX = cLeftX + (triInput2/2); // moving vertically
		cRightX = cLeftX + (triInput2);
		cLeftY = cLeftY - ((triInput2/2)*SQR);
		cMidY = cMidY - ((triInput2/2)*SQR);
		cRightY = cRightY - ((triInput2/2)*SQR);


	}
		result = (triInput*triInput*SQR/4)-(count)*(triInput2*triInput2*SQR/4); // calculating area
		cout<<"I could fit at most "<<count<<" triangles in container triangle"<<endl;
		cout<<"The area of red zone is = "<<result<<endl;	









}














