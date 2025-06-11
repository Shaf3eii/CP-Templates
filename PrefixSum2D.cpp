struct prefix_2D {
    int n, m;
    vector<vector<int>> pre;

    prefix_2D(const vector<vector<int>> & matrix) {
        n = matrix.size() - 1;
        m = matrix[0].size() - 1;
        pre = vector (n + 1, vector<int> (m + 1));

        buildPrefix2D(matrix);
    }

    void buildPrefix2D(const vector<vector<int>> & matrix) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre[i][j] = matrix[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
            }
        }
    }

    void printPrefix() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << pre[i][j] << " \n"[j == m];
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    }
};
