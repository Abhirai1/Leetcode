class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ss;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ss.push_back(sum);
            }
        }
        sort(ss.begin(), ss.end());

        int rs = 0, mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++) rs = (rs + ss[i]) % mod;
        return rs;
    }
};