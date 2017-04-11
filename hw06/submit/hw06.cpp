// HW06: Matrix Condition Numbers
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
    if(argc != 2){
        printf("Please enter the resistor number one side\n");
        exit(0);
    }
    int num_res = atoi(argv[1]);
    //int num_res = 50;
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
    double alpha = 0.003;
    A[Vin_point] = 0;
    A[Vin_point][Vin_point] = alpha;
    B[Vin_point] = alpha;

    A[Ground_point] = 0;
    A[Ground_point][Ground_point] = alpha;
    
    //A.print();
    /*    
    Json t("raw_record/A.json", 0);
    t.Write(A);
    t.Close();
    Json j("raw_record/B.json", 0);
    j.Write(B);
    j.Close();
    exit(0);
    */
    double lambda = 1;
    double lambda_1 = 1;
    double lambda_n = 1;
    VEC q0(B.dim());
    //q0[0] = 1;
    Performance P;
    
    int it1, it2, it3;
    cout << "N is "  << A.GetN() << endl;

    lambda_1 = 1;
    q0 = sqrt(1.0 / q0.dim());
    P.Start();
    it1 = EVpwr(A, q0, lambda_1, 1e-9, 4000);
    printf("it1 = %d\n", it1);
    printf("lambda1 = %g\n", lambda_1);
    P.End("Runtime(1): "," s");
    cout << endl;
    lambda_n = 1;
    q0 = sqrt(1.0 / q0.dim());
    P.Start();
    it2 = EViPwr(A, q0, lambda_n, 1e-9, 4000);
    printf("it2 = %d\n", it2);
    printf("lambda2 = %g\n", lambda_n);

    P.End("Runtime(2): "," s");
    
    cout << endl;
    
    lambda = 1;
    q0 = sqrt(1.0 / q0.dim());
    P.Start();
    it3 = EViPwrShft(A, q0, lambda, 5e-5, 1e-9, 4000);
    printf("it3 = %d\n", it3);
    printf("lambda3 = %g\n", lambda);

    P.End("Runtime(3): "," s");
    
    printf("\nCondition number is %g\n", lambda_1 / lambda_n);
    return 0;
}









