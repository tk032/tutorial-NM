/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Jan Park
Created          : 10-05-2021
Modified         : 10-05-2021
Language/ver     : C++ in MSVS2019

Description      : ODE
-------------------------------------------------------------------------------*/

#include "../../include/myNM.h"

// Define a function that defines the target equation.
double myFunc(const double x, const double y);
int main(int argc, char* argv[])
{

	// PART 1
	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");
	double a = 0;
	double b = 0.1;
	double h = 0.001;
	double y[100];
	double t[100] = { 0 };
	odeEU(myFunc, y, a, b, h);

	for (int i = 0; i < 99; i++) {
		t[i + 1] = t[i] + h;
		printf("Time : %lf \t\t v : %lf \n",t[i] ,y[i]);
	
	}

	printf("Time : %lf \t\t v : %lf \n", t[99], y[99]);          // for문에서 100열 출력 불가
	// PART 2
	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");
	odeEM(myFunc, y, a, b, h);

	for (int i = 0; i < 99; i++) {
		t[i + 1] = t[i] + h;
		printf("Time : %lf \t\t v : %lf \n", t[i], y[i]);

	}

	printf("Time : %lf \t\t v : %lf \n", t[99], y[99]);           // for문에서 100행 출력 불가


	// PART 3
	printf("\n**************************************************");
	printf("\n|                     PART 3.                    |");
	printf("\n**************************************************\n");
	ode(myFunc, y, a, b, h, Em); 

	for (int i = 0; i < 99; i++) {
		t[i + 1] = t[i] + h;
		printf("Time : %lf \t\t v : %lf \n", t[i], y[i]);

	}

	printf("Time : %lf \t\t v : %lf \n", t[99], y[99]);
	system("pause");
	return 0;
}


// Define a function that defines the target equation.
double myFunc(const double x, const double y) {
	double tau = 1;
	double T = 1 / tau;
	double f = 10;
	double Vm = 1;
	double w = 2 * PI * f;

	return  -T * y + T * Vm * cos(w * x );
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