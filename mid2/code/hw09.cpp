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
    string f_name = "q62.dat";
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
    //X.print();
    //Y.print();
    printf("%g\n", Integrate(6, X, Y));
    return 0;
}
