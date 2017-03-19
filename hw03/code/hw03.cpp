// HW03: Resistor Networks
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

double Solve(int node_one_side, double resistor);

// Ax = b
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Please enter the resistor number one side\n");
    }
    int node_num_one_side = atoi(argv[1]) + 1;
    double res;
    res = Solve(node_num_one_side, 40);
    return 0;
}

double Solve(int node_one_side, double resistor){
    double conduct = 1 / resistor;
    MAT A(node_one_side*node_one_side, node_one_side*node_one_side);
    VEC b(node_one_side*node_one_side);

    A = 0;
    // Process by row first
    for(int i=0, node=0; i<node_one_side; i++){
        for(int j=0; j<node_one_side-1; j++){
            A[node][node] += conduct;
            A[node][node+1] -= conduct;
            A[node+1][node+1] += conduct;
            A[node+1][node] -= conduct;
            node++;
        }
        node++;
    }
    // Process column
    for(int i=0, node=0; i<node_one_side-1; i++){
        for(int j=0; j<node_one_side; j++){
            A[node][node] += conduct;
            A[node][node + node_one_side] -= conduct;
            A[node + node_one_side][node + node_one_side] += conduct;
            A[node + node_one_side][node] -= conduct;
            node++;
        }
    }
    int Vin_point = (node_one_side-1)/2;
    int Ground_point = (node_one_side*node_one_side-1) - (node_one_side-1) / 2;
    A[Vin_point] = 0;
    A[Vin_point][Vin_point] = 1;
    b[Vin_point] = 1;

    A[Ground_point] = 0;
    A[Ground_point][Ground_point] = 1;
    //A.print();
    luFact(A);
    VEC Y(fwdSubs(A, b));
    VEC X(bckSubs(A, Y));
    //X.print();
    double V = X[Vin_point];
    double V_ne = X[node_one_side-1];
    double V_ea = X[(node_one_side*node_one_side-1)/2];
    double V_sw = X[node_one_side*node_one_side - node_one_side];
    double I = 0;
    double res;
    I += (V - X[Vin_point-1]) * conduct;
    I += (V - X[Vin_point+1]) * conduct;
    I += (V - X[Vin_point+node_one_side]) * conduct;
    
    res = V / I; 
    printf("Dimension: %d\n", node_one_side);
    printf("Total resistance: %lf\n", res);
    printf("V_ne: %lf\n", V_ne);
    printf("V_ea: %lf\n", V_ea);
    printf("V_sw: %lf\n", V_sw);
    return res;
}









