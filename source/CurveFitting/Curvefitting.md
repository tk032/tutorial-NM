# Curvefitting

## linearFit()

find estimated slope and offset.

```c++
Matrix linearFit(Matrix _x, Matrix _y)
```

**Parameters**

* **x**: Matrix **x** in structure Matrix form
* **y**: Matrix **y** in structure Matrix form

## linearFitVal()

find estimated value using estimated slope and offset.

```c++
double linearFitVal(Matrix _x, Matrix _y, double _p)
```

 **Parameters** 

* **x**: Matrix **x** in structure Matrix form
* **y**: Matrix **y** in structure Matrix form
* **p: **Input value to determine estimated value

## linearInterp()

find estimated value using linear spline interpolation.

```c++
Matrix linearInterp(Matrix _x, Matrix _y, Matrix _xq)
```

 **Parameters** 

* **x**: Matrix **x** in structure Matrix form
* **y**: Matrix **y** in structure Matrix form
* **xq: **Matrix **xq**, Input value to determine estimated value

**Example code**

```c++
Matrix T = txt2Mat(path, "vecT");
Matrix P = txt2Mat(path, "vecP");
Matrix z = linearFit(T, P);
printMat(T, "T");
printMat(P, "P");
printMat(z, "z");

double p = linearFitVal(T, P, 150);
printf("Predict the pressure at T = 150C  :  %lf\n", p);

double T2[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 };
double T3[] = { 75 };          //  Value 75C

Matrix xq = arr2Mat(T2, 21, 1);
Matrix yq = createMat(xq.rows, xq.cols);
Matrix xp = arr2Mat(T3, 1, 1);
Matrix yp = createMat(xp.rows, xp.cols);

initMat(yq, 0);
initMat(yp, 0);
yq = linearInterp(T, P, xq);
yp = linearInterp(T, P, xp);

printMat(xq, "xq");
printMat(yq, "yq");			//estimate T = 0:5:100
printMat(xp, "xp");       
printMat(yp, "yp");			//estimate 75C
```

See full example code: [CurveFitting.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/CurveFitting/CurveFitting.cpp)



