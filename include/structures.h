#ifndef _STRUCTURES_
#define _STRUCTURES_

/*!
    \file Хедер со всеми структурами
*/

/*!
    \brief Структура для хранения коэффициентов уравнения

    \param a, b, c коэффициенты уравнения
*/
struct Coefficients {

    double a, b, c;
    
};

/*!
    \brief Структура для хранения решений уравнения

    \param x1, x2 решения уравнений
*/
struct Result {

    double x1, x2;

};

/*!
    \brief Структура для хранения параметров для unit тестов

    \param a, b, c коэффициенты уравнения
    \param ref_x1, ref_x2 референсные решения
    \param number_roots количество корней
*/
struct SolverTestData {

    double a, b, c;
    double ref_x1, ref_x2;
    int number_roots;

};

#endif
