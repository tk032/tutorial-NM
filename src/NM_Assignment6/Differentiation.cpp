/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Yang Tae Kyun
Created          : 26-03-2018
Modified         : 18-05-2021
Language/ver     : C++ in MSVS2019

Description      : NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	6		// enter your assignment number
#define eval		0		// set 0

#include "myNM.h"



int main(int argc, char* argv[])
{
	/*	 [°ÿ DO NOT EDIT IT !!!]   Resources file path setting for evaluation	*/
	std::string path = "C:/NM_data_2021/Assignment" + std::to_string(Assignment) + "/";

#if eval
	path += "eval/";
#endif

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*	   : For each assignment, the file name will be notified on HISNET		*/
	/*==========================================================================*/

	double x[] = { -5.87, -4.23, -2.55, -0.89, 0.67, 2.09, 3.31, 4.31, 5.06, 5.55, 5.78, 5.77, 5.52, 5.08, 4.46, 3.72, 2.88, 2.00, 1.10, 0.23, -0.59 };
	double t[] = { 0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0 };
	

	// Q1
	printf("\n**************************************************");
	printf("\n|                   Question 1.                  |");
	printf("\n**************************************************\n");

	double xlength = sizeof(x) / sizeof(x[0]);                 //row size of x
	double tlength = sizeof(t) / sizeof(t[0]);                 //row size of t

	Matrix x_m = arr2Mat(x, xlength, 1);                       //1D-array to matrix
	Matrix t_m = arr2Mat(t, tlength, 1);					   //1D-array to matrix

	Matrix vel = gradient(t_m, x_m);
	Matrix acc = gradient(t_m, vel);

	printMat(t_m, "Matrix t");
	printMat(x_m, "Matrix x");
	printMat(vel, "vel");
	printMat(acc, "acc");


	// Q2
	printf("\n**************************************************");
	printf("\n|                   Question 2.                  |");
	printf("\n**************************************************\n");

	double dydx_a[21] = { 0 };							//xlength = 21 ¿Ãπ«∑Œ
	gradient1D(t, x, dydx_a, xlength);
	printf("1D array dydx= \n");
	for (int i = 0; i < xlength; i++)
		printf("\t%lf\n", dydx_a[i]);



	// Q3
	printf("\n**************************************************");
	printf("\n|                   Question 3.                  |");
	printf("\n**************************************************\n");

	Matrix xin = t_m;
	Matrix dydx = gradientFunc(myFunc, xin);

	printMat(xin, "xin");
	printMat(dydx, "dydx");


	// Q4
	printf("\n**************************************************");
	printf("\n|                   Question 4.                  |");
	printf("\n**************************************************\n");

	double tol = 0.00001;
	double x0 = 6;
	double NR_result = 0;
	printf("\nNewton-Raphson Method Results:\n");
	NR_result = newtonRaphsonFunc(myFunc, mydFunc, x0, tol);
	printf("Final Solution: %f \t", NR_result); 
	printf("\n");

	system("pause");
	return 0;
}

double myFunc(const double x) {
	double length = 4;
	double elastic = 70 * 1000000000;
	double inertia = 52.9 * 0.000001;
	double w0 = 20 * 1000;
	double F = w0 * (7 * pow(length, 4) - 30 * pow(length, 2) * pow(x, 2) + 15 * pow(x, 4)) / 360 / length / elastic / inertia;
	return F;

}

double mydFunc(const double x) {

	double length = 4;
	double elastic = 70 * 1000000000;
	double inertia = 52.9 * 0.000001;
	double w0 = 20 * 1000;
	double F = w0 * (-60 * pow(length, 2) * x + 60 * pow(x, 3)) / 360 / length / elastic / inertia;
	return F;
}



