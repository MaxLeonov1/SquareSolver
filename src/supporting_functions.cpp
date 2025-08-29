#include <stdio.h>
#include <math.h>

#include "supporting_functions.h"
#include "colours.h"

//! \file Файл для вспомогательных функций

/*!
    \brief Функция выполняет сравнение двух переменных типа double с учетом возможности накопления погрешности.
    
    \details Функция принимает значения двух переменных типа double и сравнивает их разность с заданой в функции погрешностью.
    Функция возвращает значение int 1 если они равны, int 0 если нет.

    \param[in] double_1 первое число для сравнения
    \param[in] double_2 второе число для сравнения

    \return 1 если равны, 0 если нет 
*/
int DoubleCompare (double double_1, double double_2) {

    const double error = 1e-6;

    return (fabs (double_1 - double_2) < error) ? 1 : 0;
}

/*!
    \brief Функция очистки буффера ввода

    \details Ничего не принимает и не возвращает.
    Проходится функцией getchar() по буфферу пока не дойдёт до символа новой строки.
*/
void ResetInputBuffer (void) {

    while (getchar() != '\n');

} // isspace

/*!
    \brief Функция для вывода сообщения о ошибки во время тестирования функций решения уравнения.

    \details Принимает переменные типа double для значений коэффициентов уравнения , решнений и референсных решений,
    а также переменные типа int для количества решений и референсного количества решений.
    Выводит всю информацию в терминал.
    Функция ничего не возвращает

    \param[in] coefficient_a, coefficient_b, coefficient_c коэффициенты передаваемые функции решения
    \param[in] solution_1, solution_2 решения найденные функцией решения 
    \param[in] number_root количество корней найденное функцией решения
    \param[in] ref_solution_1, ref_solution_2 референсные решения
    \param[in] ref_number_root референсное количество корней
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
    \brief Функция вывода сообщения о неизвестной команде
*/
void UndefCommandPrint(void) {

    printf("%s----------------\n"
             "Undefined comand\n"
             "----------------%s\n",
             RED, RES_COL);


}