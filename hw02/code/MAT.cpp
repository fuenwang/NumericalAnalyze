// Matrix CPP
// ID: 102061149
// Name: Fu-En Wang

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
    for(int i=0; i<m; i++)
        this->val[i] = this->CreateVEC(n);
}

MAT::MAT(const MAT &data){
    this->m = data.m;
    this->n = data.n;
    this->val = new VEC*[m];
    for(int i=0; i<m; i++){
        this->val[i] = this->CreateVEC(n);
        (*this)[i] = data[i];
    } 
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

void MAT::Reset(double **val, int m, int n){
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

void MAT::checkDim(const MAT &data){
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

void MAT::operator=(const MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] = data[i][j];
    return;
}

VEC& MAT::operator[](int index) const{
    if(index >= this->m || index < 0){
        printf("MAT[index] out of bound!\n");
        exit(0);
    }
    return *(this->val[index]);
}

void MAT::operator+=(const MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] += data[i][j];
}
void MAT::operator-=(const MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] -= data[i][j];

}
void MAT::operator*=(const MAT &data){
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] *= data[i][j];

}
void MAT::operator/=(const MAT &data){
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

MAT MAT::operator+(const MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] + data[i][j];
    return out;
}
MAT MAT::operator-(const MAT &data){
    MAT out(this->m, this->n);
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] - data[i][j];
    return out;
}
MAT MAT::operator*(const MAT &data){
    if(this->n != data.m){
        printf("MAT mul size dismatch!\n");
        exit(0);
    }
    MAT out(this->m, data.n);
    //this->checkDim(data);
    /*
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] * data[i][j];
    */
    for(int i=0; i<this->m; i++){
        for(int j=0; j<data.n; j++){
            double sum = 0;
            for(int k = 0; k < this->n; k++){
                sum += (*this)[i][k] * data[k][j];
            }
            out[i][j] = sum;
        }
    }

    return out;
}

VEC MAT::operator*(const VEC &data){
    if(this->n != data.dim()){
        printf("MAT mul size dismatch!\n");
        exit(0);
    }
    VEC out(this->m);
    //this->checkDim(data);
    /*
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            out[i][j] = (*this)[i][j] * data[i][j];
    */
    for(int i=0; i<this->m; i++){
        double sum = 0;
        for(int k = 0; k < this->n; k++){
            sum += (*this)[i][k] * data[k];
        }
        out[i] = sum;
    }

    return out;
}


MAT MAT::operator/(const MAT &data){
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

void MAT::print() const{
    printf("----------------\n");
    printf("%d %d\n", this->m, this->n);
    for(int i=0; i<this->m; i++){
        (*this)[i].print();
        if(i != this->m-1)
            printf("\n");
    }
    printf("----------------\n");
}

MAT MAT::T(){
    MAT out(this->n, this->m);

    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            out[i][j] = (*this)[j][i];
        }
    }
    return out;
}

MAT operator+(double num, const MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  + data[i][j];
    return out;
}
MAT operator-(double num, const MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  - data[i][j];
    return out;
}
MAT operator*(double num, const MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  * data[i][j];
    return out;
}
MAT operator/(double num, const MAT &data){
    MAT out(data.m, data.n);
    for(int i=0; i<data.m; i++)
        for(int j=0; j<data.n; j++)
            out[i][j] = num  / data[i][j];
    return out;
}

VEC fwdSubs(MAT &m1, VEC b){
    VEC Y(b);
    /*
    for(int i=0; i < m1.m; i++){
        for(int j=i+1; j < m1.m; j++){
            Y[j] -= m1[j][i] * Y[i];
        }
    }
    */
    for(int i=0; i < m1.m; i++){
        for(int j=0; j < i; j++){
            Y[i] -= m1[i][j] * Y[j];
        }
    }
    return Y;
}

VEC bckSubs(MAT &m1, VEC b){
    VEC X(b);
    /*
    for(int i=m1.m-1; i >= 0; i--){
        X[i] /= m1[i][i];
        for(int j=i-1; j >= 0; j--){
            X[j] -= m1[j][i] * X[i];
        }
    }
    */
    for(int i=m1.m-1; i >= 0; i--){
        for(int j=m1.m-1; j > i; j--){
            X[i] -= m1[i][j] * X[j];
        }
        X[i] /= m1[i][i];
    }

    return X;
}

MAT &luFact(MAT &m1){
    for(int i=0; i<m1.m; i++){
        for(int j=i+1; j < m1.m; j++){
            m1[j][i] /= m1[i][i];
        }
        for(int j=i+1; j < m1.m; j++){
            for(int k=i+1; k < m1.m; k++){
                m1[j][k] -= m1[j][i] * m1[i][k];
            }
        }

    }
    return m1;
}


