/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [���±�]
Created          : 26-03-2018
Modified         : 18-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"



extern Matrix linearFit(Matrix _x, Matrix _y); 

extern Matrix arr2Mat(double* _1Darray, int _rows, int _cols);  
 
extern double linearFitVal(Matrix _x, Matrix _y, double _p);

extern Matrix linearInterp(Matrix _x, Matrix _y, Matrix _xq);

extern Matrix	gradient(Matrix _x, Matrix _y);

extern Matrix	gradientFunc(double func(const double x), Matrix xin);

extern void gradient1D(double* _1Darray_x, double* _1Darray_y, double* _1Darray_dydx, int m);

double Func(double _x);
 
double dFunc(double _x); 

double myFunc(const double x);

double mydFunc(const double x);

double newtonRaphson(double _x0, double _tol);

double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), float x0, float tol);

double trapz(double* _x, double* _y, int _m);

double integral(double func(const double x), double _a, double _b, int n);

double integralMid(double x[], double y[], int m);

double integral38(double func(const double x), double a, double b, int n);

extern Matrix MultMat(Matrix _A, Matrix _B);

// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);

// Apply back-substitution
extern	Matrix	backSub(Matrix _A, Matrix _b);

// A Mtrix�� ���� Gauss Elimination (rank Ȯ���ϱ� ����)
extern Matrix  gaussElim2(Matrix _A);

// Forward substitution
extern  void	fwdSub(Matrix _U, Matrix _d, Matrix _x);

// Gauss Elimination Method
extern	void	gaussElim(Matrix _A, Matrix _b, Matrix _U, Matrix _d);

// backsub 
extern  void	backSub(Matrix _U, Matrix _d, Matrix _x);

// LU decomposition
extern  void	LUdecomp(Matrix _A, Matrix _L, Matrix _U, Matrix _P);

// solve LU
extern void	solveLU(Matrix _L, Matrix _U, Matrix _P, Matrix _b, Matrix _x);
extern double	cond2(Matrix _A, Matrix _eig);

// Inverse Matrix
extern void inv(Matrix A, Matrix Ainv);

extern void QRdecomposition(Matrix _A, Matrix _Q, Matrix _R);           //QR factorization

extern void SimilarMat(Matrix _Q, Matrix _R, Matrix _U);

extern void diagElement(Matrix _U, Matrix _diag);

extern double	 norm(Matrix _A, Matrix _eig);

extern double	  cond(Matrix _A);
#endif
