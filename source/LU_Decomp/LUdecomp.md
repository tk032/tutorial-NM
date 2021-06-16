# Linear Solver

## LUdecomp()

set Ax = b to LUx = b, a linear system problem

```c++
void LUdecomp (Matrix A, Matrix L, Matrix U, Matrix P)
```

**Parameters**

* **A**: Matrix **A** in structure Matrix form, Should be (nxn) square.
* **L**:  Matrix **L** in structure Matrix form
* **U**: Matrix **U** in structure Matrix form
* **P: **Vector **P** in structure Matrix form.

## solveLU()

solves for vector **x** from LUx = b, a linear system problem

```c++
void solveLU(Matrix _L, Matrix _U, Matrix _P, Matrix _b, Matrix _x)
```

 **Parameters** 

* **L**:  Matrix **L** in structure Matrix form.
* **U**: Matrix **U** in structure Matrix form.
* **P: **Vector **P** in structure Matrix form.
* **b**: Matrix **b** in structure Matrix form.
* **x**: Matrix **x** in structure Matrix form.

## inv()

solves for vector **x** from LUx = b, a linear system problem

```c++
void solveLU(Matrix _L, Matrix _U, Matrix _P, Matrix _b, Matrix _x)
```

 **Parameters** 

* **A**:  Matrix **A** in structure Matrix form.
* **Ainv**: Matrix **Ainv** in structure Matrix form. 

**Example code**

```c++
Matrix matA = txt2Mat(path, "prob1_matA");
Matrix vecb = txt2Mat(path, "prob1_vecb");
Matrix matU = createMat(matA.rows, matA.cols);
Matrix matL = createMat(matA.rows, matA.cols);
Matrix matP = createMat(matA.rows, matA.cols);
Matrix vecx = createMat(vecb.rows, vecb.cols);
Matrix Ainv = createMat(matA.rows, matA.cols);
Matrix matAinv = createMat(matA.rows, matA.cols);

LUdecomp(matA, matL, matU, matP);							
solveLU(matL, matU, matP, vecb, vecx);						
inv(matA, matAinv);									

printMat(vecb, "vecb");
printMat(matL, "matrix L");
printMat(matU, "matrix U");
printMat(matP, "matrix P");
printMat(vecx, "vecx");
printMat(matAinv, "Ainv");
Ainv = MultMat(matAinv, vecb);	 //    Ainv*b
printMat(Ainv, "vecx = Ainv*b");
```

See full example code: [LUdecomp.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/LUdecomp/LUdecomp.cpp)



