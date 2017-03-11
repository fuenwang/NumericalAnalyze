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
        void checkDim(const MAT &data);
    public:
        MAT(int n);
        MAT(int m, int n);
        MAT(double **val, int m, int n);
        MAT(const MAT &data);
        ~MAT();
        void Reset(double **val, int m, int n);
        void print() const;

        MAT T(); // transpose matrix

        void operator=(const MAT &data);
        VEC& operator[](int index) const;

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

        friend MAT &luFact(MAT &m1);
        friend VEC fwdSubs(MAT &m1, VEC b);
        friend VEC bckSubs(MAT &m1, VEC b);

};

MAT operator+(double num, const MAT &data);
MAT operator-(double num, const MAT &data);
MAT operator*(double num, const MAT &data);
MAT operator/(double num, const MAT &data);

MAT &luFact(MAT &m1);
VEC fwdSubs(MAT &m1, VEC b);
VEC bckSubs(MAT &m1, VEC b);




#endif
