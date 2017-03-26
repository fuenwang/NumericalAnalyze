// HW03: Resistor Networks
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

using namespace std;


double Solve(int node_one_side, double resistor);

// Ax = b
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Please enter the resistor number one side\n");
    }
    int num_res = atoi(argv[1]);
    int node_num_one_side = num_res + 1;
    if(num_res == 2)
        Solve(node_num_one_side, 1000);
    else if(num_res == 4)
        Solve(node_num_one_side, 500);
    else if(num_res == 10)
        Solve(node_num_one_side, 200);
    else if(num_res == 20)
        Solve(node_num_one_side, 100);
    else if(num_res == 40)
        Solve(node_num_one_side, 50);
    else if(num_res == 50)
        Solve(node_num_one_side, 40);
    else
        printf("Argument error!\n");
    return 0;
}

double Solve(int node_one_side, double resistor){
    double conduct = 1 / resistor;

    MAT A(node_one_side*node_one_side, node_one_side*node_one_side);
    VEC B(node_one_side*node_one_side);

    A = 0;
    // Process by row first
    for(int i=0, node=0; i<node_one_side; i++){
        for(int j=0; j<node_one_side-1; j++){
            A[node][node] += conduct;
            A[node][node+1] -= conduct;
            A[node+1][node+1] += conduct;
            A[node+1][node] -= conduct;
            node++;
        }
        node++;
    }
    // Process column
    for(int i=0, node=0; i<node_one_side-1; i++){
        for(int j=0; j<node_one_side; j++){
            A[node][node] += conduct;
            A[node][node + node_one_side] -= conduct;
            A[node + node_one_side][node + node_one_side] += conduct;
            A[node + node_one_side][node] -= conduct;
            node++;
        }
    }
    int Vin_point = (node_one_side-1)/2;
    int Ground_point = (node_one_side*node_one_side-1) - (node_one_side-1) / 2;
    A[Vin_point] = 0;
    A[Vin_point][Vin_point] = 1;
    B[Vin_point] = 1;

    A[Ground_point] = 0;
    A[Ground_point][Ground_point] = 1;

    //A.print();


    MAT A_jo(A);
    VEC B_jo(B);
    VEC X_jo(B.dim());

    VEC hw04(3);
    VEC hw03(3);

    double error_jo;

    X_jo = 0;

    luFact(A);
    VEC Y(fwdSubs(A, B));
    VEC X(bckSubs(A, Y));
    hw03[0] = X[node_one_side-1]; // V_ne
    hw03[1] = X[(node_one_side*node_one_side-1)/2]; // V_ea
    hw03[2] = X[node_one_side*node_one_side - node_one_side]; // V_sw

    int METHOD = 3;
    int E_type = 3;
    //cout << sgs(A_sgs, B_sgs, X_sgs, 100000000, 2.83 * 1e-10, E_type) << endl;
    switch(METHOD){
        case 1:
            if(E_type == 1)
                cout << jacobi(A_jo, B_jo, X_jo, 100000000, 1.95 * 1e-8, E_type) << endl; // For error_1
            else if(E_type == 2)
                cout << jacobi(A_jo, B_jo, X_jo, 100000000, 2.3 * 1e-9, E_type) << endl; // For error_2
            else if(E_type == 3)
                cout << jacobi(A_jo, B_jo, X_jo, 100000000, 3 * 1e-10, E_type) << endl; // For error_3
            break;
        case 2:
            if(E_type == 1)
                cout << gaussSeidel(A_jo, B_jo, X_jo, 100000000, 3.93 * 1e-8, E_type) << endl;
            else if(E_type == 2)
                cout << gaussSeidel(A_jo, B_jo, X_jo, 100000000, 3.27 * 1e-9, E_type) << endl;
            else if(E_type ==3)
                cout << gaussSeidel(A_jo, B_jo, X_jo, 100000000, 3.05 * 1e-10, E_type) << endl;
            break;
        case 3:
            if(E_type == 1)
                cout << sgs(A_jo, B_jo, X_jo, 100000000, 7.7 * 1e-8, E_type) << endl;
            else if(E_type == 2)
                cout << sgs(A_jo, B_jo, X_jo, 100000000, 6.5 * 1e-9, E_type) << endl;
            else if(E_type == 3)
                cout << sgs(A_jo, B_jo, X_jo, 100000000, 5.95 * 1e-10, E_type) << endl;
    }
    hw04[0] = X_jo[node_one_side-1]; // V_ne
    hw04[1] = X_jo[(node_one_side*node_one_side-1)/2]; // V_ea
    hw04[2] = X_jo[node_one_side*node_one_side - node_one_side]; // V_sw
    //X.print();
    //X_jo.print();
    hw03.print();
    hw04.print();
    switch(E_type){
        case 1:
            error_jo = error_1_norm(hw03, hw04);
            break;
        case 2:
            error_jo = error_2_norm(hw03, hw04);
            break;
        case 3:
            error_jo = error_infinite_norm(hw03, hw04);
    }
    cout << error_jo << endl;

    return 0;
}









