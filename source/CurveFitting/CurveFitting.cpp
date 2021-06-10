/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Yang Tae Kyun
Created          : 26-03-2018
Modified         : 11-05-2021
Language/ver     : C++ in MSVS2019

Description      : NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	5		// enter your assignment number
#define eval		0		// set 0

#include "../../include/myNM.h"

int main(int argc, char* argv[])
{
	/*	 [¡Ø DO NOT EDIT IT !!!]   Resources file path setting for evaluation	*/
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

	// Q1
	printf("\n**************************************************");
	printf("\n|                   Question 1.                  |");
	printf("\n**************************************************\n");
	Matrix T = txt2Mat(path, "vecT");
	Matrix P = txt2Mat(path, "vecP");
	Matrix z = linearFit(T, P);



	printMat(T, "T");
	printMat(P, "P");
	printMat(z, "z");

	double p = linearFitVal(T, P, 150);
	printf("Predict the pressure at T = 150C  :  %lf\n", p);


	// Q2
	printf("\n**************************************************");
	printf("\n|                   Question 2.                  |");
	printf("\n**************************************************\n");

	double T2[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 };
	double T3[] = { 75 };          //  Value 75C

	
	Matrix xq = arr2Mat(T2, 21, 1);
	Matrix yq = createMat(xq.rows, xq.cols);
	Matrix xp = arr2Mat(T3, 1, 1);
	Matrix yp = createMat(xp.rows, xp.cols);

	initMat(yq, 0);
	initMat(yp, 0);
	yq = linearInterp(T, P, xq);
	yp = linearInterp(T, P, xp);

	printMat(xq, "xq");
	printMat(yq, "yq");			//estimate T = 0:5:100
	printMat(xp, "xp");       
	printMat(yp, "yp");			//estimate 75C


	system("pause");
	return 0;
}
