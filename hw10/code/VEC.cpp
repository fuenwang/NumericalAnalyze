// Vector CPP
// ID: 102061149
// Name: Fu-En Wang

#include "VEC.h"

VEC::VEC(int n){
    this->dimension = n;
    this->val = new double[n]();
}

VEC::VEC(const VEC &data){
    this->dimension = data.dimension;
    this->val = new double[data.dimension]();
    for(int i=0; i<this->dimension; i++)
        this->val[i] = data.val[i];
}

VEC::~VEC(){
    delete this->val;
}

int VEC::dim() const{
    return this->dimension; 
}

void VEC::sort(){
    double tmp;
    for(int i=0; i <= this->dimension; i++){
        for(int j=i+1; j<this->dimension; j++){
           if(this->val[i] > this->val[j]) {
                tmp = this->val[i];
                this->val[i] = this->val[j];
                this->val[j] = tmp;
           }
        }
    }
}

double VEC::sum(){
    double sum=0;
    for(int i=0; i<this->dimension; i++)
        sum += this->val[i];
    return sum;
}
void VEC::print(){
    for(int i=0; i<this->dimension; i++)
        printf("%g ",this->val[i]);
    printf("\n");
    return;
}

void VEC::checkDim(const VEC &data){
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

void VEC::operator=(const VEC &data){
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] = data.val[i];
    return;
}

void VEC::operator=(double num){
    for(int i=0; i<this->dimension; i++)
        this->val[i] = num;
    return;
}
void VEC::operator=(int num){
    for(int i=0; i<this->dimension; i++)
        this->val[i] = num;
    return;
}

void VEC::operator=(const double *a){
    for(int i=0; i<this->dimension; i++){
        this->val[i] = a[i];
    }
    return;
}

void VEC::operator+=(const VEC &data){
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] += data.val[i];
}

void VEC::operator-=(const VEC &data){
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] -= data.val[i];
}

void VEC::operator*=(const VEC &data){
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] *= data.val[i];
}

void VEC::operator/=(const VEC &data){
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        this->val[i] /= data.val[i];
}
void VEC::operator/=(double num){
     for(int i=0; i<this->dimension; i++)
        this->val[i] /= num;
}


double& VEC::operator[](int index) const{
    if(index >= this->dimension || index < 0){
        printf("array[index] out of bound\n");
        exit(0);
    }
    return this->val[index];
}

VEC VEC::operator+(const VEC &data){
    VEC out(this->dimension);
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out.val[i] = this->val[i] + data.val[i];
    return out;
}

VEC VEC::operator-(const VEC &data){
    VEC out(this->dimension);
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out.val[i] = this->val[i] - data.val[i];
    return out;

}

double VEC::operator*(const VEC &data){
    double sum = 0;
    //VEC out(this->dimension);
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        sum  += this->val[i] * data.val[i];
    return sum;
}

VEC VEC::operator/(const VEC &data){
    VEC out(this->dimension);
    //this->checkDim(data);
    for(int i=0; i<this->dimension; i++)
        out.val[i] = this->val[i] / data.val[i];
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

VEC operator+(double num, const VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num + vec.val[i];
    return out;
}
VEC operator-(double num, const VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num - vec.val[i];
    return out;
}

VEC operator*(double num, const VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num * vec.val[i];
    return out;
}

VEC operator/(double num, const VEC &vec){
    VEC out(vec.dimension);
    for(int i=0; i<vec.dimension; i++)
        out.val[i] = num / vec.val[i];
    return out;
}

double Lagrange(double x, VEC &XDATA, VEC &YDATA){
    int n = YDATA.dim();
    VEC NS(YDATA);
    for(int k=1; k<n; k++){
        for(int j=0; j<n-k; j++){
            NS[j] = ((x - XDATA[j]) * NS[j+1] - (x - XDATA[k+j]) * NS[j]) / (XDATA[j+k] - XDATA[j]);
        }
    }
    return NS[0];
}




