/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [¾çÅÂ±Õ]
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
#endif
