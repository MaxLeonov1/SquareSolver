#include <stdio.h>

#include "input_output_functions.h"
#include "supporting_functions.h"
#include "solve_equation.h"
#include "unit_test.h"



void RunTests(void) {
    int test_failed = 0;

    test_failed += EquationSolverTest(0, 1, 4, -4, -4, 1);
    test_failed += EquationSolverTest(0, 0, 1, 0, 0, 0);
    test_failed += EquationSolverTest(0, 0, 0, 0, 0, -1);
    test_failed += EquationSolverTest(1, 4, 3, -3, -1, 2);

    printf("Failed tests: %d \n", test_failed);
}



int  EquationSolverTest (double coefficient_a, double coefficient_b, double coefficient_c,
                         double ref_solution_1, double ref_solution_2, int ref_number_root) {
    
    double solution_1 = 0, solution_2 = 0;
    int number_root = 0;

    if (DoubleCompare(coefficient_a, 0)) {

        number_root = SolveLinear(&coefficient_b, &coefficient_c, &solution_1, &solution_2);

    } else {

        number_root = SolveSquare(&coefficient_a, &coefficient_b, &coefficient_c, &solution_1, &solution_2);

    }

    if (!(DoubleCompare(solution_1, ref_solution_1) &&
          DoubleCompare(solution_1, ref_solution_2) &&
          number_root == ref_number_root)) {

        PrintTestFailMessage(coefficient_a, coefficient_b, coefficient_c,
                             solution_1,  solution_2,  number_root,
                             ref_solution_1,  ref_solution_2,  ref_number_root); 


        return 1;
    }
}

