// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>


int main(int argc, char *argv[]){
    int block = 12;
    int order = 6;
    VEC Y(block);
    double step = 2.0 / block;
    for(int i=0; i<block; i++){
        Y[i] += i * step;
    }
    double answer = exp(2) - exp(0);
    double my_answer = Integrate(exp, order, Y, step);
    printf("Answer = %lf\n", answer);
    printf("My Answer = %lf\n", my_answer);
    printf("Error = %g\n", fabs(my_answer - answer));
    return 0;
}
