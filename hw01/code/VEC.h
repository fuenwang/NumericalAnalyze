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
        void checkDim(VEC &data);
    public:
        VEC(int n);
        VEC(VEC &data);
        ~VEC();
        void print();
        int dim();
        bool operator==(VEC &data);
        void operator=(VEC &data);
        double& operator[](int index) const;

        VEC operator+(VEC &data);
        VEC operator+(double num);
        VEC operator-(VEC &data);
        VEC operator-(double num);
        VEC operator*(VEC &data);
        VEC operator*(double num);
        VEC operator/(VEC &data);
        VEC operator/(double num);

        void operator+=(VEC &data);
        void operator-=(VEC &data);
        void operator*=(VEC &data);
        void operator/=(VEC &data);
        friend VEC operator+(double num, VEC &vec);
        friend VEC operator-(double num, VEC &vec);
        friend VEC operator*(double num, VEC &vec);
        friend VEC operator/(double num, VEC &vec);

};

VEC operator+(double num, VEC &vec);
VEC operator-(double num, VEC &vec);
VEC operator*(double num, VEC &vec);
VEC operator/(double num, VEC &vec);
#endif