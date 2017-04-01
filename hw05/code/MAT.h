// Matrix Header
// ID: 102061149
// Name: Fu-En Wang

#ifndef MAT_H
#define MAT_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include "VEC.h"

using namespace std;
//extern int p1,p2,p3;
//extern VEC hw03;
//extern VEC hw04;

//extern int E_type;

class Performance{ // To help me get cpu time of algorithm
    private:
        struct timeval start;
        struct timeval stop;
    public:
        void Start();
        double End();
        double End(const char right[], const char left[]);
};

class Json{ // To help me dump experiment data
    private:
        int first;
        int ignore;
        ofstream f;
    public:
        Json(const char f_name[], int flag = 1);
        void Write(int data);
        void Write(float data, int mode = 0);
        void Write(double data, int mode = 0);
        void Write(const char data[]);
        void Close();
};

class MAT{
    private:
        int m; // m x n
        int n; // m x n
        VEC **val;
    protected:
        VEC *CreateVEC(int n); // Create a empty vector
        void checkDim(const MAT &data); // Chek the dimension match or not.
    public:
        MAT(int n); // Square matrix
        MAT(int m, int n); // Rectangular matrix
        MAT(double **val, int m, int n); // Rectangular Matrix with initial value
        MAT(const MAT &data); // Copy matrix
        ~MAT();
        void Reset(double **val, int m, int n);
        void print() const; // Show matrix value
        int GetM(); // Get m
        int GetN(); // Get n
        MAT T(); // transpose matrix
        
        void operator=(double num); // Assign value
        void operator=(const MAT &data); // Assign matrix
        VEC& operator[](int index) const; // Index(A[0])

        void operator+=(const MAT &data);
        void operator+=(double num);
        void operator-=(const MAT &data);
        void operator-=(double num);
        void operator*=(const MAT &data);
        void operator*=(double num);
        void operator/=(const MAT &data);
        void operator/=(double num);

        MAT operator+(const MAT &data);
        MAT operator+(double num);
        MAT operator-(const MAT &data);
        MAT operator-(double num);
        MAT operator*(const MAT &data);
        VEC operator*(const VEC &data);
        MAT operator*(double num);
        MAT operator/(const MAT &data);
        MAT operator/(double num);

        friend MAT operator+(double num, const MAT &data);
        friend MAT operator-(double num, const MAT &data);
        friend MAT operator*(double num, const MAT &data);
        friend MAT operator/(double num, const MAT &data);

        //friend MAT &luFact(MAT &m1);
        //friend VEC fwdSubs(MAT &m1, VEC b);
        //friend VEC bckSubs(MAT &m1, VEC b);

};

MAT operator+(double num, const MAT &data);
MAT operator-(double num, const MAT &data);
MAT operator*(double num, const MAT &data);
MAT operator/(double num, const MAT &data);

MAT &luFact(MAT &m1); // LU Decomposition(IN-Place LU)
VEC fwdSubs(MAT &m1, VEC b); // Forward Substitution
VEC bckSubs(MAT &m1, VEC b); // Backward Substitution

int jacobi_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type = 1); // custom Error func
int gaussSeidel_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type = 1); // custom Error func
int sgs_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type = 1); // custom Error func

int jacobi(MAT &A, VEC b, VEC &x, int maxIter, double tol);
int gaussSeidel(MAT &A, VEC b, VEC &x, int maxIter, double tol);
int sgs(MAT &A, VEC b, VEC &x, int maxIter, double tol);
int cg(MAT &A, VEC b, VEC &x, int maxIter, double tol);


double error_1_norm(VEC &x1, VEC &x2);
double error_2_norm(VEC &x1, VEC &x2);
double error_infinite_norm(VEC &x1, VEC &x2);
double error_cg(VEC &r, int n);

#endif
