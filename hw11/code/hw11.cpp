// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

#define V 0.12
#define Is 1
#define phi 0.026
#define RL 0.01

VEC cost(const VEC &x0){
    VEC result(x0.dim());
    double V1 = x0[0];
    double V2 = x0[1];
    double tmp1 = Is * (exp((V-V1)/phi) + exp(-1*V1/phi) - 2);
    double tmp2 = -1 * Is * (exp((V2-V)/phi) + exp(V2/phi) - 2);
    double tmp3 = (V1 - V2) / RL;
    result[0] = Is * tmp1 - tmp3;
    result[1] = Is * tmp2 + tmp3;
    return result;
}


int main(int argc, char *argv[]){
    VEC x0(2);
    //VEC tmp(20);
    //tmp = cost(x0);
    //tmp.print();
    cout << CyclicJacobian(cost, x0, 100000, 1e-12, 0.00001, 1) << endl;
    x0.print();
    cost(x0).print();
    return 0;
}
