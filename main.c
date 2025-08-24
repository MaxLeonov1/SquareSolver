#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "input_output_functions.h"
#include "supporting_functions.h"
#include "solve_equation.h"
#include "structures.h"
#include "unit_test.h"



int main() {
    
    int solution_number = 0;
    struct coefficients equation_coeff = { .a = 0, .b = 0, .c = 0 };
    struct result       equation_res   = { .x1 = 0, .x2 = 0 };

    if (SetWorkingMode()) {

        ScanCoefficients(&equation_coeff);

        if (DoubleCompare(equation_coeff.a, 0)) {
            solution_number = SolveLinear(&equation_coeff.b, &equation_coeff.c,
                                        &equation_res.x1, &equation_res.x2);
        }
        else {
            solution_number = SolveSquare(&equation_coeff.a, &equation_coeff.b, &equation_coeff.c,
                                        &equation_res.x1, &equation_res.x2);
        }

        PrintSolutions(solution_number, &equation_res.x1, &equation_res.x2);

    } else {

        RunTests();

    }

    return 0;
}

