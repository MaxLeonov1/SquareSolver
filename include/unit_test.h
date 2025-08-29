#ifndef _UNIT_TEST_
#define _UNIT_TEST_

/*!
    \file Хедер функций unit тестов
*/

void RunTests                             (const char tests_file_name[]);
int  EquationSolverTest                   (SolverTestData* test_data);
struct SolverTestData* ScanUnitTestData   (const char file_name[], int* number_tests);

#endif