// HW08: Polynomial Interpolations
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
}

int main(int argc, char *argv[]){
    vector<double> x;
    vector<double> y;
    Parse(argv[1], x, y);

    VEC X((int)x.size());
    VEC Y((int)y.size());

    for(int i=0; i<X.dim(); i++){
        X[i] = x[i];
        Y[i] = y[i];
    }

    //X.print();
    //Y.print();
    //cout << Lagrange(550, X, Y) << endl;
    VEC test_x(301);
    VEC test_y(301);
    test_x[0] = 475;
    for(int i=1; i<301; i++)
        test_x[i] = test_x[i-1] + 1;
    
    test_x.print();
    for(int i=0; i<301; i++){
        test_y[i] = Lagrange(test_x[i], X, Y);
    }

    //test_y.print();
    
    Json xj("X.json", 0);
    Json yj("Y.json", 0);
    Json xo("XO.json", 0);
    Json yo("YO.json", 0);

    xj.Write(test_x);
    yj.Write(test_y);
    xj.Close();
    yj.Close();
    xo.Write(X);
    yo.Write(Y);
    xo.Close();
    yo.Close();
   
    return 0;
}
