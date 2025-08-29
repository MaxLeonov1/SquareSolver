#include <stdio.h>
#include <stdlib.h>

#include "input_output_functions.h"
#include "supporting_functions.h"
#include "solve_equation.h"
#include "unit_test.h"
#include "structures.h"
#include "enum_number_res.h"

//! \file Файл с функциями для Unit тестов

/*!
    \brief Функция запуска тестирования вычисления корней.

    \details Принимает строку с путём файла с аргументами тестов в качестве аргумента.
    Подсчитывает количество пройденых тестов и ввыводит их в терминал.
    Ничего не возвращает.

    \param[in] tests_file_name

*/
void RunTests (const char tests_file_name[]) {

    int  test_pased = 0;
    int  size       = 0;

    struct SolverTestData* tests = ScanUnitTestData (tests_file_name, &size);

    for (int i = 0; i < size; i++) {

        test_pased += EquationSolverTest ( &tests[i] );
        
    }

    printf("Passed tests: %d \n", test_pased);

}

/*!
    \brief Функция считывает из файла аргументы тестирования

    \details Функция принимает указатель на int переменную с количеством тестов,
    и строку с путём файла. Считывает из первой строки файла значение количества тестов, 
    затем из каждой следующей строки считывает аргументы для тестов.
    Затем записывает агрументы в массив структур аргументов тестирования и возвращает указатель на массив.

    \warning требуется указывать путь до файла

    \param[in] number_test количество тестов
    \param[in] file_name название файла

    \return указатель на массив структур с аргументами тестов
*/
struct SolverTestData* ScanUnitTestData (const char file_name[], int* number_tests) {
    
    FILE* unit_test_data = fopen(file_name, "r");
    struct SolverTestData* tests = nullptr;

    fscanf(unit_test_data, "%d", number_tests);
    tests = (struct SolverTestData*) calloc(*number_tests, sizeof(struct SolverTestData));

    for (int test_ind = 0; test_ind < *number_tests; test_ind++) {

        fscanf(unit_test_data, "%lf %lf %lf %lf %lf %d ",
                                &(tests[test_ind].a), &(tests[test_ind].b), &(tests[test_ind].c),
                                &(tests[test_ind].ref_x1), &(tests[test_ind].ref_x2),
                                &(tests[test_ind].number_roots));

    }

    return tests;
            
}

/*!
    \brief Функция тестирует решения уравнения.

    \details Функция принимает указатель на структуру с аргументами для тестирования, 
    затем передаёт коеффициеты в функцию для решения и сравнивает полученый результат с референсным,
    в случае ошибки передает значения в функцию для вывода сообщения о ошибке,
    в ином случае возвращает int 1.

    \param[in] test_data

    \return int 1 в случае удачного тестирования
*/
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