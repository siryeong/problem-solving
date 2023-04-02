class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = potions.size();

        for(int i = 0; i < spells.size(); i++) {
            long long t = success/(long long)spells[i] + (success%(long long) spells[i] ? 1:0);
            if(t > 0x7ffffffff) {
                ans.push_back(0);
                continue;
            }
            int k = n - (lower_bound(potions.begin(), potions.end(), t) - potions.begin());
            ans.push_back(k);
        }

        return ans;
    }
};