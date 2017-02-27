MAT A_t = A.transpose();
MAT G(n, n);
G[0] = A_t[0];
for(int k=1; k<n; k++){
    G[k] = 0;
    for(int i=0; i<k; i++){
        G[k] += (A_t[k] * G[i]).sum() * G[i] / (G[i] * G[i]).sum();
    }
    G[k] = A_t[k] - G[k];
}
G = G.T();
