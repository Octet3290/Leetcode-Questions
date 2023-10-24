class Solution {
public:
    vector<vector<long long>> C;
    long long comb(int i, int j){
        if (C[i][j]!=-1) return C[i][j];
        if (j==0 || j==i ) return C[i][j]=1LL;
        return C[i][j]=comb(i-1, j)+comb(i-1, j-1);
    }
    int uniquePaths(int m, int n) {
        int N = n + m - 2, K = min(n - 1, m - 1);
        C.assign(N+1, vector(K+1, -1LL));
        return comb(N, K);
    }
};

