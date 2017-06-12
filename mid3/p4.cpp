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

VEC cost4_1(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = x - 3 * y * y - y + 1.07;
    out[1] = y - x * x - 3 * x + 3.81;
    return out;
}
VEC cost4_2(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = pow(x, 2) + x*y + pow(y, 2) + x - 4.16;
    out[1] = pow(y, 2) + x + y - 2.56;
    return out;
}
VEC cost4_3(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = y - sqrt(x + 1) + 0.60384;
    out[1] = x - sqrt(y + 2) + 0.943168;
    return out;
}
VEC cost4_4(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = y - pow(x, 3) - x - 1.375;
    out[1] = x - pow(y, 3) - 2 * y + 11.5;
    return out;
}
VEC cost4_5(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = y - 1.0 / (x+1) - 5.0/3.0;
    out[1] = x - 2.0 / (y+1) - 4.0/3.0;
    return out;
}
VEC cost4_6(const VEC &x0){
    double x = x0[0];
    double y = x0[1];
    VEC out(2);
    out[0] = y - sin(x) - 0.208793;
    out[1] = x - cos(y) - 0.646404;
    return out;
}

int main(int argc, char *argv[]){
    VEC x0(2);
    CyclicJacobian(cost4_6, x0, 1000, 1e-10, 0.001);
    x0.print();
    cost4_6(x0).print();
    return 0;
}
















