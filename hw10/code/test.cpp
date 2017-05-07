// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

double func(double x){
    return x - log(x) * log(x) - 0.9;
}
double func_der(double x){
    return 1 - 2 * log(x) / x;
}

int main(int argc, char *argv[]){
    int order = 5;
    VEC x(order);
    VEC poly(order + 1);
    VEC t(order + 1);
    double a[] = {-10120200, -211502, 10118997, 211501, 1203, 1};
    poly = a;
    poly.print();
    t.print();
    t = poly;
    t.print();
    NewtonPoly(poly, x, 1000, 1e-9);
    x.print();
    return 0;
}
