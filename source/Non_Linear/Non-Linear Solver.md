# Non-Linear Solver

## bisectionNL()

solves for  **x** from F(x)=ax+b ..etc using bisection method

, a non-linear system problem

```c++
double bisectionNL(double _a0, double _b0, double _tol)
```

**Parameters**

* **a0**:  First value in Initial value range.
* **b0: ** Last value in Initial value range.
* **tol**: Maximum error value(tolerance).

you should check   (F(a0) * F(b0) <= 0)

## newtonRahpson()

solves for  **x** from F(x)=ax+b ..etc using newtonrahpson method

, a non-linear system problem 

```c++
double newtonRaphson(double _x0, double _tol)
```

 **Parameters** 

* **x0: ** Initial value.
* **tol**: Maximum error value(tolerance).

you should check  (F'(x0) != 0)

## HybridA()

solves for  **x** from F(x)=ax+b ..etc using bisection and newtonraphson method

, a non-linear system problem 

```c++
double HybridA(double _a0, double _b0, double _x0, double _tol)
```

**Parameters**

* **a0**:  First value in Initial value range.
* **b0: ** Last value in Initial value range.
* **x0: ** Initial value.
* **tol**: Maximum error value(tolerance).

**Example code**

```c++
 double tol = 0.00001;
 double a0 = 3; //need to change initial value
 double b0 = 6;  //need to change initial value
 double x0 = 6;
 double BM_result;
 double NR_result;
 double HB_result;

 BM_result = bisectionNL(a0, b0, tol);
 printf("Final Solution: %f \t", BM_result);

 NR_result = newtonRaphson(x0, tol);
 printf("Final Solution: %f \t", NR_result);

 HB_result = HybridA(a0, b0, x0, tol);
 printf("Final Solution: %f \t", HB_result);
```

See full example code: [Non_linear.cpp](https://github.com/tk032/tutorial-NM/blob/main/source/Non_linear/Non_linear.cpp)



