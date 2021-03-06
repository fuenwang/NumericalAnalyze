#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

double calculateSigma(const MAT &M, int n){
    //M.print();
    double sum = 0;
    //M.print();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                double val = M[i][j];
                //cout << val << endl;
                sum += val * val;;
            }
        }
    }
    sum = sqrt(sum);
    //printf("Sigma: %g\n", sum);
    return sum;
}

void algo1(MAT &A, int n){
    //struct timeval a,b;
    //gettimeofday(&a, NULL);
    MAT A_t(A.T());
    //gettimeofday(&b, NULL);
    //printf("AAA %d\n", b.tv_sec - a.tv_sec);

    MAT G(n, n);
    //A_t.print();
    //
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = 0;
        for(int i=0; i<k; i++){
            G[k] += (A_t[k] * G[i]).sum() * G[i] / (G[i] * G[i]).sum();
        }
        G[k] = A_t[k] - G[k];
    }
    gettimeofday(&stop, NULL);
    G = G.T();
    //G.print();
    //(G.T() * G).print();

    //gettimeofday(&a, NULL);
    //G.T() * G;
    //gettimeofday(&b, NULL);
    //printf("BBB %d\n", b.tv_sec - a.tv_sec);

    double sigma = calculateSigma(G.T() * G, n);

    printf("-------------\n");
    printf("algo1:\n");
    printf("n: %d\n", n);
    printf("Sigma: %g\n", sigma);
    printf("Time: %g\n", ((stop.tv_usec - start.tv_usec)/ 1000000.0) + stop.tv_sec - start.tv_sec);
    //printf("Time: %d\n", stop.tv_sec - start.tv_sec);
    printf("-------------\n");
    return;
}

void algo2(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = A_t[k];
        for(int i=0; i<k; i++){
            G[k] -= (G[k] * G[i]).sum() * G[i] / (G[i] * G[i]).sum();
        }
    }
    gettimeofday(&stop, NULL);
    G = G.T();

    double sigma = calculateSigma(G.T() * G, n);
    printf("-------------\n");
    printf("algo2:\n");
    printf("n: %d\n", n);

    printf("Sigma: %g\n", sigma);
    printf("Time: %g\n", ((stop.tv_usec - start.tv_usec)/ 1000000.0) + stop.tv_sec - start.tv_sec);
    printf("-------------\n");

    return;
}

void algo3(MAT &A, int n){
    MAT A_t(A.T());
    MAT G(n, n);
    //A_t.print();
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    G[0] = A_t[0];
    for(int k=1; k<n; k++){
        G[k] = A_t[k];
        for(int i=0; i<k; i++){
            G[k] -= (G[k] * G[i]).sum() / (G[i] * G[i]).sum() * G[i];
        }
    }
    gettimeofday(&stop, NULL);
    G = G.T();

    double sigma = calculateSigma(G.T() * G, n);
    printf("-------------\n");
    printf("algo3:\n");
    printf("n: %d\n", n);

    printf("Sigma: %g\n", sigma);
    printf("Time: %g\n", ((stop.tv_usec - start.tv_usec)/ 1000000.0) + stop.tv_sec - start.tv_sec);
    printf("-------------\n");

    return;
}


int main(int argc, char* argv[]){
    int dim;
    //double **val;
    //struct timeval a, b;
    //gettimeofday(&a, NULL);
    scanf("%d", &dim);
    MAT data(dim, dim);
    //val = (double**)malloc(dim*sizeof(double*));
    for(int i=0; i<dim; i++){
        //val[i] = (double*)malloc(dim*sizeof(double));
        for(int j=0; j<dim; j++)  
            scanf("%lf", &data[i][j]);
    }

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
    algo1(data, dim);
    algo2(data, dim);
    algo3(data, dim);
    


    return 0;
}
