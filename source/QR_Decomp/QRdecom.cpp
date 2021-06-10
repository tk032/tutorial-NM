/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Yang Tae Kyun
Created          : 26-03-2018
Modified         : 30-04-2021
Language/ver     : C++ in MSVS2019

Description      : NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	4		// enter your assignment number
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

	// Q2
	printf("\n**************************************************");
	printf("\n|                   Question 1.                  |");
	printf("\n**************************************************\n");
	Matrix matA = txt2Mat(path, "matA");
	Matrix U = createMat(matA.rows, matA.cols);
	Matrix Q = createMat(matA.rows, matA.cols);
	Matrix R = createMat(matA.rows, matA.cols);
	Matrix diag = createMat(matA.rows, 1);


	Matrix matC = txt2Mat(path, "matC");

	double Sig1 = 0.0;
	double Sig2 = 0.0;

	initMat(Q, 0);
	initMat(R, 0);
	initMat(U, 0);


	QRdecomposition(matA, Q, R);                     //QR decomposition
	SimilarMat(Q,R, U);                             // Find SimilarMat
	diagElement(U, diag);


	printMat(Q, "Q");
	printMat(R, "R");
	printMat(U, "U");
	printMat(diag, "diagonal");



	// Q2
	printf("\n**************************************************");
	printf("\n|                   Question 2.                  |");
	printf("\n**************************************************\n");


	printf("MatA : \n\n");
	Sig1 = cond(matA); 

	printf("MatC : \n\n");
	Sig2 = cond(matC);

	printf("Square-root the ratio of max-min values of Cond(A) = %f\n\n", Sig1);
	printf("Square-root the ratio of max-min values of Cond(C) = %f\n\n", Sig2);




	system("pause");
	return 0;
}
