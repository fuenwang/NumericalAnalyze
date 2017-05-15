// HW10: Numerical Integration
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

#define Is 1
#define phi0 0.026
#define RL 0.01

double V = 0;

VEC cost1(const VEC &x0){
    VEC result(x0.dim());
    double V1 = x0[0];
    double V2 = x0[1];
    double I1 = Is * (exp((V-V1)/phi0) - 1);
    double I2 = Is * (exp(-1*V1/phi0) - 1);
    double I3 = Is * (exp((V2-V)/phi0) - 1);
    double I4 = Is * (exp(V2/phi0) - 1);
    double IRL = (V1 - V2) / RL;

    result[0] = I1 + I2 - IRL;
    result[1] = IRL - I3 - I4;
    return result;
}
// x0 = [V1, V2, T1, T2, T3, T4]
VEC cost2(const VEC &x0){
    VEC result(x0.dim());
    double V1 = x0[0];
    double V2 = x0[1];
    double T1 = x0[2];
    double T2 = x0[3];
    double T3 = x0[4];
    double T4 = x0[5];


    double phi1 = phi0 * T1 / 300;
    double phi2 = phi0 * T2 / 300;
    double phi3 = phi0 * T3 / 300;
    double phi4 = phi0 * T4 / 300;

    double I1 = Is * (exp((V-V1)/phi1) - 1);
    double I2 = Is * (exp(-1*V1/phi2) - 1);
    double I3 = Is * (exp((V2-V)/phi3) - 1);
    double I4 = Is * (exp(V2/phi4) - 1);
    double IRL = (V1 - V2) / RL;

    result[0] = I1 + I2 - IRL;
    result[1] = IRL - I3 - I4;
    result[2] = (300 + 2 * I1 * (V - V1)) - T1;
    result[3] = (300 + 2 * I2 * -1 * V1) - T2;
    result[4] = (300 + 2 * I3 * (V2 - V)) - T3;
    result[5] = (300 + 2 * I4 * V2) - T4;
    return result;
}


int main(int argc, char *argv[]){
    /*
       MAT result1(102, 8) ;   
       VEC x0(2);
       V = 0;
       int i = 101;
       while(V <= 1.00001){
       CyclicJacobian(cost1, x0, 1000000, 1e-12, 0.00001);
       double V1 = x0[0];
       double V2 = x0[1];
       double I1 = Is * (exp((V-V1)/phi0) - 1);
       double I2 = Is * (exp(-1*V1/phi0) - 1);
       double I3 = Is * (exp((V2-V)/phi0) - 1);
       double I4 = Is * (exp(V2/phi0) - 1);
       double IRL = (V1 - V2) / RL;
       double tmp[] = {V, V1, V2, I1, I2, I3, I4, IRL};
       result1[i] = tmp;
       V += 0.02;
       i--;
       }
       V = 0;
       x0 = 0;
       while(V >= -1.00001){
       CyclicJacobian(cost1, x0, 1000000, 1e-12, 0.00001);
       double V1 = x0[0];
       double V2 = x0[1];
       double I1 = Is * (exp((V-V1)/phi0) - 1);
       double I2 = Is * (exp(-1*V1/phi0) - 1);
       double I3 = Is * (exp((V2-V)/phi0) - 1);
       double I4 = Is * (exp(V2/phi0) - 1);
       double IRL = (V1 - V2) / RL;
       double tmp[] = {V, V1, V2, I1, I2, I3, I4, IRL};
       result1[i] = tmp;
       V -= 0.02;
       i--;
       }
    //result1.print();
    Json M1("raw_record/M1.json", 0);
    M1.Write(result1);
    M1.Close();
    */
    MAT result2(202, 12);
    VEC x0(6);
    x0 = 300;
    x0[0] = 0;
    x0[1] = 0;

    V = 0;
    int i = 201;
    while(V <= 1.001){
        CyclicJacobian(cost2, x0, 1000000, 1e-12, 0.00001);
        double V1 = x0[0];
        double V2 = x0[1];
        double T1 = x0[2];
        double T2 = x0[3];
        double T3 = x0[4];
        double T4 = x0[5];


        double phi1 = phi0 * T1 / 300;
        double phi2 = phi0 * T2 / 300;
        double phi3 = phi0 * T3 / 300;
        double phi4 = phi0 * T4 / 300;

        double I1 = Is * (exp((V-V1)/phi1) - 1);
        double I2 = Is * (exp(-1*V1/phi2) - 1);
        double I3 = Is * (exp((V2-V)/phi3) - 1);
        double I4 = Is * (exp(V2/phi4) - 1);
        double IRL = (V1 - V2) / RL;

        double tmp[] = {V, V1, V2, I1, I2, I3, I4, IRL, T1, T2, T3, T4};
        result2[i] = tmp;

        V += 0.01;
        i--;
    }
    x0 = 300;
    x0[0] = 0;
    x0[1] = 0;
    V = 0;
    while(V >= -1.001){
        CyclicJacobian(cost2, x0, 1000000, 1e-12, 0.00001);
        double V1 = x0[0];
        double V2 = x0[1];
        double T1 = x0[2];
        double T2 = x0[3];
        double T3 = x0[4];
        double T4 = x0[5];


        double phi1 = phi0 * T1 / 300;
        double phi2 = phi0 * T2 / 300;
        double phi3 = phi0 * T3 / 300;
        double phi4 = phi0 * T4 / 300;

        double I1 = Is * (exp((V-V1)/phi1) - 1);
        double I2 = Is * (exp(-1*V1/phi2) - 1);
        double I3 = Is * (exp((V2-V)/phi3) - 1);
        double I4 = Is * (exp(V2/phi4) - 1);
        double IRL = (V1 - V2) / RL;

        double tmp[] = {V, V1, V2, I1, I2, I3, I4, IRL, T1, T2, T3, T4};
        result2[i] = tmp;

        V -= 0.01;
        i--;
    }
    result2.print();
    Json M2("raw_record/M2.json", 0);
    M2.Write(result2);
    M2.Close();

    return 0;
}
















