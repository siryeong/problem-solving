class Solution {
public:
    const long long MOD = 1000000007ll;
    int n=0, m=0;
    long long dp[50][50][10];

    bool apple(vector<string>& pizza, int r, int c, int p, int q) {
        for(int i = r; i < p; i++) for(int j = c; j < q; j++) {
            if(pizza[i][j] == 'A') return true;
        }
        return false;
    }

    long long backtrace(vector<string>& pizza, int r, int c, int k) {
        if(dp[r][c][k] != -1) return dp[r][c][k];
        if(!apple(pizza, r, c, n, m))
            return dp[r][c][k] = 0;
        if(k == 0) 
            return dp[r][c][k] = 1;

        long long ret = 0;
        for(int i = r+1; i < n; i++) {
            if(!apple(pizza, r, c, i, m)) continue;
            ret += backtrace(pizza, i, c, k-1);
            ret %= MOD;
        }

        for(int j = c+1; j < m; j++) {
            if(!apple(pizza, r, c, n, j)) continue;
            ret += backtrace(pizza, r, j, k-1);
            ret %= MOD;
        }

        return dp[r][c][k] = ret;
    }


    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof dp);
        n = pizza.size();
        m = pizza[0].length();

        return backtrace(pizza, 0, 0, k-1);
    }
};