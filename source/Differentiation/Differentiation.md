# Differentiation

## gradient()

find gradient

```c++
Matrix gradient(Matrix x, Matrix y)
```

**Parameters**

* **x**: Matrix **x** in structure Matrix form
* **y**: Matrix **y** in structure Matrix form

## gradient1D()

find gradient with 1D-array

```c++
void gradient1D (double x[ ], double y[ ], double dydx[ ], int m)
```

 **Parameters** 

* **x**: Array **x** 
* **y**: Array **y** 
* **dydx: **Array **dydx**
* **m:** double **m** 

## gradientFunc()

find gradient using variable.

```c++
Matrix gradientFunc(double func(const double x), Matrix xin)
```

 **Parameters** 

* **x**: Variable x of function, you should write your function in main.cpp
* **xin: **Matrix **xin**

**Example code**

```c++
double x[] = { -5.87, -4.23, -2.55, -0.89, 0.67, 2.09, 3.31, 4.31, 5.06, 5.55, 5.78, 5.77, 5.52, 5.08, 4.46, 3.72, 2.88, 2.00, 1.10, 0.23, -0.59 };
double t[] = { 0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0 };
double xlength = sizeof(x) / sizeof(x[0]);     
double tlength = sizeof(t) / sizeof(t[0]);  
Matrix x_m = arr2Mat(x, xlength, 1);      
Matrix t_m = arr2Mat(t, tlength, 1);	

Matrix vel = gradient(t_m, x_m);
Matrix acc = gradient(t_m, vel);

printMat(t_m, "Matrix t");
printMat(x_m, "Matrix x");
printMat(vel, "vel");
printMat(acc, "acc");

double dydx_a[21] = { 0 };		
gradient1D(t, x, dydx_a, xlength);
printf("1D array dydx= \n");
for (int i = 0; i < xlength; i++)
	printf("\t%lf\n", dydx_a[i]);
Matrix xin = t_m;
Matrix dydx = gradientFunc(myFunc, xin);
pri	printMat(dydx, "dydx");

double myFunc(const double x) {
	double length = 4;
	double elastic = 70 * 1000000000;
	double inertia = 52.9 * 0.000001;
	double w0 = 20 * 1000;
	double F = w0 * (7 * pow(length, 4) - 30 * pow(length, 2) * pow(x, 2) + 15 * pow(x, 4)) / 360 / length / elastic / inertia;
	return F;

}

double mydFunc(const double x) {

	double length = 4;
	double elastic = 70 * 1000000000;
	double inertia = 52.9 * 0.000001;
	double w0 = 20 * 1000;
	double F = w0 * (-60 * pow(length, 2) * x + 60 * pow(x, 3)) / 360 / length / elastic / inertia;
	return F;
}
```

See full example code: [Differentiation.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/Differentiation/Differentiation.cpp)



