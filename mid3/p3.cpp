// HW12: RLC Circult
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>
VEC X(9);
VEC Y(9);
VEC M(9);

VEC cost3(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = Lagrange(x, X, Y) - 1.65;
    return out;
}
VEC cost4(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = spline(x, X.dim(), X, Y, M) - 1.65;
    return out;
}

double linear(double y, double x1, double y1, double x2, double y2){
    // return x;
    double k = (y - y1) / (y2 - y);
    return (x1 + k * x2) / (1 + k);
}
double linear2(double x, double x1, double y1, double x2, double y2){
    // return y;
    double k = (x - x1) / (x2 - x);
    return (y1 + k * y2) / (1 + k);
}

int main(int argc, char *argv[]){
    double buf_x[] = {0, 0.1, 0.2, 0.3, 1, 1.1, 1.2, 1.3, 1.5};
    double buf_y[] = {0.015, -0.05141, 2.281, 3.1983, 3.3, 3.3799, 1.0181, 0.02002, 0.015};
    X = buf_x;
    Y = buf_y;
    splineM_period(X.dim(), X, Y, M);
    VEC x0(1);
    x0[0] = 0.2;
    //cout << CyclicJacobian(cost4, x0, 1000, 1e-10, 0.00001) << endl;
    //x0.print();
    double tmp1 = x0[0];
    x0[0] = 1.2;
    //cout << CyclicJacobian(cost4, x0, 1000, 1e-10, 0.00001) << endl;
    double tmp2 = x0[0];
    //cost4(x0).print();

    printf("%g\n", linear2(0.15, 0.1, -0.05141, 0.2, 2.281));
    printf("%g\n", linear2(0.25, 0.2, 2.281, 0.3, 3.1983));
    printf("%g\n", linear2(0.75, 0.3, 3.1983, 1, 3.3));
    printf("%g\n", linear2(1.15, 1.1, 3.3799, 1.2, 1.0181));
    printf("%g\n", linear2(1.25, 1.2, 1.0181, 1.3, 0.02002));
    return 0;
}
















