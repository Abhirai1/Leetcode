#include <unordered_map>
#include <set>

class Solution {
public:
    int power(int n, std::unordered_map<int, int>& dp) {
        if (n == 1) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        if (n % 2 == 0) return dp[n] = 1 + power(n / 2, dp);
        return dp[n] = 1 + power(3 * n + 1, dp);
    }

    int getKth(int lo, int hi, int k) {
        std::unordered_map<int, int> dp;
        // Use a set of tuples to enforce secondary sorting by the integer value
        std::set<std::pair<int, int>> s;
        
        for (int i = lo; i <= hi; i++) {
            int val = power(i, dp);
            s.insert({val, i});
        }
        
        for (const auto& it : s) {
            k--;
            if (k == 0) return it.second;
        }
        return -1;
    }
};
