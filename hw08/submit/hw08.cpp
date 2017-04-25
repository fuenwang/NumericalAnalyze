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
    for(int i=0; i<X.dim(); i++){
        X[i] = x[i];
        Y[i] = y[i];
    }
    VEC test_x(301);
    VEC test_y(301);
    test_x[0] = 475;
    for(int i=1; i<301; i++)
        test_x[i] = test_x[i-1] + 1;
    
    for(int i=0; i<301; i++){
        test_y[i] = Lagrange(test_x[i], X, Y);
    }
    test_y.print();
    return 0;
}
