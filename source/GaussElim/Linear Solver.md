# Linear Solver

## gaussElim()

solves for vector **x** from Ax = b, a linear system problem

```c++
void gaussElim(Matrix _A, Matrix _B, Matrix* _U, Matrix *_d)
```

**Parameters**

* **A**: Matrix **A** in structure Matrix form, Should be (nxn) square.
* **b: Vector **b** in structure Matrix form. Should be(nx1)

## backsub()

solves for vector **x** from Ux = d, a linear system problem

```c++
void backsub(Matrix _U, Matrix _d, Matrix _x)
```

 **Parameters** 

* **U**: Matrix **U** in structure Matrix form, Should be (nxn) square.
* **d**: Vector **d** in structure Matrix form. Should be(nx1)

**Example code**

```c++
Matrix matA = txt2Mat(path, "prob1_matA");
Matrix vecb = txt2Mat(path, "prob1_vecb");
Matrix matU = createMat(matA.rows, matA.cols);
Matrix vecd = createMat(vecb.rows, vecb.cols);
Matrix vecx = createMat(vecb.rows, vecb.cols);
	
gaussElim(matA, vecb, matU, vecd);
backSub(matU, vecd, vecx);  

printMat(matU, "matrix U");
printMat(vecd, "vector d");
printMat(vecx, "vector x");
```

See full example code: [GaussElim.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/GaussElim/gaussElim.cpp)



