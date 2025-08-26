#include <stdio.h>
#include <math.h>

#include "supporting_functions.h"

//! \file Файл для вспомогательных функций

/*!
    \brief Функция выполняет сравнение двух переменных типа double с учетом возможности накопления погрешности.
    
    Функция принимает значения двух переменных типа double и сравнивает их разность с заданой в функции погрешностью.
    Функция возвращает значение int 1 если они равны, int 0 если нет.
*/
int DoubleCompare (double double_1, double double_2) {

    const double error = 1e-6;

    return (fabs (double_1 - double_2) < error) ? 1 : 0;
}

/*!
    \brief Функция очистки буффера ввода

    Ничего не принимает и не возвращает.
    Проходится функцией getchar() по буфферу пока не дойдёт до символа новой строки.
*/
void ResetInputBuffer (void) {

    while (getchar() != '\n');
}

/*!
    \brief Функция для вывода сообщения о ошибки во время тестирования функций решения уравнения.

    Принимает переменные типа double для значений коэффициентов уравнения , решнений и референсных решений,
    а также переменные типа int для количества решений и референсного количества решений.
    Выводит всю информацию в терминал.
    Функция ничего не возвращает
*/
void PrintTestFailMessage (double coefficient_a,  double coefficient_b,  double coefficient_c,  
                           double solution_1,     double solution_2,     int number_root,
                           double ref_solution_1, double ref_solution_2, int ref_number_root) {

    printf ("EquationSolverTest - Failed.\n"
            "_______________________________________________\n"
            "Coefficients are:\n"
            "A: %lf, B: %lf, C: %lf\n"
            "_______________________________________________\n"
            "Your result:\n"
            "_______________________________________________\n"
            "solution_1 = %lf\n"
            "solution_2 = %lf\n"
            "number_roots = %d\n"
            "_______________________________________________\n"
            "Expected result:\n"
            "_______________________________________________\n"
            "solution_1 = %lf\n"
            "solution_2 = %lf\n"
            "number_roots = %d\n"
            "_______________________________________________\n",
            coefficient_a,  coefficient_b,  coefficient_c, 
            solution_1,     solution_2,     number_root,
            ref_solution_1, ref_solution_2, ref_number_root);

}

/*!
    \brief Функция задаёт режим работы программы (тестирование или решение)
    
    Функция считывает из терминала символ. В случае символа Т возвращает int 0, в случае символа S - int 1,
    в иных случаях выводит сообщение о ошибке ввода и начинает процедуру выбора режима сначала.
*/
int SetWorkingMode(void) {

    char working_mode = 'S';

    while(1) {

        printf("Select working mode. Input T for testing and S for solving\n");
        scanf("%c", &working_mode);

        switch(working_mode) {
            case 'S':
                return 1;
                break;
            case 'T':
                return 0;
                break;
            default:
                printf("Incorect input, try again\n");
                ResetInputBuffer();
        }
    }

}