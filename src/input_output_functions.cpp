#include <stdio.h>

#include "supporting_functions.h"
#include "structures.h"
#include "enum_number_res.h"
#include "input_output_functions.h"

//! \file Файл для функций ввода и вывода

/*!
    \brief Функция считывает коэффициены уравнения из стандартного ввода.

    Функция принимает указатель на структуру хранящую коэффициенты уравнений,
    считывает и записывает значения в структуру. Функция ничего не возвращает.

    \param[in] equation_coeff указатель на структуру с коэффициентами
*/
void ScanCoefficients(struct Coefficients* equation_coeff) {
    int coefficient_number = 0;

    while(1) {

        printf("_____________________________________\n"
               "Enter coefficients separated by space\n"
               "_____________________________________\n");
        coefficient_number = scanf( "%lf %lf %lf", &(*equation_coeff).a, &(*equation_coeff).b, &(*equation_coeff).c);

        if(coefficient_number < 3) {

            ResetInputBuffer();
            coefficient_number = 0;

            printf("___________________________\n"
                   "\033[31mIncorrect input, try again.\033[0m\n"
                   "___________________________\n");

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

    switch(solution_number) {

        case INFINITE_ROOTS:

            printf("____________________________\n"
                   "\033[32mInfinite number of solutions\033[0m\n"
                   "____________________________\n");
            break;

        case ZERO_ROOTS:

            printf("_____________________\n"
                   "\033[31mThere is no solutions\033[0m\n"
                   "_____________________\n");
            break;

        case ONE_ROOT:

            printf("______________________________________________\n"
                   "It's a linear equation. Solution is \033[32m%.2lf\033[0m\n"
                   "______________________________________________\n",
                   *solution_1);
            break;

        case TWO_ROOTS:

            if (DoubleCompare(*solution_1, *solution_2)) {

                printf("_______________________\n"
                       "Solution is: \033[32m%.2lf\033[0m\n"
                       "_______________________\n",
                       *solution_1);
            }
            else {

                printf("_____________________________________\n"
                       "Solutions are: \033[32m%.2lf, %.2lf\033[0m\n"
                       "_____________________________________\n",
                       *solution_1, *solution_2);
            }
            break;

        default:

            break;
            
    }

}