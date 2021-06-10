/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Jan Park, YKKIM
Created          : 2021-06-03
Modified         : 2021-06-03  by YKKIM
Language/ver     : C++ in MSVS2017

Description      : [Tutorial]ODE_IVP_student.c
-------------------------------------------------------------------------------*/


#include "../../include/myNM.h"
#include <stdio.h>
#include <math.h>

#define ODE_EU 0
#define ODE_EM 1
#define ODE_RK2 2
#define ODE_RK4 3

//  PI is defined in  myNM.h
#define PI 3.14159265368979323846264338327950288412


double odeFunc_rc(const double x, const double y);
void odeFunc_mck(const double t, const double Y[], double dYdt[]);

// Single Equation : odeEM, odeEU
//void odeEU(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0);
//void odeEM(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0);



// 2nd order Equations : sys2RK2, sys2RK4



int main(int argc, char* argv[])
{

	/*-------------------------------------------------------------------*/
	// Single of 1st Order ODE
	/*-------------------------------------------------------------------*/

	//Parameter Definitions
	double a = 0;
	double b = 0.1;
	double h = 0.001;
	unsigned int N = (b - a) / h + 1;
	double y_EU[200] = { 0 };				//Cannot use y_EU[N]     array 사용시 임의로 크게  
	double y_EM[200] = { 0 };
	double y_RK2[200] = { 0 };
	double y_RK4[200] = { 0 };

	// Initial value
	double v0 = 0;

	// ODE solver
	odeEU(odeFunc_rc, y_EU, a, b, h);
	odeEM(odeFunc_rc, y_EM, a, b, h);


	////////////////////////////////////////////////	
	// Exercise 1: Create a general form for RK2
	odeRK2(odeFunc_rc, y_RK2, a, b, h, v0);

	// Exercise 2: Create the standard form  for RK4
	odeRK4(odeFunc_rc, y_RK4, a, b, h, v0);
	////////////////////////////////////////////////


	// Print outputs
	printf("/*-----------------------*/\n");
	printf("/ Single of 1st Order ODE /\n");
	printf("/*-----------------------*/\n");
	printf(" - Total number of data N=%d \n", N);
	for (int i = 0; i < N; i++)
		printf("t= %f\tyEU= %f\tyEM= %f\tyRK2= %f\tyRK4= %f\n", a + i * h, y_EU[i], y_EM[i], y_RK2[i], y_RK4[i]);
	printf("\n");



	/*-------------------------------------------------------------------*/
	// 2nd Order ODE : MCK example
	/*-------------------------------------------------------------------*/

	//Parameter Definitions
	double t0 = 0;
	double tf = 1;
	h = 0.01;
	N = (tf - t0) / h + 1;
	double y[200] = { 0 };
	double v[200] = { 0 };

	// Initial values
	double y0 = 0;
	v0 = 0.2;

	// ODE solver: RK2
	sys2RK2(odeFunc_mck, y, v, t0, tf, h, y0, v0);

	///////////////////////////////////////////////////////////////
	// Exercise 3: Create the standard form  for RK4 for 2nd order	
	//sys2RK4(odeFunc_mck, y, v, t0, tf, h, y0, v0);



	// Print outputs
	printf("/*---------------------------*/\n");
	printf("/ 2nd Order ODE : MCK example /\n");
	printf("/*---------------------------*/\n");
	printf(" - Total number of data N=%d \n", N);
	for (int i = 0; i < N; i++)
		printf("t= %f\ty= %f\tv= %f\n", t0 + i * h, y[i], v[i]);
	printf("\n\n");


	// Copy and paste the output in MATLAB and PLOT
	for (int i = 0; i < N; i++)
		printf("%f\t%f\t%f\n", t0 + i * h, y[i], v[i]);


	system("pause");
	return 0;
}

// Gradient function for ODE - 1st order single eq.
double odeFunc_rc(const double x, const double y) {
	double tau = 1;
	double T = 1 / tau;
	double f = 10;
	double Vm = 1;
	double w = 2 * PI * f;

	return  -T * y + T * Vm * cos(w * x);
}

void odeFunc_mck(const double t, const double Y[], double dYdt[])
{
	double m = 1;
	double c = 7;
	double k = 6.9;
	double f = 5;

	double Fin = 2 * cos(2 * PI * f * t);

	dYdt[0] = Y[1];

	// EXERCISE: MODIFY HERE
	//Y[0] == y(t);
	//Y[1] == z(t);
	//dYdt[0] = z(t) = Y[1];
	//dYdt[1] = zdot;


	// HINT;   zdot= (-k*Y - c*Z + Fin)/m;
	dYdt[1] = (-k * Y[0] - c - Y[1] + Fin) / m;
}



/*---------------------------------------------------------------------------------------------------------------------------*/
