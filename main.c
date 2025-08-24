#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



struct coefficients {
    double a, b, c;
};

struct coefficients equation_coeff = { .a = 0, .b = 0, .c = 0 };

struct result {
    double x1, x2;
};

struct result equation_res = { .x1 = 0, .x2 = 0 };




int     DoubleCompare    (double double_1, double double_2);
int     SolveSquare      (double* coefficient_a, double* coefficient_b, double* coefficient_c,
                          double* solution_1, double* solution_2);
int     SolveLinear      (double* coefficient_b, double* coefficient_c,
                          double* solution_1, double* solution_2);
void    ScanCoefficients (struct coefficients equation_coeff);
void    PrintSolutions   (int solution_number, double* solution_1, double* solution_2);
void    ResetInputBuffer (void);



int main() {
    
    int solution_number = 0;

    ScanCoefficients(equation_coeff);

    if (DoubleCompare(equation_coeff.a, 0)) {
        solution_number = SolveLinear(&equation_coeff.b, &equation_coeff.c,
                                      &equation_res.x1, &equation_res.x2);
    }
    else {
        solution_number = SolveSquare(&equation_coeff.a, &equation_coeff.b, &equation_coeff.c,
                                      &equation_res.x1, &equation_res.x2);
    }

    PrintSolutions(solution_number, &equation_res.x1, &equation_res.x2);
    
    return 0;
}



void ScanCoefficients(struct coefficients equation_coeff) {
    int coefficient_number = 0;

    while(1) {
        printf("Enter coefficients separated by space\n");
        coefficient_number = scanf( "%lf %lf %lf", &equation_coeff.a, &equation_coeff.b, &equation_coeff.c);

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



int SolveLinear(double* coefficient_b, double* coefficient_c,
                double* solution_1, double* solution_2) {

    if (DoubleCompare(*coefficient_b, 0)) {

        if (DoubleCompare(*coefficient_c, 0)) {
            return -1;
        }
        else {
            return 0;
        }
    }
    else {
        *solution_1 = *solution_2 = -*coefficient_c / *coefficient_b;
        return 1;
    }                  
}



int SolveSquare(double* coefficient_a, double* coefficient_b, double* coefficient_c,
                double* solution_1, double* solution_2) {

    double Discriminant = (*coefficient_b)*(*coefficient_b) - 4*(*coefficient_a)*(*coefficient_c);

    if (Discriminant < 0) {
        return 0;
    }
    else {
        *solution_1 = (-*coefficient_b - sqrt(Discriminant)) / (2*(*coefficient_a));
        *solution_2 = (-*coefficient_b + sqrt(Discriminant)) / (2*(*coefficient_a));

        return 2;
    }
}



void PrintSolutions(int solution_number, double* solution_1, double* solution_2) {

    switch(solution_number) {
        case -1:
            printf("Infinite number of solutions");
            break;

        case 0:
            printf("There is no solutions");
            break;

        case 1:
            printf("It's a linear equation. Solution is %.2lf", *solution_1);
            break;

        case 2:
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



int DoubleCompare(double double_1, double double_2) {

    const double error = 1e-6;

    return (fabs(double_1 - double_2) < error) ? 1 : 0;
}

void ResetInputBuffer(void) {

    while(getchar() != '\n');
}
