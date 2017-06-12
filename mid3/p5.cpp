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
    vector<double> x;
    vector<double> y;
    Parse("Q51.dat", x, y);
    VEC X1((int)x.size());
    VEC Y1((int)y.size());
    for(int i=0; i<X1.dim(); i++){
        X1[i] = x[i];
        Y1[i] = y[i];
    }
    x.clear();
    y.clear();
    Parse("Q52.dat", x, y);

    VEC X2((int)x.size());
    VEC Y2((int)y.size());
    for(int i=0; i<X2.dim(); i++){
        X2[i] = x[i];
        Y2[i] = y[i];
    }
    int order = 6;
    double tmp1 = Integrate(order, X1, Y1);
    double tmp2 = Integrate(order, X2, Y2);
    cout << tmp1 + tmp2 << endl;
    return 0;
}
