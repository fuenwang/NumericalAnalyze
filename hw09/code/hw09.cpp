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
    splineM(X.dim(), X, Y, M);
    VEC test_x(301);
    VEC test_y(301);
    test_x[0] = 475;
    for(int i=1; i<301; i++)
        test_x[i] = test_x[i-1] + 1;
    
    for(int i=0; i<301; i++){
        test_y[i] = spline(test_x[i], X.dim(), X, Y, M);
    }
    //test_y.print();
    

    Json xj("raw_record/X21.json", 0);
    Json yj("raw_record/Y21.json", 0);
    Json xs("raw_record/XS21.json", 0);
    Json ys("raw_record/YS21.json", 0);
    xj.Write(test_x);
    yj.Write(test_y);
    xs.Write(X);
    ys.Write(Y);
    xj.Close();
    yj.Close();
    xs.Close();
    ys.Close();

    vector<double> xo, yo;
    Parse("../f301.dat", xo, yo);
    VEC XO(xo.size());
    VEC YO(yo.size());
    for(int i=0; i<XO.dim(); i++){
        XO[i] = xo[i];
        YO[i] = yo[i];
    }

    double error = fabs(test_y[0] - YO[0]);
    for(int i=0; i<YO.dim(); i++){
        double tmp = fabs(test_y[i] - YO[i]);
        if(tmp > error)
            error = tmp;
    }
    printf("Max error: %g\n", error);
    return 0;
}
