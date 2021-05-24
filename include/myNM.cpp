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
	for (double i = 2; i <= _n; i += 2) {             // N = 0  ~  N = N - 1 값
		SUM += 4 * func(x0 + h * (i - 1)) + 2 * func(x0 + h * (i - 2));
	}
	SUM += func(x0 + h * _n);                     //  N = N 값    

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
	for (double i = 3; i <= n; i += 3) {             // N = 1  ~  N = N - 1 값
		SUM += 3 * (func(x0 + h * (i - 2)) + func(x0 + h * (i - 1))) + 2 * func(x0 + h * (i - 3));
	}
	SUM += func(x0 + h * n) + func(x0);                     // N = 0,  N = N 값    

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
	if (_A.cols != _B.rows)                                                         // Matrix A의 열, Matrix b의 행의 수가 다르면 오류(계산 불가)
	{
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'MultMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}
	Matrix Out1 = createMat(_A.rows, _B.cols);

	for (int i = 0; i < _A.rows; i++)                      //  Out 초기값
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

	if (_A.rows != _A.cols) {                                                            // Square Matrix가 아니면 오류
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		initMat(_U, 0);
		initMat(_d, 0);
	}
	else if (_A.cols != _b.rows)                                                         // Matrix A의 열, Matrix b의 행의 수가 다르면 오류(계산 불가)
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
	//초기값
	for (int n = 0; n < _A.cols; n++)                            // 첫 번째 행의 초기값
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

Matrix  gaussElim2(Matrix _A)													         //입력하나 A matrix 에 대해서만 가우스 소거법(rank 확인하기 위해)
{

	if (_A.rows != _A.cols) {                                                            // Square Matrix가 아니면 오류
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}


	int x = 0;												// for문 변수
	int y = 0;                                              // for문 변수
	int Pidx = 0;
	double temp = 0;


	Matrix M = createMat(_A.rows, _A.cols);
	Matrix Out = createMat(_A.rows, _A.cols);
	initMat(M, 0);
	//초기값

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


	if (_A.rows != _A.cols) {                                                            // Square Matrix가 아니면 오류
		printf("\n*************************************************");
		printf("\n  ERROR!!: Matrix is not square");
		printf("\n*************************************************\n");
		initMat(_U, 0);

	}


	Matrix X = createMat(_A.rows, _A.cols);					// A matrix 보존 하기 위해 X matrix로 대체
	Matrix M = createMat(_A.rows, _A.cols);
	Matrix I = createMat(_A.rows, _A.cols);					// Identity Matrix
	initMat(M, 0);											// M 초기값
	initMat(X, 0);
	initMat(I, 0);
	initMat(_L, 0);                                         // L matrix 초기값
	initMat(_P, 0);											// P matrix 초기값 = 0

	int x = 0;												// for문 변수
	int y = 0;                                              // for문 변수
	int Pidx = 0;
	double temp = 0;


	for (x = 0; x < _A.cols; x++) {                         // P matrix 초기값 = Identity Matrix
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



	for (x = 0; x < _A.cols; x++) {					  	      // A matrix 보존 하기 위해 X matrix로 대체
		for (y = 0; y < _A.rows; y++) {						  // 함수 내에서 A 대신 X로 사용
			X.at[x][y] = _A.at[x][y];
		}
	}


	for (x = 0; x < _A.cols; x++)							   // 첫 번째 행의 초기값
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

	for (x = 0; x < _A.cols; x++) {							 	 // U matrix 값
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

	y = MultMat(_P, _b);															// Ly = Pd 이므로

	fwdSub(_L, _b, y);

	backSub(_U, y, _x);


}

void inv(Matrix _A, Matrix _Ainv) {

	if (_A.rows != _A.cols) {                                                            // Square Matrix가 아니면 오류
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



	LUdecomp(_A, L, U, P);																		  // A matrix LU decomposition 한다
	if (U.at[U.rows - 1][U.cols - 1] == 0) {                                                            // Upper triangular matrix의 마지막 행,마지막 열이 0 이면 full rank가 되지 않는다. 
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
			solveLU(L, U, P, I1, Ainv1);							// LUx=b ,  Ux=y   에서 y = identity Matrix 로 x를 구한다.
		}


		for (int y = 0; y < _A.rows; y++)
			_Ainv.at[y][i] = Ainv1.at[y][0];					// identity matrix 열의 개수만큼 (행 개수 X 1) 의 행렬로 쪼갤 수 있다. 
																// 쪼갠 후 solveLU 함수를 실행
	}																// solveLU의 함수를 재결합 하면 A의 역함수가 나온다.
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

	initMat(v, 0);											   // 초기값
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
			if (x == y) {                                       // Q = Identity Matrix 의 초기값
				I.at[x][y] = 1;
				Q.at[x][y] = 1;
			}
			else {
				I.at[x][y] = 0;
				Q.at[x][y] = 0;
			}
		}
	}



	for (int i = 0; i < _A.rows; i++) {                          //   c  값 설정
		for (int j = 0; j < _A.cols; j++) {                      //  R0 의 값 설정
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

		for (int a = 0; a < _A.rows; a++) {								// c 절대값( 크기 )
			cValue += pow(c.at[a][k], 2);

		}
		cValue = sqrt(cValue);
		// c 절대값( 크기 )
		for (int a = 0; a < _A.rows; a++) {
			v.at[a][k] = c.at[a][k] + cValue * (e.at[a][k]);
			vValue += pow(v.at[a][k], 2);								//v를 unit vector로 만들기 위한 크기 

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
		}													//Max Sig 구하기
		Sig.at[0][0] = sqrt(abs(Sig.at[0][0]));             //루트
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
		}													//Max lam 구하기
	}
	x = lam.at[0][0];
	for (int i = 0; i < W.cols; i++) {
		if (abs(lam.at[W.rows - 1][0]) > abs(lam.at[i][0])) {
			tempm = lam.at[W.rows - 1][0];
			lam.at[W.rows - 1][0] = lam.at[i][0];
			lam.at[i][0] = tempm;
		}													//Min lam 구하기
	}

	y = lam.at[W.rows - 1][0];

	for (int i = 0; i < diag.rows; i++)
		printf("eigenvalues %f\n", lam.at[i][0]);
	printf("\nmaximum eigenvalue = %f\n\n", x);
	printf("minimum eigenvalue = %f\n\n", y);
	return x / y;

}