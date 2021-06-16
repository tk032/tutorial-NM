# Integration

## trapz()

find integrated value 

```c++
double trapz (double x[ ], double y[ ], int m)
```

**Parameters**

* **x**: Array **x** 
* **y**: Array **y** 
* **m:** double **m**, number of data

## integral()

find integrated value of range a to b

```c++
double integral(double func(const double x), double a, double b, int n) 
```

 **Parameters** 

* **x**: Variable x of function, you should write your function in main.cpp
* **a**:  First value in Initial value range.
* **b: ** Last value in Initial value range.
* **n:** double **n**, number of data

## integralMid()

find integrated value using Midpoint method.

```c++
double integralMid (double x[ ], double y[ ], int m)
```

 **Parameters** 

* **x**: Array **x** 
* **y**: Array **y** 
* **m:** double **m**, number of data

## integral38()

find integrated value using Simpson38 method.

```c++
double integral38(double func(const double x), double a, double b, int n) 
```

 **Parameters** 

* **x**: Variable x of function, you should write your function in main.cpp
* **a**:  First value in Initial value range.
* **b: ** Last value in Initial value range.
* **n:** double **n**, number of data

**Example code**

```c++
double x[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
double y[] = { 0, 3, 8, 20, 33, 42, 40, 48, 60, 12, 8, 4, 3 };
int M = sizeof(x) / sizeof(x[0]);

double I_rect = IntegrateRect(x, y, M);
printf("I_rect  = %f\n", I_rect);

double I_trapz = 0;
I_trapz = trapz(x, y, M); 
printf("I_trapz = %f\n\n", I_trapz);

double I_simpson13 = 0;
I_simpson13 = integral(myFunc, -1, 1, 12); 
printf("I_simpson13  = %f\n\n", I_simpson13);

double I_Mid = integralMid(x, y, M);
printf("I_Mid  = %f\n\n", I_Mid);

double I_simpson38 = 0;

I_simpson38 = integral38(myFunc, -1, 1, 12);
printf("I_simpson38  = %f\n\n", I_simpson38);

double myFunc(const double x) {

	return sqrt(1 - (x * x));
}
```

See full example code: [Integration.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/Integration/Integration.cpp)



