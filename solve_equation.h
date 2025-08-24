#ifndef _SOLV_EQ_H_
#define _SUPP_EQ_H_

int SolveLinear (double* coefficient_b, double* coefficient_c,
                 double* solution_1, double* solution_2);
int SolveSquare (double* coefficient_a, double* coefficient_b, double* coefficient_c,
                 double* solution_1, double* solution_2);

#endif