#include <stdio.h>

#include "supporting_functions.h"
#include "structures.h"
#include "enum_number_res.h"
#include "input_output_functions.h"


void ScanCoefficients(struct coefficients* equation_coeff) {
    int coefficient_number = 0;

    while(1) {
        printf("Enter coefficients separated by space\n");
        coefficient_number = scanf( "%lf %lf %lf", &(*equation_coeff).a, &(*equation_coeff).b, &(*equation_coeff).c);

        if(coefficient_number < 3) {
            ResetInputBuffer();
            coefficient_number = 0;

            printf("Incorrect input, try again.\n");
        } 
        else {
            break;
        }
    }
}



void PrintSolutions(int solution_number, double* solution_1, double* solution_2) {

    switch(solution_number) {
        case INFINITE_ROOTS:
            printf("Infinite number of solutions");
            break;

        case ZERO_ROOTS:
            printf("There is no solutions");
            break;

        case ONE_ROOT:
            printf("It's a linear equation. Solution is %.2lf", *solution_1);
            break;

        case TWO_ROOTS:
            if (DoubleCompare(*solution_1, *solution_2)) {
                printf("Solution is: %.2lf", *solution_1);
            }
            else {
                printf("Solutions are: %.2lf, %.2lf", *solution_1, *solution_2);
            }
            break;

        default:
            break;
            
    }
}