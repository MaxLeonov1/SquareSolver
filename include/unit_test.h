#ifndef _UNIT_TEST_
#define _UNIT_TEST_

void RunTests           (char tests_file_name[]);
int  EquationSolverTest (SolverTestData* test_data);
struct SolverTestData* ScanUnitTestData   (char file_name[], int* number_tests);

#endif