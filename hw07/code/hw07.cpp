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
    MAT Q(dim), R(dim);
    QRFact(A, Q, R);
    //Q.print();
    //R.print();
    //A.print();
    //(Q*R).print();
    VEC eig(dim);
    cout << EVqrShifted(A, 0.5, 1e-9, 10000) << endl;;
    for(int i=0; i< dim; i++)
        eig[i] = A[i][i];
    eig.sort();
    eig.print();
    //A.print();
    printf("Dim: %d\n", dim);
    return 0;
}
