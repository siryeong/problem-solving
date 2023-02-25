class Solution {
public:
    int arr1[100001];
    int arr2[100001];

    int maxProfit(vector<int>& prices) {
        int _min = 100001;
        int max_dif = 0;

        for(int i = 0; i < prices.size(); i++) {
            _min = min(_min, prices[i]);
            max_dif = max(max_dif, prices[i] - _min);
            arr1[i] = max_dif;
        }

        int _max = 0;
        max_dif = 0;

        for(int i = prices.size()-1; i >= 0; i--) {
            _max = max(_max, prices[i]);
            max_dif = max(max_dif, _max - prices[i]);
            arr2[i] = max_dif;
        }

        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, arr1[i]+arr2[i]);
        }
        return ans;
    }
};