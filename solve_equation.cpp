#include <stdio.h>
#include <math.h>

#include "solve_equation.h"
#include "supporting_functions.h"
#include "enum_number_res.h"



int SolveLinear (double* coefficient_b, double* coefficient_c,
                 double* solution_1, double* solution_2) {

    if (DoubleCompare(*coefficient_b, 0)) {

        if (DoubleCompare(*coefficient_c, 0)) {
            return INFINITE_ROOTS;
        }
        else {
            return ZERO_ROOTS;
        }
    }
    else {

        *solution_1 = *solution_2 = -*coefficient_c / *coefficient_b;
        return ONE_ROOT;
        
    }                  
}



int SolveSquare (double* coefficient_a, double* coefficient_b, double* coefficient_c,
                double* solution_1, double* solution_2) {

    double Discriminant = (*coefficient_b)*(*coefficient_b) - 4*(*coefficient_a)*(*coefficient_c);

    if (Discriminant < 0) {
        return ZERO_ROOTS;
    }
    else {
        *solution_1 = (-*coefficient_b - sqrt(Discriminant)) / (2*(*coefficient_a));
        *solution_2 = (-*coefficient_b + sqrt(Discriminant)) / (2*(*coefficient_a));

        return TWO_ROOTS;
    }
}
