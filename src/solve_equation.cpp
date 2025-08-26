#include <stdio.h>
#include <math.h>

#include "solve_equation.h"
#include "supporting_functions.h"
#include "enum_number_res.h"
#include "structures.h"



int EquationSolver (Coefficients* equation_coeff,
                    Result*       equation_res) {

    if (DoubleCompare (equation_coeff->a, 0)) {

        return SolveLinear (equation_coeff, equation_res);

    }
    else {

        return SolveSquare (equation_coeff, equation_res);

    }

}

int SolveLinear (Coefficients* equation_coeff,
                 Result*       equation_res) {

    if (DoubleCompare (equation_coeff->b, 0)) {

        if (DoubleCompare (equation_coeff->c, 0)) {

            return INFINITE_ROOTS;

        } else {

            return ZERO_ROOTS;

        }

    } else {

        equation_res->x1 = equation_res->x2 = -equation_coeff->c / equation_coeff->b;
        return ONE_ROOT;

    }

}



int SolveSquare (Coefficients* equation_coeff,
                 Result*       equation_res) {

    double Discriminant = equation_coeff->b * equation_coeff->b - 4 * equation_coeff->a * equation_coeff->c;

    if (Discriminant < 0) {

        return ZERO_ROOTS;

    } else {

        equation_res->x1 = (-equation_coeff->b - sqrt(Discriminant)) / ( 2 * (equation_coeff->a));
        equation_res->x2 = (-equation_coeff->b + sqrt(Discriminant)) / ( 2 * (equation_coeff->a));

        return TWO_ROOTS;

    }

}
