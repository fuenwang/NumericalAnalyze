// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>


int main(int argc, char *argv[]){
    int block = 192;
    //int order = 6;
    double h = 2.0 / block;
    VEC Y(block + 1);
    VEC X(block + 1);
    for(int i=0; i <= block; i++){
        X[i] = i * h;
        Y[i] = exp(i * h);
    }
    double answer = exp(2) - exp(0);
    double my_answer1 = Integrate(1, X, Y);
    double my_answer2 = Integrate(2, X, Y);
    double my_answer3 = Integrate(3, X, Y);
    double my_answer4 = Integrate(4, X, Y);
    double my_answer5 = Integrate(6, X, Y);
    printf("Answer = %lf\n", answer);
    printf("%d intervals\n", block);

    printf("I1 = %lf\n", my_answer1);
    printf("E1 = %g\n", fabs(my_answer1 - answer));

    printf("I2 = %lf\n", my_answer2);
    printf("E2 = %g\n", fabs(my_answer2 - answer));

    printf("I3 = %lf\n", my_answer3);
    printf("E3 = %g\n", fabs(my_answer3 - answer));

    printf("I4 = %lf\n", my_answer4);
    printf("E4 = %g\n", fabs(my_answer4 - answer));

    printf("I6 = %lf\n", my_answer5);
    printf("E6 = %g\n", fabs(my_answer5 - answer));

    return 0;
}
