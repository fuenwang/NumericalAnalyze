// HW07: Matrix Eigenvalues
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"

int main(){
    int dim;
    scanf("%d", &dim);
    MAT A(dim);
    
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    int it;
    VEC eig(dim);
    VEC largest(3);
    VEC smallest(3);
    it = EVqrShifted(A, 0.5, 1e-9, 10000);
    //it = EVqr(A, 1e-9, 10000);
    for(int i=0; i< dim; i++)
        eig[i] = A[i][i];
    eig.sort();

    smallest[0]  = eig[0];
    smallest[1]  = eig[1];
    smallest[2]  = eig[2];
    largest[0] = eig[dim-3];
    largest[1] = eig[dim-2];
    largest[2] = eig[dim-1];

    printf("N: %d\n", dim);
    printf("# of iteration: %d\n", it);
    printf("Largest eigenvalue: ");
    largest.print();
    printf("Smallest eigenvalue: ");
    smallest.print();

    return 0;
}
