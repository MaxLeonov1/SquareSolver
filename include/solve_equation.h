#ifndef _SOLV_EQ_H_
#define _SUPP_EQ_H_

#include "structures.h"

int EquationSolver (Coefficients* equation_coeff,
                    Result*       equation_res);
int SolveLinear    (Coefficients* equation_coeff,
                    Result*       equation_res);
int SolveSquare    (Coefficients* equation_coeff,
                    Result*       equation_res);

#endif