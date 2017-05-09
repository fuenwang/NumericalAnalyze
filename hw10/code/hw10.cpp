// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>


int main(int argc, char *argv[]){
    int block = 1536;
    int order = 6;
    double h = 2.0 / block;
    VEC Y(block + 1);
    VEC X(block + 1);
    for(int i=0; i <= block; i++){
        X[i] = i * h;
        Y[i] = exp(i * h);
    }
    double answer = exp(2) - exp(0);
    double my_answer = Integrate(order, X, Y);
    printf("Answer = %lf\n", answer);
    printf("My Answer = %lf\n", my_answer);
    printf("Error = %g\n", fabs(my_answer - answer));
    return 0;
}
