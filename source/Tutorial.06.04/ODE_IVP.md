# ODE_IVP

## odeEU()

solve Ordinary Difference Equation using Euler method.

```c++
void odeEU (double func(const double x), double y[ ], double t0, double tf, double h)
```

**Parameters**

* **x**: Variable x of function, you should write your function in main.cpp
* **y**: Array **y** 
* **t0**:  First value in Initial value range.
* **tf: ** Last value in Initial value range.
* **h:** double **h**, interval of x

## odeEM()

solve Ordinary Difference Equation using Euler modified method.

```c++
void odeEM(double func(const double x), double y[ ], double t0, double tf, double h)
```

 **Parameters** 

* **x**: Variable x of function, you should write your function in main.cpp
* **y**: Array **y** 
* **t0**:  First value in Initial value range.
* **tf: ** Last value in Initial value range.
* **h:** double **h**, interval of x

## ode()

select solving method. 

```c++
void ode(double func(const double x), double y[ ], double t0, double tf, double h, int method)
```

 **Parameters** 

* **x**: Variable x of function, you should write your function in main.cpp
* **y**: Array **y** 
* **t0**:  First value in Initial value range.
* **tf: ** Last value in Initial value range.
* **h:** double **h**, interval of **x**
* **method:** select method --- Eu, Em

## odeRK2()

solve Ordinary Difference Equation using Runge-Kutta 2nd method

```c++
void odeRK2(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0)
```

 **Parameters** 

* **t**: Variable t of function, you should write your function in main.cpp
* **y**: Variable y of function, you should write your function in main.cpp
* **y**: Array **y** 
* **t0**:  First value in Initial value range.
* **tf: ** Last value in Initial value range.
* **h:** double **h**, interval of **x**
* **y0**: Initial value of **y**

## odeRK4()

solve Ordinary Difference Equation using Runge-Kutta 4th method

```c++
void odeRK4(double odeFunc(const double t, const double y), double y[], double t0, double tf, double h, double y0)
```

 **Parameters** 

* **t**: Variable t of function, you should write your function in main.cpp
* **y**: Variable y of function, you should write your function in main.cpp
* **y**: Array **y** 
* **t0**:  First value in Initial value range.
* **tf: ** Last value in Initial value range.
* **h:** double **h**, interval of **x**
* **y0**: Initial value of **y**

## sys2RK2()

solve 2nd Ordinary Difference Equation using Runge-Kutta 2nd method

```c++
void sys2RK2(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init)
```

 **Parameters** 

* **t**: Variable t of function, you should write your function in main.cpp

* **Y**: Array **Y**[],  you should write your function in main.cpp --- Y[0] = y(t), Y[1] = z(t)

* **dYdt**: Array **dYdt**[], you should write your function in main.cpp 

  ​            --- dYdt[0] = z(t), dYdt[1] = zdot.

* **y1**: Array **y1**

* **y2**: Array **y2**

* **t0**:  First value in Initial value range.

* **tf: ** Last value in Initial value range.

* **h:** double **h**, interval of **t**

* **y1_init**: Initial value of **y1**

* **y2_init**: Initial value of **y2**

## sys2RK4()

solve 2nd Ordinary Difference Equation using Runge-Kutta 4th method

```c++
void sys2RK4(void odeFunc_sys2(const double t, const double Y[], double dYdt[]), double y1[], double y2[], double t0, double tf, double h, double y1_init, double y2_init)
```

 **Parameters** 

* **t**: Variable t of function, you should write your function in main.cpp

* **Y**: Array **Y**[],  you should write your function in main.cpp --- Y[0] = y(t), Y[1] = z(t)

* **dYdt**: Array **dYdt**[], you should write your function in main.cpp 

  ​            --- dYdt[0] = z(t), dYdt[1] = zdot.

* **y1**: Array **y1**

* **y2**: Array **y2**

* **t0**:  First value in Initial value range.

* **tf: ** Last value in Initial value range.

* **h:** double **h**, interval of **t**

* **y1_init**: Initial value of **y1**

* **y2_init**: Initial value of **y2**

**Example code**

```c++
double a = 0;
double b = 0.1;
double h = 0.001;
unsigned int N = (b - a) / h + 1;
double y_EU[200] = { 0 };		   
double y_EM[200] = { 0 };
double y_RK2[200] = { 0 };
double y_RK4[200] = { 0 };
double v0 = 0;

odeEU(odeFunc_rc, y_EU, a, b, h);
odeEM(odeFunc_rc, y_EM, a, b, h);
ode(myFunc, y, a, b, h, Em); 
odeRK2(odeFunc_rc, y_RK2, a, b, h, v0);
odeRK4(odeFunc_rc, y_RK4, a, b, h, v0);
for (int i = 0; i < N; i++)
	printf("t= %f\tyEU= %f\tyEM= %f\tyRK2= %f\tyRK4= %f\n", a + i * h, y_EU[i], y_EM[i], y_RK2[i], y_RK4[i]);
printf("\n");

double t0 = 0;
double tf = 1;
h = 0.01;
N = (tf - t0) / h + 1;
double y[200] = { 0 };
double v[200] = { 0 };
double y0 = 0;
v0 = 0.2;

sys2RK2(odeFunc_mck, y, v, t0, tf, h, y0, v0);
for (int i = 0; i < N; i++)
	printf("t= %f\ty= %f\tv= %f\n", t0 + i * h, y[i], v[i]);
printf("\n\n");

sys2RK4(odeFunc_mck, y, v, t0, tf, h, y0, v0);
for (int i = 0; i < N; i++)
	printf("t= %f\ty= %f\tv= %f\n", t0 + i * h, y[i], v[i]);

double odeFunc_rc(const double x, const double y) {
	double tau = 1;
	double T = 1 / tau;
	double f = 10;
	double Vm = 1;
	double w = 2 * PI * f;

	return  -T * y + T * Vm * cos(w * x);
}

void odeFunc_mck(const double t, const double Y[], double dYdt[])
{
	double m = 1;
	double c = 7;
	double k = 6.9;
	double f = 5;
	double Fin = 2 * cos(2 * PI * f * t);
	dYdt[0] = Y[1];
	dYdt[1] = (-k * Y[0] - c - Y[1] + Fin) / m;
}
```

See full example code: [ODE_IVP.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/Tutorial.06.04/Tutorial.06.04.cpp)



