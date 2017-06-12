// HW12: RLC Circult
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

#define V 1
#define R 1
#define L 1
#define C 1

VEC cost1_1(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = pow(2, x) + pow(2, 2*x) - 3;
    return out;
}
VEC cost1_2(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = pow(2, x) + log2(x) - 1;
    return out;
}
VEC cost1_3(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = sin(2 * x) + sin(4 * x *x) + sin(8 * x * x * x) - 1;
    return out;
}
VEC cost1_4(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = pow(2, x) * pow(sin(x), 2) * pow(cos(x), 2) - 1;
    return out;
}
VEC cost1_5(const VEC &x0){
    double x = x0[0];
    VEC out(1);
    out[0] = 1.0 / x + 1.0 / pow(x, 2) + 1.0 / pow(x, 3) + 1.0 / pow(x, 4) - 1;
    return out;
}

int main(int argc, char *argv[]){
    VEC x0(1);
    x0[0] = 0.1;
    cout << CyclicJacobian(cost1_5, x0, 100000, 1e-9, 1e-4) << endl;
    x0.print();
    cost1_5(x0).print();
    return 0;
}
















