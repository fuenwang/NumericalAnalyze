// HW09: Spline Interpolations
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>

void Parse(const char f_name[], vector<double> &x, vector<double> &y){
    ifstream f;
    f.open(f_name);
    string buf;
    
    getline(f, buf);
    while(getline(f, buf)){
        double a,b;
        sscanf(buf.c_str(), "%lf %lf", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }
    f.close();
}

int main(int argc, char *argv[]){
    string f_name;
    switch(argc){
        case 1:
            f_name = "f21.dat";
            break;
        case 2:
            f_name = argv[1];
            break;
        default:
            printf("Argument error!\n");
            printf("Usage: ./a.out f21.dat\n");
            exit(0);
    }
    vector<double> x;
    vector<double> y;
    Parse(f_name.c_str(), x, y);
    VEC X((int)x.size());
    VEC Y((int)y.size());
    VEC M((int)y.size());
    for(int i=0; i<X.dim(); i++){
        X[i] = x[i];
        Y[i] = y[i];
    }
    splineM_period(X.dim(), X, Y, M);
    //splineM(X.dim(), X, Y, M);
    cout << spline(1, X.dim(), X, Y, M) << endl;
    cout << spline(2, X.dim(), X, Y, M) << endl;
    cout << spline(4, X.dim(), X, Y, M) << endl;
    cout << spline(5, X.dim(), X, Y, M) << endl;
    //M.print();

    return 0;
}
