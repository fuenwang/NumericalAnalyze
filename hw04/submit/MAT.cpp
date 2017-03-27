// Matrix CPP
// ID: 102061149
// Name: Fu-En Wang

#include "MAT.h"

void Performance::Start(){
    gettimeofday(&this->start, NULL);
}

double Performance::End(){
    double duration;
    gettimeofday(&this->stop, NULL);
    duration = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    return duration;
}

double Performance::End(const char right[], const char left[]){
    double duration;
    gettimeofday(&this->stop, NULL);
    duration = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    printf("%s %g %s\n", right, duration, left);
    return duration;
}

Json::Json(const char f_name[], int flag){
    this->first = 1;
    this->ignore = flag;
    if(!this->ignore){
        this->f.open(f_name, ios::out);
    }
}

void Json::Write(int data){
    if(this->ignore)
        return;
    if(this->first == 1){
        this->first = 0;
        this->f << "[";
    }
    else
        this->f << ",";
    char s[100];
    sprintf(s, "%d", data);
    this->f << s;
}

void Json::Write(double data, int mode){
    if(this->ignore)
        return;
    if(this->first == 1){
        this->first = 0;
        this->f << "[";
    }
    else
        this->f << ",";
    char s[100];
    if(mode == 0)
        sprintf(s, "%g", data);
    else
        sprintf(s, "%lf", data);
    this->f << s;
}

void Json::Write(float data, int mode){
    if(this->ignore)
        return;
    if(this->first == 1){
        this->first = 0;
        this->f << "[";
    }
    else
        this->f << ",";
    char s[100];
    if(mode == 0)
        sprintf(s, "%g", data);
    else
        sprintf(s, "%f", data);
    this->f << s;
}

void Json::Write(const char data[]){
    if(this->ignore)
        return;
    if(this->first == 1){
        this->first = 0;
        this->f << "[";
    }
    else
        this->f << ",";
    char s[100];
    sprintf(s, "\"%s\"", data);
    this->f << s;
}

void Json::Close(){
    if(this->ignore)
        return;
    this->f << "]" << endl;
    this->f.close();
}

MAT::MAT(int n){  // Square Matrix
    this->m = n;
    this->n = n;
    this->val = new VEC*[m];
    for(int i=0; i<n; i++)
        this->val[i] = this->CreateVEC(n);
}

MAT::MAT(int m, int n){ // Rectangular Matrix
    this->m = m;
    this->n = n;
    this->val = new VEC*[m];
    for(int i=0; i<m; i++)
        this->val[i] = this->CreateVEC(n);
}

MAT::MAT(const MAT &data){ // Copy matrix
    this->m = data.m;
    this->n = data.n;
    this->val = new VEC*[m];
    for(int i=0; i<m; i++){
        this->val[i] = this->CreateVEC(n);
        (*this)[i] = data[i];
    } 
}


MAT::MAT(double **val, int m, int n){ // Matrix with initial value
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

void MAT::checkDim(const MAT &data){ // Check m,n match or not
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

void MAT::operator=(const MAT &data){ // Assign maatrix value
    this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] = data[i][j];
    return;
}

void MAT::operator=(double num){ // Assign maatrix value
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] = num;
    return;
}


VEC& MAT::operator[](int index) const{ // Indexing: A[0], A[1]
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

int MAT::GetM(){
    return this->m;
}
int MAT::GetN(){
    return this->n;
}

VEC fwdSubs(MAT &m1, VEC b){ // Forward Substitution
    int m = m1.GetM();
    VEC Y(b);
    for(int i=0; i < m; i++){
        for(int j=0; j < i; j++){
            Y[i] -= m1[i][j] * Y[j];
        }
    }
    return Y;
}

VEC bckSubs(MAT &m1, VEC b){ // Backward Substitution
    int m=m1.GetM();
    VEC X(b);
    for(int i=m-1; i >= 0; i--){
        for(int j=m-1; j > i; j--){
            X[i] -= m1[i][j] * X[j];
        }
        X[i] /= m1[i][i];
    }
    return X;
}

MAT &luFact(MAT &m1){ // LU Decomposition
    int m=m1.GetM();
    for(int i=0; i<m; i++){
        for(int j=i+1; j < m; j++){
            m1[j][i] /= m1[i][i];
        }
        for(int j=i+1; j < m; j++){
            for(int k=i+1; k < m; k++){
                m1[j][k] -= m1[j][i] * m1[i][k];
            }
        }
    }
    return m1;
}

double error_1_norm(VEC &x1, VEC &x2){
    VEC E_mat(x1 - x2);
    double error = 0;
    for(int i=0; i < E_mat.dim() ; i++)
        error += fabs(E_mat[i]);
    return error;
}

double error_2_norm(VEC &x1, VEC &x2){
    VEC E_mat(x1 - x2);
    double error = 0;
    for(int i=0; i < E_mat.dim() ; i++)
        error += pow(E_mat[i], 2);
    return sqrt(error);
}

double error_infinite_norm(VEC &x1, VEC &x2){
    VEC E_mat(x1 - x2);
    double error = fabs(E_mat[0]);
    for(int i=1; i < E_mat.dim() ; i++)
        if(fabs(E_mat[i]) > error)
            error = fabs(E_mat[i]);
    return error;
}

int jacobi(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
    int it;
    int dim = x.dim();
    double tmp;
    double error;
    for(it=1; it <= maxIter; it++){
        VEC last_x(x);
        for(int i=0; i < dim; i++){
            tmp = 0;
            for(int j=0; j<dim; j++){
                if(j != i){
                    tmp += A[i][j] * last_x[j];
                }
            }
            x[i] = (1 / A[i][i]) * (b[i] - tmp);
        }
        //error = error_1_norm(last_x, x);
        switch(E_type){
            case 1:
                error = error_1_norm(last_x, x);
                break;
            case 2:
                error = error_2_norm(last_x, x);
                break;
            case 3:
                error = error_infinite_norm(last_x, x);
                break;
            default:
                cout << "Error type wrong" << endl;
                error = 0;
        }
        
        if(error < tol){
            return it;
        }
    }
    return it;
}

int gaussSeidel(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
    int it;
    int dim = x.dim();
    double tmp1;
    double tmp2;
    double error;
    for(it=1; it <= maxIter; it++){
        VEC last_x(x);
        for(int i=0; i < dim; i++){
            tmp1 = 0;
            tmp2 = 0;
            for(int j=0; j < i; j++){
                tmp1 += A[i][j] * x[j];
            }
            for(int j=i+1; j < dim; j++){
                tmp2 += A[i][j] * last_x[j];
            }
            x[i] = (1 / A[i][i]) * (b[i] - tmp1 - tmp2);
        }
        switch(E_type){
            case 1:
                error = error_1_norm(last_x, x);
                break;
            case 2:
                error = error_2_norm(last_x, x);
                break;
            case 3:
                error = error_infinite_norm(last_x, x);
                break;
            default:
                cout << "Error type wrong" << endl;
                error = 0;
        }
        if(error < tol){
            return it;
        }
    }
    return it;
}

int sgs(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
    int it;
    int m = A.GetM();
    double tmp1;
    double tmp2;
    double error;
    for(it = 1; it <= maxIter; it++){
        VEC last_x(x);
        // Forward
        for(int i=0; i < m; i++){
            tmp1 = 0;
            tmp2 = 0;
            for(int j=0; j < i; j++)
                tmp1 += A[i][j] * x[j];
            for(int j=i+1; j < m; j++)
                tmp2 += A[i][j] * last_x[j];
            x[i] = (1 / A[i][i]) * (b[i] - tmp1 - tmp2);
        }
        // Backward
        
        for(int i=m-1; i >= 0; i--){
            tmp1 = 0;
            tmp2 = 0;
            for(int j=0; j<i; j++)
                tmp1 += A[i][j] * x[j];

            for(int j=i+1; j < m; j++)
                tmp2 += A[i][j] * x[j];

            x[i] = (1 / A[i][i]) * (b[i] - tmp1 - tmp2);
        }
        
        switch(E_type){
            case 1:
                error = error_1_norm(last_x, x);
                break;
            case 2:
                error = error_2_norm(last_x, x);
                break;
            case 3:
                error = error_infinite_norm(last_x, x);
                break;
            default:
                cout << "Error type wrong" << endl;
                error = 0;
        }
        if(error < tol){
            return it;
        }

    }
    return it;
}








