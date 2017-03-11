// HW02: LU Decomposition
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

// Ax = b
double calculateError(const VEC &v1, const VEC &v2){
    double error = 0;
    for(int i=0; i < v1.dim(); i++){
        double tmp = v1[i] - v2[i];
        error += tmp * tmp;
    }
    return sqrt(error);
}

void Solve(const char v[], MAT &A, VEC &B, int n){
    double LU, fwd, bck;
    struct timeval a;
    struct timeval b;
    MAT ori(A);
    

    gettimeofday(&a, NULL);
    luFact(A);
    gettimeofday(&b, NULL);
    LU = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;

    gettimeofday(&a, NULL);
    VEC Y(fwdSubs(A, B));
    gettimeofday(&b, NULL);
    fwd = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;

    gettimeofday(&a, NULL);
    VEC X(bckSubs(A, Y));
    gettimeofday(&b, NULL);
    bck = (b.tv_sec - a.tv_sec) + (b.tv_usec - a.tv_usec) / 1000000.0;

    cout << "-----------" << endl;
    cout << v << endl;
    cout << "Error: " << calculateError(ori * X, B) << endl;
    printf("LU: %g second\n", LU);
    printf("FWD: %g second\n", fwd);
    printf("BCK: %g second\n", bck);
    cout << "-----------" << endl;
}

int main(int argc, char* argv[]){
    int dim;
    //double **val;
    //struct timeval a, b;
    //gettimeofday(&a, NULL);
    scanf("%d", &dim);
    MAT A(dim, dim);
    VEC b(dim);
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)  
            scanf("%lf", &A[i][j]);
    }
    for(int j=0; j<dim; j++)  
        scanf("%lf", &b[j]);
    Solve(argv[1], A, b, dim);
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
