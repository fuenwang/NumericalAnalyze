#include <fstream>
#include <string>
#include "VEC.h"
#include "MAT.h"

using namespace std;

int main(int argc, char *argv[]){
    int count = atoi(argv[1]);
    //MAT *data = (MAT*)malloc(count * sizeof(MAT));
    //for(int i=0; i<count; i++){
        int dim;
        double **val;
        scanf("%d", &dim);
        val = (double**)malloc(dim * sizeof(double*));
        for(int j=0; j<dim; j++)
            val[j] = (double*)malloc(dim * sizeof(double));
        for(int j=0; j<dim; j++){
            for(int k=0; k<dim; k++){
                scanf("%lf", &val[j][k]);
                //printf("%lf ", val[j][k]);
            }
        }
        MAT data(val, dim, dim);
        data.print();
    //}
/*
    VEC a(3);
    VEC b(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
    //a.print();
    //a *= b;
    //b.print();
    (a / 5).print();
    a.print();
    //b.print();
*/
}
