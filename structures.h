#ifndef _STRUCTURES_
#define _STRUCTURES_

struct Coefficients {

    double a, b, c;
    
};


struct Result {

    double x1, x2;

};

struct SolverTestData {

    double a, b, c,
           ref_x1, ref_x2;
    int    number_roots;

};

#endif
