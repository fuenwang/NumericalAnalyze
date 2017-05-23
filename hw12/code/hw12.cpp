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

VEC Forward(VEC &x0, double h){
    double V1_t = x0[0];
    double V2_t = x0[1];
    double iL_t = x0[2];
    
    x0[1] = (h / C) * iL_t + V2_t;
    x0[2] = (h / L) * (V1_t - V2_t) + iL_t;
    x0[0] = V - R * x0[2];

    return x0;
}

VEC Backward(VEC &x0, double h){
    double V2_t = x0[1];
    double iL_t = x0[2];
    
    x0[2] = (iL_t - (h / L) * V2_t + (h * V) / L) / (1 + pow(h, 2) / (L * C) + (h * R) / L);
    x0[0] = V - R * x0[2];
    x0[1] = V2_t + (h / C) * x0[2];
    return x0;
}

VEC Trap(VEC &x0, double h){
    double V1_t = x0[0];
    double V2_t = x0[1];
    double iL_t = x0[2];
    
    double tmp0 = 1 + (h * h) / (4 * L * C) + (h * R) / (2 * L);
    double tmp1 = 1 - (h * h) / (4 * L * C);
    x0[2] = (tmp1 * iL_t + h / (2 * L) * (V + V1_t - 2 * V2_t)) / tmp0;
    x0[0] = V - R * x0[2];
    x0[1] = V2_t + (h / (2 * C)) * (x0[2] + iL_t);
    return x0;
}

int main(int argc, char *argv[]){
    double h = 0.1;
    VEC x0(3); // [v1, v2, iL]
    
    x0[0] = 1; // v1(0) = 1
    OrdDiff(Forward, x0, 0, 10, h); 
    
    
    x0 = 0;
    x0[0] = 1;
    OrdDiff(Backward, x0, 0, 10, h);
    
    
    x0 = 0;
    x0[0] = 1;
    OrdDiff(Trap, x0, 0, 10, h);
    
    //x0.print();
    return 0;
}
















