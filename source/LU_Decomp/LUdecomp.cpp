
/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Yang Tae Kyun
Created          : 26-03-2018
Modified         : 06-04-2021
Language/ver     : C++ in MSVS2019

Description      : NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	3		// enter your assignment number
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
	Matrix matA = txt2Mat(path, "prob1_matA");
	Matrix vecb = txt2Mat(path, "prob1_vecb");
	Matrix matU = createMat(matA.rows, matA.cols);
	Matrix matL = createMat(matA.rows, matA.cols);
	Matrix matP = createMat(matA.rows, matA.cols);
	Matrix vecx = createMat(vecb.rows, vecb.cols);
	Matrix Ainv = createMat(matA.rows, matA.cols);
	Matrix matAinv = createMat(matA.rows, matA.cols);
	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// enter your algorithm here
	// enter your algorithm here
	// enter your algorithm here



	printMat(matA, "matrix A");
	LUdecomp(matA, matL, matU, matP);							  //	LUdecomp function
	solveLU(matL, matU, matP, vecb, vecx);						  //	solve LU function
	inv(matA, matAinv);											  //    inverse Matrix
	
	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/

	printMat(vecb, "vecb");
	printMat(matL, "matrix L");
	printMat(matU, "matrix U");
	printMat(matP, "matrix P");
	printMat(vecx, "vecx");
	printMat(matAinv, "Ainv");
	Ainv = MultMat(matAinv, vecb);								  //    Ainv*b
	printMat(Ainv, "vecx = Ainv*b");

	


	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(matA);		freeMat(matL);		freeMat(vecx);		freeMat(matAinv);
	freeMat(matU);		freeMat(matP);		freeMat(vecb);


	system("pause");
	return 0;
}