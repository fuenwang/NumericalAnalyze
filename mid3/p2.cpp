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

int main(int argc, char *argv[]){
    // (x + 1)(x - 1) = 0
    int order = 4;
    VEC A(order + 1);
    VEC x(order);
    x = 1; 
    double buf21[] = {105, -176, 86, -16, 1};
    double buf22[] = {120, 194, 89, 16, 1};
    double buf23[] = {180, -24, -37, 0, 1};
    double buf24[] = {105, -176, 0, -16, 1};
    double buf25[] = {105, 0, 86, 0, 1};
    A = buf25;

    NewtonPoly(A, x, 1000, 1e-9);
    x.print();
    return 0;
}
















