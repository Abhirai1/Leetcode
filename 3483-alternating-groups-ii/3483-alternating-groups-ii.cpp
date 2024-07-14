class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 0;
        int alt = 0;
      
        for (int i = 1; i < k; ++i) if (colors[i] != colors[i-1]) alt++;
        
        if (alt == k-1) cnt++;
        
        for (int i = k; i < n + k - 1; ++i) {
            if (colors[(i-k+1) % n] != colors[(i-k) % n]) alt--;
            
            if (colors[i % n] != colors[(i-1) % n]) alt++;
            
            if (alt == k-1) cnt++;
        }
        
        return cnt;
    }
};