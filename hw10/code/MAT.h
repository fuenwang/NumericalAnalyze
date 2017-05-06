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

#define HW06_E 1

using namespace std;
//extern int p1,p2,p3;
//extern VEC hw03;
//extern VEC hw04;

//extern int E_type;
const double W1[2] = {0.5, 0.5};
const double W2[3] = {1.0/3, 4.0/3, 1.0/3};
const double W3[4] = {3.0/8, 9.0/8, 9.0/8, 3.0/8};
const double W4[5] = {14.0/45, 64.0/45, 24.0/45, 64.0/45, 14.0/45};
const double W5[6] = {95.0/288, 375.0/288, 250.0/288, 250.0/288, 375.0/288, 95.0/288};
const double W6[7] = {41.0/140, 216.0/140, 27.0/140, 272.0/140, 27.0/140, 216.0/140, 41.0/140};

class Performance{ // To help me get cpu time of algorithm
    private:
        struct timeval start;
        struct timeval stop;
    public:
        void Start();
        double End();
        double End(const char right[], const char left[]);
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
        int GetM() const; // Get m
        int GetN() const; // Get n
        MAT T() const; // transpose matrix
        
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
        void Write(const MAT &m);
        void Write(const VEC &v);
        void Close();
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
int sd(MAT &A, VEC b, VEC &x, int maxIter, double tol);
int cg(MAT &A, VEC b, VEC &x, int maxIter, double tol);

double error_1_norm(VEC &x1, VEC &x2);
double error_2_norm(VEC &x1, VEC &x2);
double error_infinite_norm(VEC &x1, VEC &x2);
double error_1_norm(const VEC &E_mat);
double error_2_norm(const VEC &E_mat);
double error_infinite_norm(const VEC &E_mat);

double error_cg(VEC &r);

int EVpwr(MAT &A, VEC &q0, double &lambda, double tol, int maxiter);
int EViPwr(MAT &A, VEC &q0, double &lambda, double tol, int maxiter);
int EViPwrShft(MAT &A, VEC &q0, double &lambda, double mu, double tol, int maxiter);

void QRFact(const MAT &A, MAT &Q, MAT &R);
int EVqr(MAT &A, double tol, int maxiter);
int EVqrShifted(MAT &A, double mu, double tol, int maxiter);

void splineM(int N, VEC &X, VEC &Y, VEC &M);
double spline(double x, int N, VEC &X, VEC &Y, VEC &M);

double Integrate(double (*func)(double), int order, VEC &Y, double step);
#endif
