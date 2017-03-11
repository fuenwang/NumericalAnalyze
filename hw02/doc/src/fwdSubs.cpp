VEC fwdSubs(MAT &m1, VEC b){
    VEC Y(b);
    for(int i=0; i < m1.m; i++){
        for(int j=0; j < i; j++){
            Y[i] -= m1[i][j] * Y[j];
        }
    }
    return Y;
}
