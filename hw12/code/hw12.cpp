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

VEC Forward(const VEC &x0, double h){
    double V1_t = x0[0];
    double V2_t = x0[1];
    double iL_t = x0[2];
    
    x0[1] = (1 / (h * C)) * iL_t + V2_t;
    x0[2] = (h / L) * (V1_t - V2_t);
    x0[0] = V - R * x0[2];

    return x0;
}

int main(int argc, char *argv[]){
    VEC x0(3); // [v1, v2, iL]
    x0[0] = 1; // v1(0) = 1
    OrdDiff(Forward, x0, 0, 10, 0.01);  
    x0.print();
    return 0;
}
















