class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = 10001;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++) {
            minimum = min(minimum, prices[i]);
            ans = max(ans, prices[i] - minimum);
        }

        return ans;
    }
};