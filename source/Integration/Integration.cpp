/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [���±�]
Created          : 17-05-2021
Modified         : 25-05-2021
Language/ver     : C++ in MSVS2019

Description      : [Tutorial]Integration_student.cpp
-------------------------------------------------------------------------------*/

#include "../../include/myNM.h"

// Integration using rectangular method for discrete data inputs
double IntegrateRect(double _x[], double _y[], int _m);

// You need to create myFunc() in this main source file

// You need to create trapz() and integral() in myNM.h. myNM.cpp


int main(int argc, char* argv[])
{
	// PART 1. Integration from Datasets
	printf("\n**************************************************");
	printf("\n        PART 1. Integration from Datasets         ");
	printf("\n**************************************************\n");

	double x[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
	double y[] = { 0, 3, 8, 20, 33, 42, 40, 48, 60, 12, 8, 4, 3 };
	int M = sizeof(x) / sizeof(x[0]);

	double I_rect = IntegrateRect(x, y, M);
	printf("I_rect  = %f\n", I_rect);

	double I_trapz = 0;
	// ADD YOUR CODE HERE  I_trapz=trapz()
	I_trapz = trapz(x, y, M); 
	printf("I_trapz = %f\n\n", I_trapz);

	

	// PART 2. Integration from a Function
	printf("\n**************************************************");
	printf("\n        PART 2. Integration from a Function       ");
	printf("\n**************************************************\n");
	
	double I_simpson13 = 0;
	// ADD YOUR CODE HERE.   I_simpson13=integral()
	I_simpson13 = integral(myFunc, -1, 1, 12); 
	printf("I_simpson13  = %f\n\n", I_simpson13);



	// PART 3. Integration from a Function
	printf("\n**************************************************");
	printf("\n        PART 3. Integration from a Function       ");
	printf("\n**************************************************\n");

	double I_Mid = integralMid(x, y, M);
	printf("I_Mid  = %f\n\n", I_Mid);

	// PART 4. Integration from a Function
	printf("\n**************************************************");
	printf("\n        PART 4. Integration from a Function       ");
	printf("\n**************************************************\n");

	double I_simpson38 = 0;
	// ADD YOUR CODE HERE.   I_simpson13=integral()
	I_simpson38 = integral38(myFunc, -1, 1, 12);
	printf("I_simpson38  = %f\n\n", I_simpson38);



	system("pause");
	return 0;
}




// Integration using rectangular method for discrete data inputs
double IntegrateRect(double _x[], double _y[], int _m) {
	int N = _m - 1;
	double I = 0;
	for (int i = 0; i < N; i++)
		I += _y[i] * (_x[i + 1] - _x[i]);

	return I;
}

double myFunc(const double x) {

	return sqrt(1 - (x * x));
}


