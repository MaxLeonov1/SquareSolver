#ifndef _SUPP_FUNC_H_
#define _SUPP_FUNC_H_

int  SetWorkingMode       (void);
int  DoubleCompare        (double double_1, double double_2);
void ResetInputBuffer     (void);
void PrintTestFailMessage (double coefficient_a, double coefficient_b, double coefficient_c,
                           double solution_1, double solution_2, int number_root,
                           double ref_solution_1, double ref_solution_2, int ref_number_root);

#endif