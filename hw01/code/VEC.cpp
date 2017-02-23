#include "VEC.h"

VEC::VEC(int n){
    this->dimension = n;
    this->val = new double[n]();
}

VEC::VEC(VEC &data){
    this->dimension = data.dimension;
    this->val = new double[data.dimension]();
    for(int i=0; i<this->dimension; i++)
        this->val[i] = data.val[i];
}

VEC::~VEC(){
    delete this->val;
}

int VEC::dim(){
    return this->dimension; 
}
double VEC::sum(){
    double sum=0;
    for(int i=0; i<this->dimension; i++)
        sum += this->val[i];
    return sum;
}
void VEC::print(){
    for(int i=0; i<this->dimension; i++)
        printf("%lf ",this->val[i]);
    printf("\n");
    return;
}

void VEC::checkDim(VEC &data){
    if(this->dimension != data.dimension){
        printf("Dimension dismatch!\n");
        exit(0);
    }
}

bool VEC::operator==(VEC &data){
    if(this->dimension == data.dimension){
        for(int i=0; i<this->dimension; i++)
            if(this->val[i] != data.val[i])
                return false;
        return true;
    }
    else
        return false;
}

void VEC::operator=(VEC &data){
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] = data.val[i];
    return;
}

void VEC::operator=(double num){
    for(int i=0; i<this->dimension; i++)
        this->val[i] = num;
    return;
}

void VEC::operator+=(VEC &data){
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] += data.val[i];
}

void VEC::operator-=(VEC &data){
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] -= data.val[i];
}

void VEC::operator*=(VEC &data){
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] *= data.val[i];
}

void VEC::operator/=(VEC &data){
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] /= data.val[i];
}

double& VEC::operator[](int index) const{
    if(index >= this->dimension || index < 0){
        printf("array[index] out of bound\n");
        exit(0);
    }
    return this->val[index];
}

VEC VEC::operator+(VEC &data){
    VEC out(this->dimension);
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] + data[i];
    return out;
}

VEC VEC::operator-(VEC &data){
    VEC out(this->dimension);
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] - data[i];
    return out;

}

VEC VEC::operator*(VEC &data){
    VEC out(this->dimension);
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] * data[i];
    return out;
}

VEC VEC::operator/(VEC &data){
    VEC out(this->dimension);
    this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] / data[i];
    return out;
}

VEC VEC::operator+(double num){
    VEC out(this->dimension);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] + num;
    return out;
}

VEC VEC::operator-(double num){
    VEC out(this->dimension);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] - num;
    return out;
}

VEC VEC::operator*(double num){
    VEC out(this->dimension);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] * num;
    return out;
}

VEC VEC::operator/(double num){
    VEC out(this->dimension);
    for(int i=0; i<this->dimension; i++)
        out[i] = this->val[i] / num;
    return out;
}

VEC operator+(double num, VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num + vec.val[i];
    return out;
}
VEC operator-(double num, VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num - vec.val[i];
    return out;
}

VEC operator*(double num, VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num * vec.val[i];
    return out;
}

VEC operator/(double num, VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num / vec.val[i];
    return out;
}
























