class Solution {
public:
    int p[100001];

    int uni(int c) {
        if(p[c] == c) return p[c];
        return p[c] = uni(p[c]);
    }

    void merge(int a, int b) {
        a = uni(a);
        b = uni(b);
        if(a!=b)
            p[a] = p[b];
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < edges.size(); i++) 
            merge(edges[i][0], edges[i][1]);

        unordered_map<int, long long> m;
        for(int i = 0 ; i < n; i++) 
            m[uni(i)]++;

        long long ans = 0;
        for(auto it : m) {
            ans += (n - it.second) * it.second;
            n -= it.second;
        }
        return ans;
    }
};