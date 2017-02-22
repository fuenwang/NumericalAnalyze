#include "VEC.h"

using namespace std;

int main(){
    vec a(3);
    vec b(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
    a.print();
    a /= b;
    //b.print();
    //(a / b).print();
    a.print();
    b.print();
}
