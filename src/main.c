#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "input_output_functions.h"
#include "supporting_functions.h"
#include "solve_equation.h"
#include "structures.h"
#include "unit_test.h"

/*!
    Определяет максимальную длину названия файла
*/
#define MAXFILENAME 100 

/*!
    \brief Главная функция

    Тут проиходит запуск программы и задание основных переменных
*/
int main() {
    
    int solution_number = 0;
    struct Coefficients equation_coeff = { .a = 0, .b = 0, .c = 0 };
    struct Result       equation_res   = { .x1 = 0, .x2 = 0 };
    char test_file_name[MAXFILENAME] = "";

    if (SetWorkingMode()) {///Работа в режиме решения уравнения

                          ScanCoefficients (&equation_coeff);
        solution_number = EquationSolver   (&equation_coeff, &equation_res);
                          PrintSolutions   (solution_number, &equation_res.x1, &equation_res.x2);

    } else {///Работа в режиме тестирования

        printf("Input test parametrs file name\n");
        scanf("%s", test_file_name);

        RunTests(test_file_name);

    }

    return 0;
    
}

