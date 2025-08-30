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

    \details Тут происходит запуск программы и задание основных переменных, выбор режима работы 
    по средством ввода аргументов командной строки

    \note -t или --test для режима тестирования
          -s или --solve для режима решения
*/
int main(const int argc, const char* argv[]) {
    
    int                 solution_number = 0;
    struct Coefficients equation_coeff  = { .a = 0, .b = 0, .c = 0 };
    struct Result       equation_res    = { .x1 = 0, .x2 = 0 };

    if (argc >= 2) {

        if ((strcmp(argv[1], "--solve") == 0 ||
             strcmp(argv[1], "-s") == 0)) {///* Pежим решения уравнения

            if (argc == 2) {

                                  ScanCoefficients (&equation_coeff);
                solution_number = EquationSolver   (&equation_coeff, &equation_res);
                                  PrintSolutions   (solution_number, &equation_res.x1, &equation_res.x2);

            } else if ((strcmp(argv[2], "--file") == 0 ||
                        strcmp(argv[2], "-f") == 0) && 
                        argc == 4 && fopen(argv[3], "r") != NULL) {

                printf("FILE_INPUT\n");

            } else {

                UndefCommandPrint();

            }

        } else if ((strcmp(argv[1], "--test") == 0 ||
                    strcmp(argv[1], "-t")) == 0 && 
                    argc == 3 && fopen(argv[2], "r") != NULL) {///* Режим тестирования

            RunTests(argv[2]);

        } else {

            UndefCommandPrint();

        } 

    } else {

        UndefCommandPrint();

    }

    return 0;
    
}