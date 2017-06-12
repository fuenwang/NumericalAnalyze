// HW12: RLC Circult
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <vector>
#include <fstream>
#include <string>


int main(int argc, char *argv[]){
    double buf_x[] = {0, 0.1, 0.2, 0.3, 1, 1.1, 1.2, 1.3, 1.5};
    double buf_y[] = {0.015, -0.05141, 2.281, 3.1983, 3.3, 3.3799, 1.0181, 0.02002, 0.015};
    VEC X(9);
    VEC Y(9);
    VEC M(9);
    X = buf_x;
    Y = buf_y;
    splineM_period(X.dim(), X, Y, M);
    cout << spline(0.15, X.dim(), X, Y, M) << endl;
    cout << spline(0.25, X.dim(), X, Y, M) << endl;
    cout << spline(0.75, X.dim(), X, Y, M) << endl;
    cout << spline(1.15, X.dim(), X, Y, M) << endl;
    cout << spline(1.25, X.dim(), X, Y, M) << endl;

    //Y.print();
    //
    /*
       cout << Lagrange(0.15, X, Y) << endl;
       cout << Lagrange(0.25, X, Y) << endl;
       cout << Lagrange(0.75, X, Y) << endl;
       cout << Lagrange(1.15, X, Y) << endl;
       cout << Lagrange(1.25, X, Y) << endl;
       */
    return 0;
}
















