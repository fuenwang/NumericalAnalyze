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

void Json::Write(const MAT &m){
    if(this->ignore)
        return;
    int M = m.GetM();
    int N = m.GetN();
    this->f << "[";
    char s[100];
    for(int i=0; i<M; i++){
        this->f << "[";
        for(int j=0; j<N; j++){
            if( j != N-1) {
                sprintf(s, "%.10lf,", m[i][j]);
                this->f << s;
            }
            else{
                sprintf(s, "%.10lf", m[i][j]);
                this->f << s;
            }
        }
        if(i != M-1)
            this->f << "],";
        else
            this->f << "]";
    }
    //this->f << "]";
}

void Json::Write(const VEC &v){
    if(this->ignore)
        return;
    int N = v.dim();
    char s[100];
    this->f << "[";
    for(int i=0; i<N; i++){
        if(i != N-1){
            sprintf(s, "%.10lf,", v[i]);
        }
        else{
            sprintf(s, "%.10lf", v[i]);
        }
        this->f << s;
    }
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
    //this->checkDim(data);
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
    //this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] += data[i][j];
}
void MAT::operator-=(const MAT &data){
    //this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] -= data[i][j];

}
void MAT::operator*=(const MAT &data){
    //this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*this)[i][j] *= data[i][j];

}
void MAT::operator/=(const MAT &data){
    //this->checkDim(data);
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
    //this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*out.val[i])[j] = (*this->val[i])[j] + (*data.val[i])[j];
    return out;
}
MAT MAT::operator-(const MAT &data){
    MAT out(this->m, this->n);
    //this->checkDim(data);
    for(int i=0; i<this->m; i++)
        for(int j=0; j<this->n; j++)
            (*out.val[i])[j] = (*this->val[i])[j] - (*data.val[i])[j];
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
                sum += (*this->val[i])[k] * (*data.val[k])[j];
            }
            (*out.val[i])[j] = sum;
        }
    }

    return out;
}

VEC MAT::operator*(const VEC &data){
    /*
       if(this->n != data.dim()){
       printf("MAT mul size dismatch!\n");
       exit(0);
       }
       */
    VEC out(this->m);
    //this->checkDim(data);
    /*
       for(int i=0; i<this->m; i++)
       for(int j=0; j<this->n; j++)
       out[i][j] = (*this)[i][j] * data[i][j];
       */
    for(int i=0; i<this->m; i++){
        out[i] = (*this->val[i]) * data;
    }

    return out;
}


MAT MAT::operator/(const MAT &data){
    MAT out(this->m, this->n);
    //this->checkDim(data);
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
            (*out.val[i])[j] = (*this->val[i])[j] / num;
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

int MAT::GetM() const{
    return this->m;
}
int MAT::GetN() const{
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
double error_1_norm(const VEC &E_mat){
    double error = 0;
    for(int i=0; i < E_mat.dim() ; i++)
        error += fabs(E_mat[i]);
    return error;
}

double error_2_norm(const VEC &E_mat){
    double error = 0;
    for(int i=0; i < E_mat.dim() ; i++)
        error += pow(E_mat[i], 2);
    return sqrt(error);
}

double error_infinite_norm(const VEC &E_mat){
    double error = fabs(E_mat[0]);
    for(int i=1; i < E_mat.dim() ; i++)
        if(fabs(E_mat[i]) > error)
            error = fabs(E_mat[i]);
    return error;
}

double error_cg(VEC &r){
    return sqrt((r * r) / r.dim());
}

int jacobi_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
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

int gaussSeidel_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
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

int sgs_E(MAT &A, VEC b, VEC &x, int maxIter, double tol, int E_type){
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
int jacobi(MAT &A, VEC b, VEC &x, int maxIter, double tol){
    return jacobi_E(A, b, x, maxIter, tol, 3);
}
int gaussSeidel(MAT &A, VEC b, VEC &x, int maxIter, double tol){
    return gaussSeidel_E(A, b, x, maxIter, tol, 3);
}
int sgs(MAT &A, VEC b, VEC &x, int maxIter, double tol){
    return sgs_E(A, b, x, maxIter, tol, 3);
}

int sd(MAT &A, VEC b, VEC &x, int maxIter, double tol){
    VEC r(b - A * x); // r0
    double alpha = (r * r) / ( r * (A * r));
    double error;
    for(int it = 1; it <= maxIter; it++){
        x += alpha * r;
        r -= alpha * (A * r);
        error = error_cg(r);
        alpha = (r * r) / ( r * (A * r));

        if(error < tol){
            return it;
        }
    }
    return maxIter+1;
}

int cg(MAT &A, VEC b, VEC &x, int maxIter, double tol){
    VEC r(b - A * x); // r0
    VEC p(r); // p0 = r0
    int n = A.GetM();
    VEC ap(A * p);
    double pap = (p * ap);
    double alpha = (p * r) / pap;
    double beta;
    double error;
    //Json Q("raw_record/error.json",0);
    for(int it = 1; it <= maxIter; it++){
        x += alpha * p;
        r -= alpha * ap;
        beta = (p * (A * r)) / pap;
        p = r - beta * p;
        ap = A * p;
        pap = (p * ap);
        alpha = (p * r) / pap;
        error = sqrt(r * r / n);
        //hw04[0] = x[p1];
        //hw04[1] = x[p2];
        //hw04[2] = x[p3];
        //Q.Write(error_infinite_norm(hw03, hw04));
        if(error < tol){
            //Q.Close();
            return it;
        }

    }
    return maxIter+1;
}

int EVpwr(MAT &A, VEC &q0, double &lambda, double tol, int maxiter){
    int it;
    double error;
    double lambda_old = lambda;
    MAT A_T(A.T());
    VEC Aq(A * q0);
    VEC ATq(q0.dim());
    VEC r(q0.dim());
    VEC q_old(q0.dim());
    double wq;
    //Json D("raw_record/error_e4.json", 0);
    for(it = 1; it <= maxiter; it++){
        q_old = q0;
        q0 = Aq / error_2_norm(Aq);
        Aq = A * q0;
        lambda = q0 * Aq;
        switch(HW06_E){
            case 1:
                error = fabs(lambda - lambda_old);
                break;
            case 2:
                error = error_2_norm(q_old - q0);
                break;
            case 3:
                r = Aq - (lambda * q0);
                error = error_2_norm(r);
                break;
            case 4:
                ATq = (A_T * q0);
                wq = (ATq / error_2_norm(ATq)) * q0;
                r = Aq - (lambda * q0);
                error = error_2_norm(r) / fabs(wq);
        }
        //D.Write(error);
        lambda_old = lambda;
        //cout << lambda << endl; 
        if(error < tol){
            //printf("%g\n", error);
            return it;
        }
        
    }
    //D.Close();
    return it;
}

int EViPwr(MAT &A, VEC &q0, double &lambda, double tol, int maxiter){
    int it;
    double error;
    double lambda_old = lambda;
    MAT A_lu(A);
    MAT A_T(A.T());
    VEC Aq(q0.dim());
    VEC ATq(q0.dim());
    VEC r(q0.dim());
    VEC q_old(q0.dim());
    VEC z(q0.dim());
    VEC buf(q0.dim());
    //Performance Q;
    double wq;
    z = 0;
    z[0] = 1;
    luFact(A_lu);
    for(it = 1; it <= maxiter; it++){
        q_old = q0;
        buf = fwdSubs(A_lu, q0);
        z = bckSubs(A_lu, buf);
        q0 = z / error_2_norm(z);
        Aq = A * q0;
        lambda = q0 * Aq;
        switch(HW06_E){
            case 1:
                error = fabs(lambda - lambda_old);
                break;
            case 2:
                error = error_2_norm(q_old - q0);
                break;
            case 3:
                r = Aq - (lambda * q0);
                error = error_2_norm(r);
                break;
            case 4:
                ATq = (A_T * q0);
                wq = (ATq / error_2_norm(ATq)) * q0;
                r = Aq - (lambda * q0);
                error = error_2_norm(r) / fabs(wq);
        }
        lambda_old = lambda;
        //cout << lambda << endl;
        if(error < tol){
            //printf("%g\n", error);
            return it;
        }
    }
    return it;

}

int EViPwrShft(MAT &A, VEC &q0, double &lambda, double mu, double tol, int maxiter){
    int it;
    double error;
    double lambda_old = lambda;
    MAT I(A.GetN());
    for(int i=0; i < A.GetN(); i++)
        I[i][i] = 1;
    MAT A_T(A.T());
    MAT A_shift(A - I * mu);
    VEC Aq(q0.dim());
    VEC ATq(q0.dim());
    VEC r(q0.dim());
    VEC q_old(q0.dim());
    VEC z(q0.dim());
    VEC buf(q0.dim());
    //Performance Q;
    double wq;
    z = 0;
    z[0] = 1;
    luFact(A_shift);
    for(it = 1; it <= maxiter; it++){
        //cout << error << endl;
        q_old = q0;
        buf = fwdSubs(A_shift, q0);
        z = bckSubs(A_shift, buf);
        q0 = z / error_2_norm(z);
        Aq = A * q0;
        lambda = q0 * Aq;
        switch(HW06_E){
            case 1:
                error = fabs(lambda - lambda_old);
                break;
            case 2:
                error = error_2_norm(q_old - q0);
                break;
            case 3:
                r = Aq - (lambda * q0);
                error = error_2_norm(r);
                break;
            case 4:
                ATq = (A_T * q0);
                wq = (ATq / error_2_norm(ATq)) * q0;
                r = Aq - (lambda * q0);
                error = error_2_norm(r) / fabs(wq);
        }

        lambda_old = lambda;
        if(error < tol){
            //printf("%g\n", error);
            return it;
        }
    }
    return it;
}















