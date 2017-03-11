VEC bckSubs(MAT &m1, VEC b){
    VEC X(b);
    for(int i=m1.m-1; i >= 0; i--){
        for(int j=m1.m-1; j > i; j--){
            X[i] -= m1[i][j] * X[j];
        }
        X[i] /= m1[i][i];
    }
    return X;
}
