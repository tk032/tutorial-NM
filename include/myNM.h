/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [양태균]
Created          : 26-03-2018
Modified         : 18-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"


#define Eu		0
#define Em		1
#define PI		3.14159265358979323846


extern Matrix linearFit(Matrix _x, Matrix _y); 

extern Matrix arr2Mat(double* _1Darray, int _rows, int _cols);  
 
extern double linearFitVal(Matrix _x, Matrix _y, double _p);

extern Matrix linearInterp(Matrix _x, Matrix _y, Matrix _xq);

extern Matrix	gradient(Matrix _x, Matrix _y);

extern Matrix	gradientFunc(double func(const double x), Matrix xin);

extern void gradient1D(double* _1Darray_x, double* _1Darray_y, double* _1Darray_dydx, int m);

extern double bisectionNL(double _a0, double _b0, double _tol);			// Bisection Method

extern double newtonRaphson(double _x, double _tol);				    // NewtonRapshon Method

extern double Bonusfunc(double _x);									    // bonus problem y function

extern double BonusNR(double _x0, double _tol);

extern double HybridA(double _a0, double _b0, double _x0, double _tol); //bonus problem Hybrid algorithm

double Func(double _x);
 
double dFunc(double _x); 

double myFunc(const double x);

double mydFunc(const double x);

double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), float x0, float tol);

double trapz(double* _x, double* _y, int _m);

double integral(double func(const double x), double _a, double _b, int n);

double integralMid(double x[], double y[], int m);

double integral38(double func(const double x), double a, double b, int n);

void odeEU(double func(const double x, const double y), double v[], double t0, double tf, double h);

void odeEM(double func(const double x, const double y), double v[], double t0, double tf, double h);

void ode(double func(const double x, const double y), double v[], double t0, double tf, double h, int method);

void odeRK2(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0);

void odeRK4(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0);

void sys2RK2(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init);
void sys2RK4(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init);

extern Matrix MultMat(Matrix _A, Matrix _B);

// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);

// Apply back-substitution
extern	Matrix	backSub(Matrix _A, Matrix _b);

// A Mtrix에 대한 Gauss Elimination (rank 확인하기 위해)
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
