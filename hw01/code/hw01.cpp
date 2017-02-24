#include "MAT.h"
#include <math.h>
using namespace std;

double calculateSigma(const MAT &M, int n){
    double sum = 0;
    M.print();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                double val = M[i][j];
                cout << val << endl;
                sum += val * val;;
            }
        }
    }
    sum = sqrt(sum);
    printf("Sigma: %lf\n", sum);
    return sum;
}

void algo1(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();
    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = 0;
        for(int i=0; i<k; i++){
            G[k] += (A[k] * G[i]).sum() * G[i] / (G[i] * G[i]).sum();
        }
        G[k] = A_t[k] - G[k];
    }
    G = G.T();

    //(G.T() * G).print();

    calculateSigma(G.T() * G, n);
    return;
}

void algo2(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();
    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = A_t[k];
        for(int i=0; i<k; i++){
            G[k] -= (G[k] * G[i]).sum() * G[i] / (G[i] * G[i]).sum();
        }
    }
    G = G.T();

    (G.T() * G).print();

    calculateSigma(G.T() * G, n);
    return;
}

void algo3(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();
    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = A_t[k];
        for(int i=0; i<k; i++){
            G[k] -= (G[k] * G[i]).sum() / (G[i] * G[i]).sum() * G[i];
        }
    }
    G = G.T();

    calculateSigma(G.T() * G, n);
    //(G.T() * G).print();

    return;
}


int main(){
    int dim;
    double **val;

    scanf("%d", &dim);
    val = (double**)malloc(dim*sizeof(double*));
    for(int i=0; i<dim; i++){
        val[i] = (double*)malloc(dim*sizeof(double));
        for(int j=0; j<dim; j++)  
            scanf("%lf", &val[i][j]);
    }
    MAT data(val, dim, dim);
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
    algo2(data, dim);

    



    for(int i=0; i<dim; i++){
        free(val[i]);
    }
    free(val);
    return 0;
}
