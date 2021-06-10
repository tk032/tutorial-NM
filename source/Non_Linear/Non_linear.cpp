#include "../../include/myNM.h"


int main() {

    /*==========================================================================*/
    /*               Tutorial -     Bisection Method                            */
    /*==========================================================================*/

    /************      Variables declaration & initialization      ************/

    double tol = 0.00001;
    double a0 = 3; //need to change initial value
    double b0 = 6;  //need to change initial value
    double x0 = 6;
    double BM_result;
    double NR_result;

    /************      Test NM Functions & Show Output            ************/
    printf("------------------------------------------------------------------------------------\n");
    printf("         Bisection Method Results             \n");
    printf("------------------------------------------------------------------------------------\n");

    printf("Bisection Method:\n");
    BM_result = bisectionNL(a0, b0, tol);
    printf("Final Solution: %f \t", BM_result);
    printf("\n");

    printf("------------------------------------------------------------------------------------\n");
    printf("         Newton-Raphson Method Results             \n");
    printf("------------------------------------------------------------------------------------\n");

    printf("Newton-Raphson Method Results:\n");
    NR_result = newtonRaphson(x0, tol);
    printf("Final Solution: %f \t", NR_result);
    printf("\n");

    /************      Variables declaration & initialization      ************/

     tol = 0.00001;
     a0 = 0.1; //need to change initial value
     b0 = 2;  //need to change initial value
     x0 = 1.4;
    double HB_result;
  

    /************      Test NM Functions & Show Output            ************/
    printf("------------------------------------------------------------------------------------\n");
    printf("         Newton-Raphson Method Results             \n");
    printf("------------------------------------------------------------------------------------\n");

    printf("Newton-Raphson Method:\n");
    NR_result = BonusNR(x0, tol);
    printf("Final Solution: %f \t", NR_result);
    printf("\n");

    printf("------------------------------------------------------------------------------------\n");
    printf("         Hybrid Algorithm Results             \n");
    printf("------------------------------------------------------------------------------------\n");

    printf("Hybrid Algorithm:\n");
    HB_result = HybridA(a0, b0, x0, tol);
    printf("Final Solution: %f \t", HB_result);
    printf("\n");

    system("pause");
}