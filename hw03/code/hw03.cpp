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
    int num_res = atoi(argv[1]);
    int node_num_one_side = num_res + 1;
    double res;
    if(num_res == 2)
        res = Solve(node_num_one_side, 1000);
    else if(num_res == 4)
        res = Solve(node_num_one_side, 500);
    else if(num_res == 10)
        res = Solve(node_num_one_side, 200);
    else if(num_res == 20)
        res = Solve(node_num_one_side, 100);
    else if(num_res == 40)
        res = Solve(node_num_one_side, 50);
    else if(num_res == 50)
        res = Solve(node_num_one_side, 40);
    else
        printf("Argument error!\n");
    return 0;
}

double Solve(int node_one_side, double resistor){
    struct timeval start, stop, a,b;
    double conduct = 1 / resistor;
    double MODEL, LU, FWD, BCK;
    gettimeofday(&start, NULL);

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
    gettimeofday(&stop, NULL);
    MODEL = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;

    //A.print();
    gettimeofday(&a, NULL);
    luFact(A);
    gettimeofday(&b, NULL);
    LU = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;
    
    gettimeofday(&a, NULL);
    VEC Y(fwdSubs(A, B));
    gettimeofday(&b, NULL);
    FWD = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;

    gettimeofday(&a, NULL);
    VEC X(bckSubs(A, Y));
    gettimeofday(&b, NULL);
    BCK = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;

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
    cout << "-----------------" << endl;
    printf("Dimension: %d\n", node_one_side*node_one_side);
    printf("Each resistance: %lf\n", resistor);
    printf("Total resistance: %lf\n", res);
    printf("V_ne: %lf\n", V_ne);
    printf("V_ea: %lf\n", V_ea);
    printf("V_sw: %lf\n", V_sw);
    printf("MODEL(s): %g\n", MODEL);
    printf("LU(s): %g\n", LU);
    printf("FWD(s): %g\n", FWD);
    printf("BCK(s): %g\n", BCK);
    cout << "-----------------" << endl << endl;
    return res;
}









