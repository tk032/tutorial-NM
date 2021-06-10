/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [���±�]
Created          : 26-03-2018
Modified         : 18-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"


double Func(double _x) // dy/dx �Լ�
{

	return _x;
}





double dFunc(double _x) // dy/dx�� ���Լ�
{

	return _x;
}


double bisectionNL(double _a0, double _b0, double _tol) // BisectionMethod
{
	int k = 0;
	int nmax = 1000;
	double a = _a0;
	double b = _b0;
	double xn = 0;
	double ep = 1000;

	// you should check     if(Func(a) * Func(b) >= 0)
	// what should you do for this condition?

	if (Func(a) * Func(b) >= 0)
		printf("\n�� �Լ� ���� ��ȣ�� �����ϴ�. �ʱⰪ�� �������ּ���\n\n");   //��ȣ�� ���� ��� ��� + �������� ����
	else                                                                         //��ȣ�� �ٸ� ��� �Լ� ����
	{
		do {
			xn = (a + b) / 2;
			ep = fabs(Func(xn));
			printf("iteration:%d \t", k);
			printf("x(n): %f \t", xn);
			printf("tolerance: %.10f\n", ep);

			if (Func(a) * Func(xn) < 0)
				b = xn;
			else
				a = xn;
			k++;
		} while (k<nmax && ep>_tol);
	}

	return xn;
}



//-----------------------------------  Bonus  --------------------------------------------------//





double Bonusfunc(double _x)     // y = 1/x - 2  function
{
	double x = _x;
	double F = 1 / x - 2;
	return F;
}





double Bonusdfunc(double _x)     // y = 1/x - 2  function
{
	double x = _x;
	double F = -1 / pow(_x, 2);
	return F;
}

double BonusNR(double _x0, double _tol)                                    //Bonus problem ���� ����� NewtonRaphson Method
{
	int k = 0;
	int Nmax = 1000;
	double x = _x0;
	double xn = 0;
	double ep = 1000;

	if (Bonusdfunc(x) == 0)
		printf("\n�Լ��� ���Ⱑ 0 �Դϴ�. �ʱⰪ�� �������ּ���\n\n");   // ���Լ� ũ�Ⱑ 0 �̸� �����̹Ƿ� �������� ����
	else                                                                   // ���Լ� ũ�Ⱑ 0�� �ƴϸ� ����
	{
		do {
			xn = x - Bonusfunc(x) / Bonusdfunc(x);                         //  �Լ��� Bonusfunc ���� �ٲ�
			ep = fabs(Bonusfunc(xn));
			printf("Iteration:%d \t", k);
			printf("X(n): %f \t", xn);
			printf("Tolerance: %.10f\n", ep);
			x = xn;
			k++;
		} while (k<Nmax && ep>_tol);
	}

	return xn;
}


double HybridA(double _a0, double _b0, double _x0, double _tol)// BonusProblem hybrid algorithm 
{
	int k = 0;
	int i = 0;
	int Nmax = 1000;
	double a = _a0;
	double b = _b0;
	double x = _x0;
	double xn = 0;
	double ep = 1000;


	while (i < 100)                                                    // 100�� ���� �߻����� ����
	{
		xn = x - Bonusfunc(x) / Bonusdfunc(x);                         //  �Լ��� Bonusfunc ���� �ٲ�
		ep = fabs(Bonusfunc(xn));
		printf("Iteration:%d \t", k);
		printf("X(n): %f \t", xn);
		printf("Tolerance: %.10f\n", ep);
		x = xn;
		if (x < a || x > b)                                             //bound ���� �ظ� �� �� break
		{
			k++;
			break;
		}
		else
			k++;
		i++;
	}
	if (ep > _tol)                                                     //�߻��� �� Ȥ�� bound ���� �ظ� �� �� bisection ����
	{
		if (xn >= b)                                                   //xn �� bound[a b] �� �ʱⰪ ����
			xn = (x + a) / 2;
		else if (xn <= a)
			xn = (x + b) / 2;
		do {
			ep = fabs(Bonusfunc(xn));
			printf("iteration:%d \t", k);
			printf("x(n): %f \t", xn);
			printf("tolerance: %.10f\n", ep);

			if (Bonusfunc(a) * Bonusfunc(xn) < 0)
				b = xn;
			else
				a = xn;
			xn = (a + b) / 2;
			k++;
		} while (k<Nmax && ep>_tol);
	}

	return xn;
}

double newtonRaphson(double _x0, double _tol) //NewtonRaphson Method
{
	int k = 0;
	int Nmax = 1000;
	double x = _x0;
	double xn = 0;
	double ep = 1000;

	if (dFunc(x) == 0)
		printf("\n�Լ��� ���Ⱑ 0 �Դϴ�. �ʱⰪ�� �������ּ���\n\n");   // ���Լ� ũ�Ⱑ 0 �̸� �����̹Ƿ� �������� ����
	else                                                                   // ���Լ� ũ�Ⱑ 0�� �ƴϸ� ����
	{
		do {
			xn = x - Func(x) / dFunc(x);                                     // xn+1 �� ���� ��
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
			for (int k = 0; k < _xq.rows; k++) {                                    //���� ã��
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
			printf("\n�Լ��� ���Ⱑ 0 �Դϴ�. �ʱⰪ�� �������ּ���\n\n");   // ���Լ� ũ�Ⱑ 0 �̸� �����̹Ƿ� �������� ����
		else                                                                   // ���Լ� ũ�Ⱑ 0�� �ƴϸ� ����
		{
			do {
				xn = x - func(x) / dfunc(x);                                     // xn+1 �� ���� ��
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

double trapz(double* _x, double* _y, int _m) {
	double SUM = 0;
	//data : m
	//interval N = m - 1
	double N = _m - 1;
	for (int i = 0; i < N; i++) {
		SUM += (_y[i] + _y[i + 1]) * (_x[i + 1] - _x[i]);
	}
	return 0.5 * SUM;
}

double integral(double func(const double x), double _a, double _b, int _n) {
	double x0 = _a;
	double h = (_b - _a) / _n;
	double SUM = 0;
	for (double i = 2; i <= _n; i += 2) {             // N = 0  ~  N = N - 1 ��
		SUM += 4 * func(x0 + h * (i - 1)) + 2 * func(x0 + h * (i - 2));
	}
	SUM += func(x0 + h * _n);                     //  N = N ��    

	return SUM * h / 3;
}

double integralMid(double x[], double y[], int m) {
	double SUM = 0;
	for (int i = 0; i < m - 2; i += 2) {
		SUM += (y[i + 1]) * (x[i + 2] - x[i]);        //
	}
	return SUM;
}

double integral38(double func(const double x), double a, double b, int n) {
	double x0 = a;
	double h = (b - a) / n;
	double SUM = 0;
	for (double i = 3; i <= n; i += 3) {             // N = 1  ~  N = N - 1 ��
		SUM += 3 * (func(x0 + h * (i - 2)) + func(x0 + h * (i - 1))) + 2 * func(x0 + h * (i - 3));
	}
	SUM += func(x0 + h * n) + func(x0);                     // N = 0,  N = N ��    

	return SUM * h * 3 / 8;

}

Matrix	transpose(Matrix _A) {
	Matrix Out = createMat(_A.cols, _A.rows);

	for (int i = 0; i < _A.cols; i++)
		for (int j = 0; j < _A.rows; j++)
			Out.at[i][j] = _A.at[j][i];
	return Out;
}

// multiply Matrix
Matrix MultMat(Matrix _A, Matrix _B) {
	if (_A.cols != _B.rows)                                                         // Matrix A�� ��, Matrix b�� ���� ���� �ٸ��� ����(��� �Ұ�)
	{
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'MultMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}
	Matrix Out1 = createMat(_A.rows, _B.cols);

	for (int i = 0; i < _A.rows; i++)                      //  Out �ʱⰪ
		for (int j = 0; j < _B.cols; j++)
			Out1.at[i][j] = 0;

	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _B.cols; j++) {
			for (int k = 0; k < _A.cols; k++)
				Out1.at[i][j] += _A.at[i][k] * _B.at[k][j];
		}
	}

	return Out1;
}

// Matrix addition
Matrix	addMat(Matrix _A, Matrix _B)
{
	if (_A.rows != _B.rows || _A.cols != _B.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'addMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}

	Matrix Out = createMat(_A.rows, _B.cols);
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _B.cols; j++)
			Out.at[i][j] = _A.at[i][j] + _B.at[i][j];

	return Out;
}

// Apply back-substitution
void	backSub(Matrix _U, Matrix _d, Matrix _x)
{


	// error check: whether _A is a triangular matrix

	//for (int i = _A.rows; i > 0; i--) {
	//	double temp = 0;
	//	for (int j = i + 1; j <= _A.cols; j++)
	//		temp += _A.at[i - 1][j - 1] * Out.at[j - 1][0];
	//	Out.at[i - 1][0] = (_b.at[i - 1][0] - temp) / _A.at[i - 1][i - 1];
	//}

	for (int i = _U.rows - 1; i >= 0; i--) {
		double temp = 0;
		for (int j = i + 1; j < _U.cols; j++)
			temp += _U.at[i][j] * _x.at[j][0];
		_x.at[i][0] = (_d.at[i][0] - temp) / _U.at[i][i];
	}
}

void	fwdSub(Matrix _U, Matrix _d, Matrix _x) {
	for (int i = 0; i < _U.rows; i++) {
		double temp = 0;
		for (int j = 0; j < i; j++) {
			temp += _U.at[i][j] * _x.at[j][0];
		}
		_x.at[i][0] = (_d.at[i][0] - temp) / _U.at[i][i];
	}
}



void  gaussElim(Matrix _A, Matrix _b, Matrix _U, Matrix _d)
{

	if (_A.rows != _A.cols) {                                                            // Square Matrix�� �ƴϸ� ����
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		initMat(_U, 0);
		initMat(_d, 0);
	}
	else if (_A.cols != _b.rows)                                                         // Matrix A�� ��, Matrix b�� ���� ���� �ٸ��� ����(��� �Ұ�)
	{
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'gaussElim' function");
		printf("\n*************************************************\n");
		initMat(_U, 0);
		initMat(_d, 0);
	}
	else if (_A.at[0][0] == 0) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: function cannot be divided by zero");
		printf("\n*************************************************\n");
		initMat(_U, 0);
		initMat(_d, 0);
	}

	Matrix M = createMat(_A.rows, _A.cols);
	initMat(M, 0);
	//�ʱⰪ
	for (int n = 0; n < _A.cols; n++)                            // ù ��° ���� �ʱⰪ
	{
		_U.at[0][n] = _A.at[0][n];
		_d.at[0][0] = _b.at[0][0];
	}

	for (int k = 0; k < _A.rows - 1; k++) {
		for (int i = k + 1; i < _A.rows; i++) {
			M.at[0][k] = _A.at[i][k] / _A.at[k][k];
			for (int j = k; j < _A.cols; j++) {
				_A.at[i][j] = _A.at[i][j] - M.at[0][k] * _A.at[k][j];
				_U.at[i][j] = _A.at[i][j];

			}
			_b.at[i][0] = _b.at[i][0] - M.at[0][k] * _b.at[k][0];
			_d.at[i][0] = _b.at[i][0];
		}
	}

}

Matrix  gaussElim2(Matrix _A)													         //�Է��ϳ� A matrix �� ���ؼ��� ���콺 �ҰŹ�(rank Ȯ���ϱ� ����)
{

	if (_A.rows != _A.cols) {                                                            // Square Matrix�� �ƴϸ� ����
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}


	int x = 0;												// for�� ����
	int y = 0;                                              // for�� ����
	int Pidx = 0;
	double temp = 0;


	Matrix M = createMat(_A.rows, _A.cols);
	Matrix Out = createMat(_A.rows, _A.cols);
	initMat(M, 0);
	//�ʱⰪ

	for (int k = 0; k < _A.rows - 1; k++) {
		Pidx = k;
		for (x = k + 1; x < _A.cols; x++) {
			if (abs(_A.at[x][k]) > abs(_A.at[Pidx][k])) {        // Find Pivot
				Pidx = x;
			}
			for (y = k; y < _A.rows; y++) {
				temp = _A.at[Pidx][y];
				_A.at[Pidx][y] = _A.at[k][y];					// A matrix change row
				_A.at[k][y] = temp;
			}
			for (int i = k + 1; i < _A.rows; i++) {
				M.at[0][k] = _A.at[i][k] / _A.at[k][k];
				for (int j = k; j < _A.cols; j++) {
					_A.at[i][j] = _A.at[i][j] - M.at[0][k] * _A.at[k][j];
					Out.at[i][j] = _A.at[i][j];

				}
			}
		}
	}
	return Out;
}


void	LUdecomp(Matrix _A, Matrix _L, Matrix _U, Matrix _P) {                           //input _A, Output _L, _U, _P


	if (_A.rows != _A.cols) {                                                            // Square Matrix�� �ƴϸ� ����
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		initMat(_U, 0);

	}


	Matrix X = createMat(_A.rows, _A.cols);					// A matrix ���� �ϱ� ���� X matrix�� ��ü
	Matrix M = createMat(_A.rows, _A.cols);
	Matrix I = createMat(_A.rows, _A.cols);					// Identity Matrix
	initMat(M, 0);											// M �ʱⰪ
	initMat(X, 0);
	initMat(I, 0);
	initMat(_L, 0);                                         // L matrix �ʱⰪ
	initMat(_P, 0);											// P matrix �ʱⰪ = 0

	int x = 0;												// for�� ����
	int y = 0;                                              // for�� ����
	int Pidx = 0;
	double temp = 0;


	for (x = 0; x < _A.cols; x++) {                         // P matrix �ʱⰪ = Identity Matrix
		for (y = 0; y < _A.rows; y++) {						// Identity Matrix
			if (x == y) {
				_P.at[x][y] = 1;
				I.at[x][y] = 1;
			}
			else {
				_P.at[x][y] = 0;
				I.at[x][y] = 0;
			}
		}
	}



	for (x = 0; x < _A.cols; x++) {					  	      // A matrix ���� �ϱ� ���� X matrix�� ��ü
		for (y = 0; y < _A.rows; y++) {						  // �Լ� ������ A ��� X�� ���
			X.at[x][y] = _A.at[x][y];
		}
	}


	for (x = 0; x < _A.cols; x++)							   // ù ��° ���� �ʱⰪ
	{
		_U.at[0][x] = X.at[0][x];

	}


	for (int k = 0; k < _A.rows - 1; k++) {
		Pidx = k;
		for (x = k + 1; x < _A.cols; x++) {
			if (abs(X.at[x][k]) > abs(X.at[Pidx][k])) {        // Find Pivot
				Pidx = x;
			}
		}
		for (y = k; y < _A.rows; y++) {
			temp = X.at[Pidx][y];
			X.at[Pidx][y] = X.at[k][y];					// A matrix change row
			X.at[k][y] = temp;
			temp = _L.at[Pidx][y];
			_L.at[Pidx][y] = _L.at[k][y];	 			// L matrix change row
			_L.at[k][y] = temp;
		}

		for (y = 0; y < _A.rows; y++) {
			temp = _P.at[Pidx][y];
			_P.at[Pidx][y] = _P.at[k][y];	 			// P matrix change row
			_P.at[k][y] = temp;
		}

		for (int i = k + 1; i < _A.rows; i++) {
			M.at[i][k] = X.at[i][k] / X.at[k][k];
			_L.at[i][k] = M.at[i][k];
			for (int j = k; j < _A.cols; j++) {
				X.at[i][j] = X.at[i][j] - M.at[i][k] * X.at[k][j];

			}
		}
	}

	for (x = 0; x < _A.cols; x++) {							 	 // U matrix ��
		for (y = 0; y < _A.rows; y++) {
			_U.at[x][y] = X.at[x][y];
		}
	}

	for (int i = 0; i < _A.rows; i++)							 // L = L + I
		for (int j = 0; j < I.cols; j++)
			_L.at[i][j] = _L.at[i][j] + I.at[i][j];

}

void	solveLU(Matrix _L, Matrix _U, Matrix _P, Matrix _b, Matrix _x) {            //solve LU fuction

	Matrix y = createMat(_L.cols, _b.rows);											// y Matrix
	initMat(y, 0);

	y = MultMat(_P, _b);															// Ly = Pd �̹Ƿ�

	fwdSub(_L, _b, y);

	backSub(_U, y, _x);


}

void inv(Matrix _A, Matrix _Ainv) {

	if (_A.rows != _A.cols) {                                                            // Square Matrix�� �ƴϸ� ����
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		initMat(_Ainv, 0);
	}




	Matrix L = createMat(_A.rows, _A.cols);
	Matrix U = createMat(_A.rows, _A.cols);
	Matrix P = createMat(_A.rows, _A.cols);
	Matrix I = createMat(_A.rows, _A.cols);
	Matrix I1 = createMat(_A.rows, 1);
	Matrix Ainv1 = createMat(_A.rows, 1);
	initMat(I1, 0);
	initMat(L, 0);
	initMat(U, 0);
	initMat(P, 0);
	initMat(I, 0);
	initMat(Ainv1, 0);
	initMat(_Ainv, 0);



	LUdecomp(_A, L, U, P);																		  // A matrix LU decomposition �Ѵ�
	if (U.at[U.rows - 1][U.cols - 1] == 0) {                                                            // Upper triangular matrix�� ������ ��,������ ���� 0 �̸� full rank�� ���� �ʴ´�. 
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not full rank");
		printf("\n*************************************************\n");
		initMat(_Ainv, 0);
	}


	for (int x = 0; x < _A.cols; x++) {
		for (int y = 0; y < _A.rows; y++) {						// Identity Matrix
			if (x == y) {
				I.at[x][y] = 1;
			}
			else {
				I.at[x][y] = 0;
			}
		}
	}


	for (int i = 0; i < _A.cols; i++) {
		for (int k = 0; k < _A.rows; k++) {
			I1.at[k][0] = I.at[k][i];
			solveLU(L, U, P, I1, Ainv1);							// LUx=b ,  Ux=y   ���� y = identity Matrix �� x�� ���Ѵ�.
		}


		for (int y = 0; y < _A.rows; y++)
			_Ainv.at[y][i] = Ainv1.at[y][0];					// identity matrix ���� ������ŭ (�� ���� X 1) �� ��ķ� �ɰ� �� �ִ�. 
																// �ɰ� �� solveLU �Լ��� ����
	}																// solveLU�� �Լ��� ����� �ϸ� A�� ���Լ��� ���´�.
}






void QRdecomposition(Matrix _A, Matrix _Q, Matrix _R) {

	double cValue = 0;
	double vValue = 0;

	Matrix v = createMat(_A.rows, _A.cols);
	Matrix vT = createMat(_A.cols, _A.rows);
	Matrix G = createMat(_A.rows, _A.cols);              //G = v*vT/vT*v
	Matrix e = createMat(_A.rows, _A.cols);
	Matrix c = createMat(_A.rows, _A.cols);
	Matrix H = createMat(_A.rows, _A.cols);
	Matrix I = createMat(_A.rows, _A.cols);
	Matrix Q = createMat(_A.rows, _A.cols);
	Matrix R = createMat(_A.rows, _A.cols);

	initMat(v, 0);											   // �ʱⰪ
	initMat(vT, 0);
	initMat(G, 0);
	initMat(c, 0);
	initMat(H, 0);
	initMat(I, 0);
	initMat(e, 0);
	initMat(Q, 0);
	initMat(R, 0);
	initMat(_Q, 0);
	initMat(_R, 0);


	for (int x = 0; x < _A.rows; x++) {
		for (int y = 0; y < _A.cols; y++) {						// Identity Matrix
			if (x == y) {                                       // Q = Identity Matrix �� �ʱⰪ
				I.at[x][y] = 1;
				Q.at[x][y] = 1;
			}
			else {
				I.at[x][y] = 0;
				Q.at[x][y] = 0;
			}
		}
	}



	for (int i = 0; i < _A.rows; i++) {                          //   c  �� ����
		for (int j = 0; j < _A.cols; j++) {                      //  R0 �� �� ����
			c.at[i][j] = _A.at[i][j];
			R.at[i][j] = _A.at[i][j];
			if (i < j)
				c.at[i][j] = 0;
		}
	}


	for (int k = 0; k < _A.cols - 1; k++) {

		if (c.at[k][k] > 0)
			e.at[k][k] = 1;
		else
			e.at[k][k] = -1;

		for (int a = 0; a < _A.rows; a++) {								// c ���밪( ũ�� )
			cValue += pow(c.at[a][k], 2);

		}
		cValue = sqrt(cValue);
		// c ���밪( ũ�� )
		for (int a = 0; a < _A.rows; a++) {
			v.at[a][k] = c.at[a][k] + cValue * (e.at[a][k]);
			vValue += pow(v.at[a][k], 2);								//v�� unit vector�� ����� ���� ũ�� 

		}

		vT = transpose(v);
		G = MultMat(v, vT);                                    // v*vT
		for (int i = 0; i < _A.rows; i++)
			for (int j = 0; j < _A.cols; j++)
				H.at[i][j] = I.at[i][j] - 2 * G.at[i][j] / vValue;                          //H


		Q = MultMat(Q, H);
		R = MultMat(H, R);
		initMat(v, 0);
		initMat(vT, 0);
		cValue = 0;
		vValue = 0;
	}

	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++) {
			_Q.at[i][j] = Q.at[i][j];
			_R.at[i][j] = R.at[i][j];
		}
	}
}

void SimilarMat(Matrix _Q, Matrix _R, Matrix _U) {

	Matrix U = createMat(_R.cols, _Q.rows);
	Matrix R = createMat(_R.rows, _R.cols);
	Matrix Q = createMat(_Q.rows, _Q.cols);
	Matrix R2 = createMat(_R.rows, _R.cols);
	Matrix Q2 = createMat(_Q.rows, _Q.cols);

	initMat(_U, 0);
	initMat(R, 0);
	initMat(Q, 0);
	initMat(R2, 0);
	initMat(Q2, 0);

	R = copyMat(_R);
	Q = copyMat(_Q);
	U = copyMat(_U);

	U = MultMat(R, Q);                   //A1
	for (int i = 0; i < 100; i++) {                        // n = 100 times 
		QRdecomposition(U, Q, R);
		Q2 = copyMat(Q);
		R2 = copyMat(R);
		U = MultMat(R2, Q2);

	}

	for (int j = 0; j < U.rows; j++) {
		for (int k = 0; k < U.cols; k++) {
			_U.at[j][k] = U.at[j][k];
		}
	}
}

void diagElement(Matrix _U, Matrix _diag) {
	for (int j = 0; j < _U.rows; j++) {
		_diag.at[j][0] = _U.at[j][j];

	}
}




double	norm(Matrix _A, Matrix _eig) {
	Matrix Y = createMat(_A.rows, _A.cols);
	Y = MultMat(_A, transpose(_A));
	Matrix Sig = createMat(_A.rows, 1);
	Sig = MultMat(Y, _eig);
	double temp = 0;
	double x = 0;
	for (int i = 0; i < _A.cols; i++) {
		if (abs(Sig.at[0][0]) > abs(Sig.at[i][0])) {
			temp = Sig.at[i][0];
			Sig.at[i][0] = Sig.at[0][0];
			Sig.at[0][0] = temp;
		}													//Max Sig ���ϱ�
		Sig.at[0][0] = sqrt(abs(Sig.at[0][0]));             //��Ʈ
	}
	x = Sig.at[0][0];
	return x;
}

double	cond(Matrix _A) {

	double x = 0;
	double y = 0;
	double temp = 0;
	double tempm = 0;
	Matrix AT = createMat(_A.cols, _A.rows);
	Matrix W = createMat(_A.rows, _A.rows);


	AT = transpose(_A);
	W = MultMat(_A, AT);

	Matrix Q = createMat(W.rows, W.cols);
	Matrix R = createMat(W.rows, W.cols);
	Matrix U = createMat(W.rows, W.cols);
	Matrix diag = createMat(W.rows, 1);
	Matrix lam = createMat(W.rows, 1);

	QRdecomposition(W, Q, R);                     //QR decomposition
	SimilarMat(Q, R, U);                          // Find SimilarMat
	diagElement(U, diag);
	for (int i = 0; i < diag.rows; i++)
		lam.at[i][0] = sqrt(abs(diag.at[i][0]));


	for (int i = 0; i < W.cols; i++) {
		if (abs(lam.at[0][0]) < abs(lam.at[i][0])) {
			temp = lam.at[0][0];
			lam.at[0][0] = lam.at[i][0];
			lam.at[i][0] = temp;
		}													//Max lam ���ϱ�
	}
	x = lam.at[0][0];
	for (int i = 0; i < W.cols; i++) {
		if (abs(lam.at[W.rows - 1][0]) > abs(lam.at[i][0])) {
			tempm = lam.at[W.rows - 1][0];
			lam.at[W.rows - 1][0] = lam.at[i][0];
			lam.at[i][0] = tempm;
		}													//Min lam ���ϱ�
	}

	y = lam.at[W.rows - 1][0];

	for (int i = 0; i < diag.rows; i++)
		printf("eigenvalues %f\n", lam.at[i][0]);
	printf("\nmaximum eigenvalue = %f\n\n", x);
	printf("minimum eigenvalue = %f\n\n", y);
	return x / y;

}


void odeEU(double func(const double x, const double y), double v[], double t0, double tf, double h) {
	double N = (tf - t0) / h; 
	double t[100] = { 0 }; 
	v[0] = 0;
	for (int i = 0; i < N - 1; i++) { 
		v[i + 1] = v[i] + func(t[i], v[i]) * h; 
		t[i + 1] = t[i] + h;  
	}
}


void odeEM(double func(const double x, const double y), double v[], double t0, double tf, double h) {
	double N = (tf - t0) / h;
	double t[100] = { 0 };
	double vE[100] = { 0 };               // vE[i+1] = y[i] + f*h
	v[0] = 0;
	for (int i = 0; i < N - 1; i++) {

		vE[i + 1] = v[i] + func(t[i], v[i]) * h;
		t[i + 1] = t[i] + h;
		v[i + 1] = v[i] + h / 2 * (func(t[i], v[i]) + func(t[i + 1], vE[i + 1]));
	}
}

void ode(double func(const double x, const double y), double v[], double t0, double tf, double h, int method) {
	if(method == Eu){
		odeEU(func, v, t0, tf, h);
	}
	else if(method == Em) {
		odeEM(func, v, t0, tf, h);
	}
}



void odeRK2(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0)
{
	double C1 = 0.5;
	double C2 = 0.5;
	double alpha = 1;
	double beta = alpha;  // alpha=beta

	int N = (tf - t0) / h + 1;
	double ti = t0;
	double y_EU;
	double K1 = 0, K2 = 0;

	// Initialization 
	y[0] = y0;

	for (int i = 0; i < N - 1; i++)
	{
		// First slope  
		K1 = odeFunc(ti, y[i]);
		// Second slope  
		y_EU = y[i] + beta * K1 * h;
		K2 = odeFunc(ti + alpha * h, y_EU);

		// Update 
		y[i + 1] = y[i] + (C1 * K1 + C2 * K2) * h;
		ti += h;
	}
}

void odeRK4(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0)
{

	double a = 0.5;
	int N = (tf - t0) / h + 1;
	double ti = t0;
	double y_EU;
	double K1 = 0, K2 = 0, K3 = 0, K4 = 0;

	// Initialization 
	y[0] = y0;

	for (int i = 0; i < N - 1; i++)
	{
		// First slope  
		K1 = odeFunc(ti, y[i]);
		// Second slope 
		y_EU = y[i] + a * K1 * h;
		K2 = odeFunc(ti + a * h, y_EU);
		// Third slope
		y_EU = y[i] + a * K2 * h;
		K3 = odeFunc(ti + a * h, y_EU);
		// Fourth slope
		y_EU = y[i] + K3 * h;
		K4 = odeFunc(ti + h, y_EU);
		// Update 
		y[i + 1] = y[i] + (K1 + 2 * K2 + 2 * K3 + K4) * h / 6;
		ti += h;
	}
}

void sys2RK2(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init)
{
	int N = (tf - t0) / h + 1;
	double ti = t0;

	double K1[2] = { 0 };         // K1 = [K1_y1, K1_y2]
	double K2[2] = { 0 };         // k2 = [K2_y1, K2_y2]
	double Yin[2] = { 0 };
	double K1_y1 = 0, K1_y2 = 0, K2_y1 = 0, K2_y2 = 0;

	//Y[0] == y(t);
	//Y[1] == z(t);
	//dYdt[0] = z(t) = Y[1];
	//dYdt[1] = zdot;



	// Initial condition
	y1[0] = y1_init;        //y(t)
	y2[0] = y2_init;        //z(t) = dydt(t)

	for (int i = 0; i < N - 1; i++) {

		// Slope 1 : K1
		Yin[0] = y1[i];		// z
		Yin[1] = y2[i];		// dzdt		
		odeFunc_sys2(ti, Yin, K1);
		K1_y1 = K1[0];
		K1_y2 = K1[1];

		// Slope 2 : K2

		Yin[0] = y1[i] + K1_y1 * h;		// z
		Yin[1] = y2[i] + K1_y2 * h;		// dzdt		
		odeFunc_sys2(ti + h, Yin, K2);
		K2_y1 = K2[0];
		K2_y2 = K2[1];


		// Update
		y1[i + 1] = y1[i] + (K1_y1 + K2_y1) * 0.5 * h;
		y2[i + 1] = y2[i] + (K1_y2 + K2_y2) * 0.5 * h;
		ti += h;
	}
}


// Classical RK4
void sys2RK4(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init)
{

	int N = (tf - t0) / h + 1;
	double ti = t0;

	double K1[2] = { 0 };         // K1 = [K1_y1, K1_y2]
	double K2[2] = { 0 };         // k2 = [K2_y1, K2_y2]
	double K3[2] = { 0 };
	double K4[2] = { 0 };
	double Yin[2] = { 0 };
	double K1_y1 = 0, K1_y2 = 0, K2_y1 = 0, K2_y2 = 0, K3_y1 = 0, K3_y2 = 0, K4_y1 = 0, K4_y2 = 0;

	//Y[0] == y(t);
	//Y[1] == z(t);
	//dYdt[0] = z(t) = Y[1];
	//dYdt[1] = zdot;



	// Initial condition
	y1[0] = y1_init;        //y(t)
	y2[0] = y2_init;        //z(t) = dydt(t)

	for (int i = 0; i < N - 1; i++) {

		// Slope 1 : K1
		Yin[0] = y1[i];		// z
		Yin[1] = y2[i];		// dzdt		
		odeFunc_sys2(ti, Yin, K1);
		K1_y1 = K1[0];
		K1_y2 = K1[1];

		// Slope 2 : K2

		Yin[0] = y1[i] + K1_y1 * h;		// z
		Yin[1] = y2[i] + K1_y2 * h;		// dzdt		
		odeFunc_sys2(ti + h, Yin, K2);
		K1_y1 = K2[0];
		K1_y2 = K2[1];

		// Slope 3 : K3

		Yin[0] = y1[i] + K2_y1 * h;		// z
		Yin[1] = y2[i] + K2_y2 * h;		// dzdt		
		odeFunc_sys2(ti + h, Yin, K2);
		K1_y1 = K3[0];
		K1_y2 = K3[1];

		// Slope 4 : K4

		Yin[0] = y1[i] + K3_y1 * h;		// z
		Yin[1] = y2[i] + K3_y2 * h;		// dzdt		
		odeFunc_sys2(ti + h, Yin, K2);
		K1_y1 = K4[0];
		K1_y2 = K4[1];

		// Update
		y1[i + 1] = y1[i] + (K1_y1 + K2_y1) * 0.5 * h;
		y2[i + 1] = y2[i] + (K1_y2 + K2_y2) * 0.5 * h;
		ti += h;
	}

}

