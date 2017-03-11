// HW02: LU Decomposition
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

// Ax = b
double calculateError(VEC &v1, VEC &v2);
void Solve(MAT &A, VEC &b, int n){
    MAT ori(A);
    //MAT L(n, n);
    //MAT U(n, n);
    MAT test(n, n);
    test[0][0] = A[0][0];
    test[0][1] = A[0][1];
    test[0][2] = A[0][2];
    test[1][0] = A[1][0] / test[0][0];
    test[2][0] = A[2][0] / test[0][0];
    test[1][1] = A[1][1] - test[1][0] * test[0][1];
    test[1][2] = A[1][2] - test[1][0] * test[0][2];
    test[2][1] = (A[2][1] - test[2][0] * test[0][1]) / test[1][1];
    test[2][2] = A[2][2] - test[2][0] * test[0][2] - test[1][2] * test[2][1];

    luFact(A);
    //A.print();
    //test.print();
    //exit(0);
    /*
    for(int i=0; i<n; i++){
        L[i][i] = 1;
        for(int j=0; j<i; j++){
            L[i][j] = A[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            U[i][j] = A[i][j];
        }
    }
    */
    //L.print();
    //U.print();
    //exit(0);
    //A.print();
    VEC Y(fwdSubs(A, b));
    //Y.print();
    //exit(0);
    VEC X(bckSubs(A, Y));
    //A.print();
    (ori * X).print();
    //A.print();
    //X.print();
    b.print();
}

int main(int argc, char* argv[]){
    int dim;
    //double **val;
    //struct timeval a, b;
    //gettimeofday(&a, NULL);
    scanf("%d", &dim);
    MAT A(dim, dim);
    VEC b(dim);
    //val = (double**)malloc(dim*sizeof(double*));
    for(int i=0; i<dim; i++){
        //val[i] = (double*)malloc(dim*sizeof(double));
        for(int j=0; j<dim; j++)  
            scanf("%lf", &A[i][j]);
    }

    //cout << "GG" << endl;
    //left_hand.print();
    //right_hand.print();
    for(int j=0; j<dim; j++)  
        scanf("%lf", &b[j]);
    //A.print();
    Solve(A, b, dim);
    //A.print();
    //VEC test(3);
    //test[0] = 1;
    //test[1] = 2;
    //test[2] = 3;
    //(A * test).print();
    //right_hand.print();
    //gettimeofday(&b, NULL);

    //printf("DDDDD %d\n", b.tv_sec - a.tv_sec);
    //cout << (data[0]*data[1]).sum() << endl;
    //data.print();
    //data[0] += data[1];
    //data.print();
    /*
    MAT data2(data + 1);
    data.print();
    data2.print();
    (data * data2).print();
    data.print();
    data2.print();
    */


    return 0;
}
