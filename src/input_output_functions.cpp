#include <stdio.h>
#include <assert.h>

#include "supporting_functions.h"
#include "structures.h"
#include "enum_number_res.h"
#include "input_output_functions.h"
#include "colours.h"


//! \file Файл для функций ввода и вывода

/*!
    \brief Функция считывает коэффициены уравнения из стандартного ввода.

    Функция принимает указатель на структуру хранящую коэффициенты уравнений,
    считывает и записывает значения в структуру. Функция ничего не возвращает.

    \param[in] equation_coeff указатель на структуру с коэффициентами
*/
void ScanCoefficients(struct Coefficients* equation_coeff) {

    assert(equation_coeff != 0);

    int coefficient_number = 0;

    while(1) {

        printf("_______________________________________\n"
               "Enter 3 coefficients separated by space\n"
               " %s(only 3 coefficients will be scaned)%s\n"
               "_______________________________________\n", YELLOW, RES_COL);
        coefficient_number = scanf( "%lf %lf %lf", &(*equation_coeff).a, &(*equation_coeff).b, &(*equation_coeff).c);

        if(coefficient_number < 3) {

            ResetInputBuffer();
            coefficient_number = 0;

            printf("___________________________\n"
                   "%sIncorrect input, try again.%s\n"
                   "___________________________\n", RED, RES_COL);

        } else {

            break;

        }

    }

}

/*!
    \brief Функция выводит результат вычесления корней в терминал

    Функция принимае переменную типа int с количеством решений и два указателя на переменные типа double.
    В зависимости от количества решений выводит в терминал случаи решения уравнения:
        *Бесконечное число решений
        *Нет решений
        *Случай с линейным уравнением
        *Случай с квадратным уранением
    Функция ничего не возвращает.
    
    \param[in] solution_number количество решений
    \param[in] solution_1, solution_2 решения уравнений
*/
void PrintSolutions(int solution_number, double* solution_1, double* solution_2) {

    assert(solution_1 != 0 || solution_2 != 0);

    switch(solution_number) {

        case INFINITE_ROOTS:

            printf("____________________________\n"
                   "%sInfinite number of solutions%s\n"
                   "____________________________\n",
                   GREEN, RES_COL);
            break;

        case ZERO_ROOTS:

            printf("_____________________\n"
                   "%sThere is no solutions%s\n"
                   "_____________________\n", 
                   RED, RES_COL);
            break;

        case ONE_ROOT:

            printf("______________________________________________\n"
                   "It's a linear equation. Solution is %s%.2lf%s"
                   "______________________________________________\n",
                   GREEN, *solution_1, RES_COL);
            break;

        case TWO_ROOTS:

            if (DoubleCompare(*solution_1, *solution_2)) {

                printf("_______________________\n"
                       "Solution is: %s%.2lf%s\n"
                       "_______________________\n",
                       GREEN, *solution_1, RES_COL);
            }
            else {

                printf("_____________________________________\n"
                       "Solutions are: %s%.2lf, %.2lf%s\n"
                       "_____________________________________\n",
                       GREEN, *solution_1, *solution_2, RES_COL);
            }
            break;

        default:

            break;
            
    }

}