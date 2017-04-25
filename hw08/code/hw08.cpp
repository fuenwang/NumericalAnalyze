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
    if(argc != 2){
        printf("Argument error!\n");
        printf("Usage: ./a.out f21.dat\n");
        exit(0);
    }
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
    
    for(int i=0; i<301; i++){
        test_y[i] = Lagrange(test_x[i], X, Y);
    }
    double error;
    vector<double> a;
    vector<double> b;
    Parse("../f301.dat", a, b);
    VEC XO(a.size());
    VEC YO(b.size());

    for(int i=0; i<XO.dim(); i++){
        XO[i] = a[i];
        YO[i] = b[i];
    }
    error = fabs(YO[0] - test_y[0]);
    for(int i=0; i<301; i++){
        double tmp = fabs(YO[i] - test_y[i]);
        if(tmp > error)
            error = tmp;
    }
    printf("Max error: %lf\n", error);
    //test_y.print();p
    /*
    vector<double> a;
    vector<double> b;
    Parse("../f301.dat", a, b);
    for(int i=0; i<XO.dim(); i++){
        XO[i] = a[i];
        YO[i] = b[i];
    }
    */
    /*
    Json xj("raw_record/X21.json", 1);
    Json yj("raw_record/Y21.json", 1);
    Json xo("raw_record/XS21.json", 0);
    Json yo("raw_record/YS21.json", 0);

    xj.Write(test_x);
    yj.Write(test_y);
    xj.Close();
    yj.Close();
    xo.Write(X);
    yo.Write(Y);
    xo.Close();
    yo.Close();
    */
    return 0;
}
