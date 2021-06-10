/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Yang Tae Kyun
Created          : 26-03-2018
Modified         : 30-03-2021
Language/ver     : C++ in MSVS2019

Description      : NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	2		// enter your assignment number
#define eval		0		// set 0

#include "../../include/myNM.h"

int main(int argc, char* argv[])
{
	/*	 [※ DO NOT EDIT IT !!!]   Resources file path setting for evaluation	*/
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
	Matrix vecd = createMat(vecb.rows, vecb.cols);
	Matrix vecx = createMat(vecb.rows, vecb.cols);

	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// enter your algorithm here
	// enter your algorithm here
	// enter your algorithm here

	backSub(matU, vecd, vecx);       //backsub

	/// Q3

	

	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/
	printMat(matA, "matA");
	printMat(vecb, "vecb");
	gaussElim(matA, vecb, matU, vecd);          // Mat A의 값이 변경되어 순서를 바꿔줌
	backSub(matU, vecd, vecx);                  // GaussElim 다음 실행
	printMat(matU, "matrix U");
	printMat(vecd, "vector d");
	printMat(vecx, "vector x");

	/// Q3
	


	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(matA);		freeMat(vecb);
	freeMat(matU);		freeMat(vecd);


	system("pause");
	return 0;
}