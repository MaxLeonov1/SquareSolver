#include <stdio.h>

#include "input_output_functions.h"
#include "supporting_functions.h"
#include "solve_equation.h"
#include "unit_test.h"
#include "structures.h"
#include "enum_number_res.h"



// SolverTestData tests[] = {{.a = 0, .b =  1, .c = 4, .ref_x1 = -4, .ref_x2 = -4, .number_roots = ONE_ROOT},
//                           {.a = 0, .b =  0, .c = 1, .ref_x1 =  0, .ref_x2 =  0, .number_roots = ZERO_ROOTS},
//                           {.a = 0, .b =  0, .c = 0, .ref_x1 =  0, .ref_x2 =  0, .number_roots = INFINITE_ROOTS},
//                           {.a = 1, .b =  4, .c = 3, .ref_x1 = -3, .ref_x2 = -1, .number_roots = TWO_ROOTS},
//                           {.a = 1, .b = -2, .c = 1, .ref_x1 =  1, .ref_x2 =  1, .number_roots = TWO_ROOTS}};

struct SolverTestData tests[5];



void RunTests (char tests_file_name[]) {

    int  test_pased = 0;
    int  size       = 0;

    ScanUnitTestData (tests_file_name, tests);

    size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        test_pased += EquationSolverTest (&tests[i]);

    }

    printf("Passed tests: %d \n", test_pased);

}



void ScanUnitTestData (char file_name[], SolverTestData tests[]) {

    FILE* unit_test_data = fopen(file_name, "r");
    
    int   number_tests = 5;

    for (int test_ind = 0; test_ind < number_tests; test_ind++) {

        fscanf(unit_test_data, "%lf %lf %lf %lf %lf %d ",
                                &(tests[test_ind].a), &(tests[test_ind].b), &(tests[test_ind].c),
                                &(tests[test_ind].ref_x1), &(tests[test_ind].ref_x2),
                                &(tests[test_ind].number_roots));

    }
            
}



int EquationSolverTest (SolverTestData* test_data) {
    
    Result       test_solution     = {.x1 = 0, .x2 = 0};
    Coefficients test_coefficients = {.a = test_data->a,
                                      .b = test_data->b,
                                      .c = test_data->c};

    int number_roots = EquationSolver (&test_coefficients, &test_solution); 

    if (!(DoubleCompare (test_solution.x1, test_data->ref_x1) &&
          DoubleCompare (test_solution.x2, test_data->ref_x2) &&
          number_roots == test_data->number_roots)) {

        PrintTestFailMessage (test_data->a,      test_data->b,      test_data->c,
                              test_solution.x1,  test_solution.x2,  number_roots,
                              test_data->ref_x1, test_data->ref_x2, test_data->number_roots); 

    } else {

        return 1;

    }

}