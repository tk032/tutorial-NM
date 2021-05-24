/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [양태균]
Created          : 26-03-2018
Modified         : 18-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"


double Func(double _x) // dy/dx 함수
{

	return _x;
}





double dFunc(double _x) // dy/dx의 도함수
{

	return _x;
}






double newtonRaphson(double _x0, double _tol) //NewtonRaphson Method
{
	int k = 0;
	int Nmax = 1000;
	double x = _x0;
	double xn = 0;
	double ep = 1000;

	if (dFunc(x) == 0)
		printf("\n함수의 기울기가 0 입니다. 초기값을 변경해주세요\n\n");   // 도함수 크기가 0 이면 오류이므로 실행하지 않음
	else                                                                   // 도함수 크기가 0이 아니면 실행
	{
		do {
			xn = x - Func(x) / dFunc(x);                                     // xn+1 에 대한 식
			ep = fabs(Func(xn));
			printf("Iteration:%d \t", k);
			printf("X(n): %f \t", xn);
			printf("Tolerance: %.10f\n", ep);
			x = xn;
			k++;
		} while (k<Nmax && ep>_tol);
	}

	return xn;
}



Matrix	linearFit(Matrix _x, Matrix _y) {
	int mx = _x.rows;
	int my = _y.rows;

	double a1 = 0;
	double a0 = 0;
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;

	if ((mx != my) || (mx < 2)) {
		printf("ERROR: length of x and y must be equal and more than 1 ");
	}
	else
		for (int k = 0; k < mx; k++)                      //SUM 
		{ 
			Sx = Sx + _x.at[k][0];                     
			Sxx = Sxx + _x.at[k][0] * _x.at[k][0]; 
			Sy = Sy + _y.at[k][0];
			Sxy = Sxy + _y.at[k][0] * _x.at[k][0];
		}

	a1 = (mx * Sxy - Sx * Sy) / (mx * Sxx - Sx * Sx);      //slope
	a0 = (Sxx * Sy - Sxy * Sx) / (mx * Sxx - Sx * Sx);     //offset


	double z_array[] = { a1, a0 };
	return arr2Mat(z_array, 2, 1);
}

double linearFitVal(Matrix _x, Matrix _y, double _p) {

	double a1 = 0.0;
	double a0 = 0.0;
	Matrix z = linearFit(_x, _y);

	a0 = z.at[0][0] ;
	a1 = z.at[1][0] ;

	return  a0 * _p + a1;
	

}

Matrix linearInterp(Matrix _x, Matrix _y, Matrix _xq) {

	Matrix Out = createMat(_xq.rows, _xq.cols);

		for (int i = 0; i < _x.rows - 1; i++)
		{
			for (int k = 0; k < _xq.rows; k++) {                                    //구간 찾기
				if (_x.at[i][0] <= _xq.at[k][0] && _xq.at[k][0] <= _x.at[i + 1][0])
					Out.at[k][0] = _y.at[i][0] + (_y.at[i + 1][0] - _y.at[i][0]) / (_x.at[i + 1][0] - _x.at[i][0]) * (_xq.at[k][0] - _x.at[i][0]);  // Linear Spline
			}
		}
	return Out;
}

Matrix	gradient(Matrix _x, Matrix _y) {

	int n = _x.rows;
	double h = _x.at[1][0] - _x.at[0][0];
	Matrix Out = createMat(_x.rows, _x.cols);
	if (n > 2) {
		for (int i = 0; i < _x.rows; i++) {
			if (i == 0){
				Out.at[i][0] = (-3 * _y.at[i][0] + 4 * _y.at[i + 1][0] - _y.at[i + 2][0]) / (2 * h);
			}
			if (i < _x.rows - 1 && i > 0){
				Out.at[i][0] = (_y.at[i + 1][0] - _y.at[i - 1][0]) / (2 * h);
			}
			if (i == _x.rows - 1){
				Out.at[i][0] = (3 * _y.at[i][0] - 4 * _y.at[i - 1][0] + _y.at[i - 2][0]) / (2 * h);
			}
		}
	}
	else if (n == 2) {
		Out.at[0][0] = (_y.at[1][0] - _y.at[0][0]) / h;
		Out.at[1][0] = (_y.at[1][0] - _y.at[0][0]) / h;
	}
	else
		Out.at[0][0] = 0;
	    Out.at[1][0] = 1;

	return Out;
}
	
Matrix	gradientFunc(double func(const double x), Matrix xin) {
	int n = xin.rows;
	Matrix y = createMat(n, 1);
	Matrix df = createMat(n, 1);



    // define y[0] to y[n-1]
	for (int i = 0; i < n; i++)
		y.at[i][0] = func(xin.at[i][0]);
	// Numerical differentiation

	return gradient(xin, y);

}

void gradient1D(double* _1Darray_x, double* _1Darray_y, double* _1Darray_dydx, int m) {
	double h = _1Darray_x[1] - _1Darray_x[0];
	if (m > 2) {
		for (int i = 0; i < m; i++) {
			if (i == 0)
				_1Darray_dydx[i] = (-3 * _1Darray_y[i] + 4 * _1Darray_y[i + 1] - _1Darray_y[i + 2]) / (2 * h); // 3point forward
			if (i < m - 1 && i > 0)
				_1Darray_dydx[i] = (_1Darray_y[i + 1] - _1Darray_y[i - 1]) / (2 * h);                          // 2point centural
			if (i == m - 1)
				_1Darray_dydx[i] = (3 * _1Darray_y[i] - 4 * _1Darray_y[i - 1] + _1Darray_y[i - 2]) / (2 * h);  // 3point backward
		}
	}
	else if (m == 2) {
		_1Darray_dydx[0] = (_1Darray_y[1] - _1Darray_y[0]) / h;
		_1Darray_dydx[1] = (_1Darray_y[1] - _1Darray_y[0]) / h;
	}
	else
		_1Darray_dydx[0] = 0;
		_1Darray_dydx[1] = 1;
}

double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), float x0, float tol) {

		int k = 0;
		int Nmax = 1000;
		double x = x0;
		double xn = 0;
		double ep = 1000;

		if (func(x) == 0)
			printf("\n함수의 기울기가 0 입니다. 초기값을 변경해주세요\n\n");   // 도함수 크기가 0 이면 오류이므로 실행하지 않음
		else                                                                   // 도함수 크기가 0이 아니면 실행
		{
			do {
				xn = x - func(x) / dfunc(x);                                     // xn+1 에 대한 식
				ep = fabs(func(xn));
				printf("Iteration:%d \t", k);
				printf("X(n): %f \t", xn);
				printf("Tolerance: %.10f\n", ep);
				x = xn;
				k++;
			} while (k<Nmax && ep>tol);
		}


	return xn;


}

