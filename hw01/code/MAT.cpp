#include "MAT.h"

MAT::MAT(int n){
    this->m = n;
    this->n = n;
    this->val = new VEC*[m];
    for(int i=0; i<n; i++)
        this->val[i] = this->CreateVEC(n);
}

MAT::MAT(int m, int n){
    this->m = m;
    this->n = n;
    this->val = new VEC*[m];
    for(int i=0; i<n; i++)
        this->val[i] = this->CreateVEC(n);
}

MAT::MAT(double **val, int m, int n){
    this->m = m;
    this->n = n;
    this->val = new VEC*[m];
    for(int i=0; i<m; i++){
        this->val[i] = this->CreateVEC(n);
        for(int j=0; j<n; j++)
            (*this)[i][j] = val[i][j];
    } 
}

MAT::~MAT(){
    for(int i=0; i<this->n; i++){
        this->val[i]->~VEC();
        //delete this->val[i];
    }
    delete this->val;
}

void MAT::checkDim(MAT &data){
    if (this->m != data.m || this->n != data.n){
        printf("MAT dimension dismatch!\n");
        exit(0);
    }
    return;
}

VEC* MAT::CreateVEC(int n){
    VEC *out = new VEC(n);
    return out;
}

void MAT::operator=(MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] = data[i][j];
    return;
}

VEC& MAT::operator[](int index){
    if(index >= this->m || index < 0){
        printf("MAT[index] out of bound!\n");
        exit(0);
    }
    return *(this->val[index]);
}

void MAT::operator+=(MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] += data[i][j];
}
void MAT::operator-=(MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] -= data[i][j];

}
void MAT::operator*=(MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] *= data[i][j];

}
void MAT::operator/=(MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] /= data[i][j];

}

void MAT::operator+=(double num){
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] += num;
}
void MAT::operator-=(double num){
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] -= num;
}
void MAT::operator*=(double num){
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] *= num;
}
void MAT::operator/=(double num){
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] /= num;
}

MAT MAT::operator+(MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] + data[i][j];
    return out;
}
MAT MAT::operator-(MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] - data[i][j];
    return out;
}
MAT MAT::operator*(MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] * data[i][j];
    return out;
}
MAT MAT::operator/(MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] / data[i][j];
    return out;
}

MAT MAT::operator+(double num){
    MAT out(this->m, this->n);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] + num;
    return out;
}
MAT MAT::operator-(double num){
    MAT out(this->m, this->n);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] - num;
    return out;
}
MAT MAT::operator*(double num){
    MAT out(this->m, this->n);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] * num;
    return out;
}
MAT MAT::operator/(double num){
    MAT out(this->m, this->n);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] / num;
    return out;
}

void MAT::print(){
    printf("%d %d\n", this->m, this->n);
    for(int i=0; i<this->m; i++){
        (*this)[i].print();
        printf("\n");
    }
}

MAT operator+(double num, MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  + data[i][j];
    return out;
}
MAT operator-(double num, MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  - data[i][j];
    return out;
}
MAT operator*(double num, MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  * data[i][j];
    return out;
}
MAT operator/(double num, MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  / data[i][j];
    return out;
}

