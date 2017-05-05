// Vector Header
// ID: 102061149
// Name: Fu-En Wang

#ifndef VEC_H
#define VEC_H
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class VEC{
    private:
        int dimension;
        double *val;
    protected:
        void checkDim(const VEC &data);
    public:
        VEC(int n);
        VEC(const VEC &data);
        ~VEC();
        void print();
        void sort();
        int dim() const;
        double sum();
        bool operator==(VEC &data);
        void operator=(const VEC &data);
        void operator=(double num);
        double& operator[](int index) const;

        VEC operator+(const VEC &data);
        VEC operator+(double num);
        VEC operator-(const VEC &data);
        VEC operator-(double num);
        double operator*(const VEC &data);
        VEC operator*(double num);
        VEC operator/(const VEC &data);
        VEC operator/(double num);

        void operator+=(const VEC &data);
        void operator-=(const VEC &data);
        void operator*=(const VEC &data);
        void operator/=(const VEC &data);
        void operator/=(double num);
        friend VEC operator+(double num, const VEC &vec);
        friend VEC operator-(double num, const VEC &vec);
        friend VEC operator*(double num, const VEC &vec);
        friend VEC operator/(double num, const VEC &vec);

};

VEC operator+(double num, const VEC &vec);
VEC operator-(double num, const VEC &vec);
VEC operator*(double num, const VEC &vec);
VEC operator/(double num, const VEC &vec);

double Lagrange(double x, VEC &XDATA, VEC &YDATA);
#endif
