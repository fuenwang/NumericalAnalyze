// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

double func(double x){
    return x + pow(x, 0.5) + pow(x, 1.0/3) + pow(x, 1.0/4) - 10;
}
double func_der(double x){
    return 1 - 2 * log(x) / x;
}

int main(int argc, char *argv[]){
    double x;
    double a = 0;
    double b = 11;
    Bisection(func, a, b, x, 1000, 1e-11);
    printf("X = %g\n", x);
    cout << func(x) << endl;
    return 0;
}
