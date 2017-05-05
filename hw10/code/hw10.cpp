// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

double f(double x){
    return exp(x);
}

int main(int argc, char *argv[]){
    double answer = exp(2) - exp(0);

    double my_answer = Integrate(exp, 0, 2, 1536, 1);
    printf("Answer = %lf\n", answer);
    printf("My Answer = %lf\n", my_answer);
    return 0;
}
