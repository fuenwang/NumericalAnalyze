#ifndef MAT_H
#define MAT_H
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "VEC.h"

class MAT{
    private:
        int m; // m x n
        int n; // m x n
        VEC **val;
    protected:
        VEC *CreateVEC(int n);
        void checkDim(MAT &data);
    public:
        MAT(int n);
        MAT(int m, int n);
        MAT(double **val, int m, int n);
        MAT(const MAT &data);
        ~MAT();
        void Reset(double **val, int m, int n);
        void print();

        MAT T(); // transpose matrix

        void operator=(MAT &data);
        VEC& operator[](int index) const;

        void operator+=(MAT &data);
        void operator+=(double num);
        void operator-=(MAT &data);
        void operator-=(double num);
        void operator*=(MAT &data);
        void operator*=(double num);
        void operator/=(MAT &data);
        void operator/=(double num);

        MAT operator+(MAT &data);
        MAT operator+(double num);
        MAT operator-(MAT &data);
        MAT operator-(double num);
        MAT operator*(MAT &data);
        MAT operator*(double num);
        MAT operator/(MAT &data);
        MAT operator/(double num);

        friend MAT operator+(double num, MAT &data);
        friend MAT operator-(double num, MAT &data);
        friend MAT operator*(double num, MAT &data);
        friend MAT operator/(double num, MAT &data);
};

MAT operator+(double num, MAT &data);
MAT operator-(double num, MAT &data);
MAT operator*(double num, MAT &data);
MAT operator/(double num, MAT &data);
#endif
