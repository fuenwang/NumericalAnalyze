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
    //double a[] = {0, 1.5, 2.25, 3, 3.75, 4.5, 6};
    //double b[] = {0, 0.578571, 0.885052, 1, 0.885052, 0.578571, 0};
    //double a[] = {0, 0.75, 1.5, 3, 4.5, 5.25, 6};
    //double b[] = {0, 0.204167, 0.578571, 1, 0.578571, 0.204167, 0};
    double a[] = {0, 0.75, 1.5, 2.25, 3, 3.75, 4.5, 5.25, 6};
    double b[] = {0, 0.204167, 0.578571, 0.885052, 1, 0.885052, 0.578571, 0.204167, 0};

    int N = 9;
    VEC xs(N);
    VEC ys(N);
    VEC M(N);
    xs = a;
    ys = b;
    splineM(N, xs, ys, M);

    xs.print();
    ys.print();

    printf("%g\n", spline(1, N, xs, ys, M));
    printf("%g\n", spline(2, N, xs, ys, M));
    printf("%g\n", spline(4, N, xs, ys, M));
    printf("%g\n", spline(5, N, xs, ys, M));
    return 0;
}
