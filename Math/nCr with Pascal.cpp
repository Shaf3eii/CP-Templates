int C[32][32];
void pre() {
    memset(C, 0, sizeof C);
    for (int i = 0; i < 32; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}