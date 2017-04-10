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
    //if(argc != 2){
    //    printf("Please enter the resistor number one side\n");
    //}
    //int num_res = atoi(argv[1]);
    int num_res = 20;
    int node_num_one_side = num_res + 1;
    double res = 2000.0 / num_res;
    Solve(node_num_one_side, res);

    return 0;
}

double Solve(int node_one_side, double resistor){
    //double conduct = 1 / resistor;
    double conduct = 1;
    MAT A(14, 14);
    VEC B(14);

    A = 0;
    A[0][0] = 3;
    A[0][1] = -1;
    A[0][4] = -1;
    A[1][1] = 3;
    A[1][2] = -1;
    A[1][5] = -1;
    A[2][1] = -1;
    A[2][2] = 2;
    A[2][6] = -1;
    A[3][3] = 3;
    A[3][4] = -1;
    A[3][7] = -1;
    A[4][3] = -1;
    A[4][4] = 4;
    A[4][5] = -1;
    A[4][8] = -1;
    A[5][1] = -1;
    A[5][4] = -1;
    A[5][5] = 4;
    A[5][6] = -1;
    A[5][9] = -1;

    A[6][2] = -1;
    A[6][5] = -1;
    A[6][6] = 3;
    A[6][10] = -1;
    
    A[7][3] = -1;
    A[7][7] = 3;
    A[7][8] = -1;
    A[7][11] = -1;

    A[8][4] = -1;
    A[8][7] = -1;
    A[8][8] = 4;
    A[8][9] = -1;
    A[8][12] = -1;

    A[9][5] = -1;
    A[9][8] = -1;
    A[9][9] = 4;
    A[9][10] = -1;
    A[9][13] = -1;

    A[10][6] = -1;
    A[10][9] = -1;
    A[10][10] = 3;
    
    A[11][7] = -1;
    A[11][11] = 2;
    A[11][12] = -1;

    A[12][8] = -1;
    A[12][11] = -1;
    A[12][12] = 3;
    A[12][13] = -1;

    A[13][9] = -1;
    A[13][12] = -1;
    A[13][13] = 3;
    
    VEC q(14);
    double l=0;
    q = sqrt(1.0 / q.dim());
    EVpwr(A, q, l, 1e-9, 10000);
    cout << l << endl;
    exit(0);
    /*
    A.print();
    Json J("A5.json", 0);
    Json Q("B5.json", 0);
    J.Write(A);
    J.Close();
    Q.Write(B);
    Q.Close();
    //B.print();
    exit(0);
    */
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
    double lambda = 0;
    VEC q0(B.dim());
    //q0 = sqrt(1.0 / q0.dim());
    q0 = 1;
    Performance P;
    P.Start();

    cout << EVpwr(A, q0, lambda, 1e-9, 4000) << endl;
    //cout << EViPwr(A, q0, lambda, 1e-9, 10000000) << endl;
    //cout << EViPwrShft(A, q0, lambda, 5e-5, 1e-9, 10000000) << endl;
    cout << lambda << endl;
    P.End("Runtime: ", " s");
    return 0;
}









