// HW05: Conjugate Gradient Methods
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

int p1,p2,p3;
VEC hw03(3);
VEC hw04(3);

double Solve(int node_one_side, double resistor);

// Ax = b
int main(int argc, char* argv[]){
    //if(argc != 2){
    //    printf("Please enter the resistor number one side\n");
    //}
    //int num_res = atoi(argv[1]);
    int num_res = 2;
    int node_num_one_side = num_res + 1;
    double res = 2000.0 / num_res;
    Solve(node_num_one_side, res);

    return 0;
}

double Solve(int node_one_side, double resistor){
    double conduct = 1 / resistor;

    MAT A(node_one_side*node_one_side, node_one_side*node_one_side);
    VEC B(node_one_side*node_one_side);

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
    B[Vin_point] = 1;

    A[Ground_point] = 0;
    A[Ground_point][Ground_point] = 1;
    
    MAT A_tmp(A);
    luFact(A_tmp);
    VEC ans(bckSubs(A_tmp, fwdSubs(A_tmp, B)));
    ans.print();
    return 0;
}









