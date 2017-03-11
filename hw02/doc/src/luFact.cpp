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
