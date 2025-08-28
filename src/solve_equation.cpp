#include <stdio.h>
#include <math.h>

#include "solve_equation.h"
#include "supporting_functions.h"
#include "enum_number_res.h"
#include "structures.h"

//! \file Файл для функций решающих уравнение

/*!
    \brief Функция для выбора оптимального способа решения уравнения.

    \details Принимает указатели на структуры содержащие коэффициенты и решения уравнения.
    В зависимости от значения коэффициена "а" передаёт указатели на переданные в неё стуктуры
    в функции для линейного решения уравнения или квадратного.
    Возвращает int переменную с количеством решений уравнения.

    \param[in] equation_coeff указатель на структуру с коэффициентами
    \param[in] equation_res   указатель на структуру с решениями

    \return количество корней
*/
int EquationSolver (Coefficients* equation_coeff,
                    Result*       equation_res) {

    if (DoubleCompare (equation_coeff->a, 0)) {

        return SolveLinear (equation_coeff, equation_res);

    }
    else {

        return SolveSquare (equation_coeff, equation_res);

    }

}

/*!
    \brief Функция для линейного решения уравнения.

    \details Принимает указатели на структуры содержащие коэффициенты и решения уравнения.
    Рассматривает 3 случая решения уравнения при коэффициенте "а" = 0:
        *Бесконечное число корней
        *Нет корней
        *Линейное решение с одним корнем
    Возвращает int переменную с количеством решений уравнения.

    \param[in] equation_coeff указатель на структуру с коэффициентами
    \param[in] equation_res   указатель на структуру с решениями

    \return количество корней
*/
int SolveLinear (Coefficients* equation_coeff,
                 Result*       equation_res) {

    if (DoubleCompare (equation_coeff->b, 0)) {

        if (DoubleCompare (equation_coeff->c, 0)) {

            return INFINITE_ROOTS;

        } else {

            return ZERO_ROOTS;

        }

    } else {

        equation_res->x1 = equation_res->x2 = -equation_coeff->c / equation_coeff->b;
        return ONE_ROOT;

    }

}

/*!
    \brief Функция для квадратного решения уравнения.

    \details Принимает указатели на структуры содержащие коэффициенты и решения уравнения.
    Рассматривает 2 случая решения уравнения при коэффициенте "а" != 0:
        *Нет корней
        *Квадратное решение с двумя корнями
    Возвращает int переменную с количеством решений уравнения.

    \param[in] equation_coeff указатель на структуру с коэффициентами
    \param[in] equation_res   указатель на структуру с решениями

    \return количество корней
*/
int SolveSquare (Coefficients* equation_coeff,
                 Result*       equation_res) {

    double Discriminant = equation_coeff->b * equation_coeff->b - 4 * equation_coeff->a * equation_coeff->c;

    if (Discriminant < 0) {

        return ZERO_ROOTS;

    } else {

        equation_res->x1 = (-equation_coeff->b - sqrt(Discriminant)) / ( 2 * (equation_coeff->a));
        equation_res->x2 = (-equation_coeff->b + sqrt(Discriminant)) / ( 2 * (equation_coeff->a));

        return TWO_ROOTS;

    }

}