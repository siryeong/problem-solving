class Solution {
public:

    int parent[26];

    int find(int p) {
        if(parent[p] == p) return p;
        return parent[p] = find(parent[p]);
    }

    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb)
            return;

        if(pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        
        for(int i = 0; i < s1.length(); i++)
            merge(s1[i] - 'a', s2[i] - 'a');
        
        string result = "";
        for(int i = 0; i < baseStr.length(); i++)
            result.push_back((char)(find(baseStr[i] - 'a') + 'a'));
        return result;
    }
};