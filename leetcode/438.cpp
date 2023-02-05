class Solution {
private:
    int alpha[26];

    bool anagram() {
        for(int i = 0; i < 26; i++)
            if(alpha[i]!=0) 
                return false;
        return true;
    }
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) return ans;

        memset(alpha, 0, sizeof alpha);
        for(int i = 0; i < p.length(); i++) 
            alpha[p[i] - 'a']++;        

        for(int i = 0; i < p.length(); i++)
            alpha[s[i] - 'a']--;

        for(int i = p.length(); i < s.length(); i++) {
            if(anagram())
                ans.push_back(i - p.length());
            alpha[s[i] - 'a']--;
            alpha[s[i - p.length()] - 'a']++;
        }
        if(anagram())
            ans.push_back(s.length() - p.length());
        return ans;
    }
};