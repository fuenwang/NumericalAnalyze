#include "MAT.h"

void algo1(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();

    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = 0;
        for(int i=0; i<k; i++){
            //G[k] += 
        }
    }
    G.print();

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
    data.print();
    /*
    MAT data2(data + 1);
    data.print();
    data2.print();
    (data * data2).print();
    data.print();
    data2.print();
    */
    algo1(data, dim);
    



    for(int i=0; i<dim; i++){
        free(val[i]);
    }
    free(val);
    return 0;
}
