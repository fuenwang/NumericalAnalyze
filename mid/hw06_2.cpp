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
    for(int i=0; i<2; i++){
        A[i][i] += conduct;
        A[i][i+1] -= conduct;
        A[i+1][i+1] += conduct;
        A[i+1][i] -= conduct;
        //B[i] += 1;
    }
    for(int i=3; i<6; i++){
        if(i!=4){
            A[i][i] += conduct;
            A[i][i+1] -= conduct;
            A[i+1][i+1] += conduct;
            A[i+1][i] -= conduct;
        }
        else{
            A[i][i] += 0;
            A[i][i+1] -= 0;
            A[i+1][i+1] += 0;
            A[i+1][i] -= 0;
        }
        //B[i] += 1;
    }
    for(int i=7; i<10; i++){
        if(i!=8){
            A[i][i] += conduct;
            A[i][i+1] -= conduct;
            A[i+1][i+1] += conduct;
            A[i+1][i] -= conduct;
        }
        else{
            A[i][i] += 0;
            A[i][i+1] -= 0;
            A[i+1][i+1] += 0;
            A[i+1][i] -= 0;
        }
        //B[i] += 1;
    }
    for(int i=11; i<13; i++){
        A[i][i] += conduct;
        A[i][i+1] -= conduct;
        A[i+1][i+1] += conduct;
        A[i+1][i] -= conduct;
        //B[i] += 1;
    }

    A[0][0] += conduct;
    A[0][3] -= conduct;
    A[3][3] += conduct;
    A[3][0] -= conduct;
    //B[0] += 1;

    A[1][1] += conduct;
    A[1][4] -= conduct;
    A[4][4] += conduct;
    A[4][1] -= conduct;
    //B[1] += 1;

    A[2][2] += conduct;
    A[2][5] -= conduct;
    A[5][5] += conduct;
    A[5][2] -= conduct;
    //B[2] += 1;

    A[3][3] += conduct;
    A[3][7] -= conduct;
    A[7][7] += conduct;
    A[7][3] -= conduct;
    //B[3] += 1;

    A[4][4] += 0;
    A[4][8] -= 0;
    A[8][8] += 0;
    A[8][4] -= 0;
    //B[4] +=1 ;

    A[5][5] += 0;
    A[5][9] -= 0;
    A[9][9] += 0;
    A[9][5] -= 0;
    //B[5] += 1;

    A[6][6] += conduct;
    A[6][10] -= conduct;
    A[10][10] += conduct;
    A[10][6] -= conduct;
    //B[6] += 1;

    A[8][8] += conduct;
    A[8][11] -= conduct;
    A[11][11] += conduct;
    A[11][8] -= conduct;
    //B[8] += 1;

    A[9][9] += conduct;
    A[9][12] -= conduct;
    A[12][12] += conduct;
    A[12][9] -= conduct;
    //B[9] += 1;

    A[10][10] += conduct;
    A[10][13] -= conduct;
    A[13][13] += conduct;
    A[13][10] -= conduct;
    //B[10] += 1;

    A[0] = 0;
    A[0][0] = 1;
    A[13] = 0;
    A[13][13] = 1;
    B[0] = 1;
    A.print();
    luFact(A);
    VEC Y(fwdSubs(A, B));
    VEC X(bckSubs(A,Y));
    X.print();
    cout << 1.0 / ((1 - X[1]) + (1 - X[3])) << endl; 
    exit(0);
    //exit(0);
    /*
    Json J("A4.json", 0);
    Json Q("B4.json", 0);
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









