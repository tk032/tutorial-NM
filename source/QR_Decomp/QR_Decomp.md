# Linear Solver

## QRdecomposition()

set Matrix A to QR, a linear system problem

```c++
void QRdecomposition(Matrix _A, Matrix _Q, Matrix _R)
```

**Parameters**

* **A**: Matrix **A** in structure Matrix form, Should be (nxn) square.
* **Q**: Matrix **Q** in structure Matrix form
* **R**: Matrix **R** in structure Matrix form

## SimilarMat()

find Similar Matrix

```c++
void SimilarMat(Matrix _Q, Matrix _R, Matrix _U)
```

 **Parameters** 

* **Q**:  Matrix **Q** in structure Matrix form.
* **R**: Matrix **R** in structure Matrix form.
* **U: **Vector **U** in structure Matrix form.

## diagElement()

find diagonal element.

```c++
void diagElement(Matrix _U, Matrix _diag)
```

 **Parameters** 

* **A**:  Matrix **A** in structure Matrix form. Should be (nxn) square.
* **Ainv**: Matrix **Ainv** in structure Matrix form. 

## cond()

find cond(Matrix A)

```c++
double	cond(Matrix _A)
```

 **Parameters** 

* **A**:  Matrix **A** in structure Matrix form.

**Example code**

```c++
Matrix matA = txt2Mat(path, "matA");
Matrix U = createMat(matA.rows, matA.cols);
Matrix Q = createMat(matA.rows, matA.cols);
Matrix R = createMat(matA.rows, matA.cols);
Matrix diag = createMat(matA.rows, 1);
Matrix matC = txt2Mat(path, "matC");
QRdecomposition(matA, Q, R);        //QR decomposition
SimilarMat(Q,R, U);                 // Find SimilarMat
diagElement(U, diag);

double Sig1 = 0.0;
double Sig2 = 0.0;

printMat(Q, "Q");
printMat(R, "R");
printMat(U, "U");
printMat(diag, "diagonal");

printf("MatA : \n\n");
Sig1 = cond(matA); 

printf("MatC : \n\n");
Sig2 = cond(matC);

printf("Square-root the ratio of max-min values of Cond(A) = %f\n\n", Sig1);
printf("Square-root the ratio of max-min values of Cond(C) = %f\n\n", Sig2);
```

See full example code: [QRdecomp.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/QRdecomp/QRdecom.cpp)



