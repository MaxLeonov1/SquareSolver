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
                   "Incorrect input, try again.\n"
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
*/
void PrintSolutions(int solution_number, double* solution_1, double* solution_2) {

    switch(solution_number) {

        case INFINITE_ROOTS:

            printf("____________________________\n"
                   "Infinite number of solutions\n"
                   "____________________________\n");
            break;

        case ZERO_ROOTS:

            printf("_____________________\n"
                   "There is no solutions\n"
                   "_____________________\n");
            break;

        case ONE_ROOT:

            printf("______________________________________________\n"
                   "It's a linear equation. Solution is %10.2lf\n"
                   "______________________________________________\n",
                   *solution_1);
            break;

        case TWO_ROOTS:

            if (DoubleCompare(*solution_1, *solution_2)) {

                printf("_______________________\n"
                       "Solution is: %10.2lf\n"
                       "_______________________\n",
                       *solution_1);
            }
            else {

                printf("_____________________________________\n"
                       "Solutions are: %10.2lf, %10.2lf\n"
                       "_____________________________________\n",
                       *solution_1, *solution_2);
            }
            break;

        default:

            break;
            
    }

}