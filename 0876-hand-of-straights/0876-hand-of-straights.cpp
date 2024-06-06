class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp; 
        int n = hand.size();
        for (auto it : hand) mp[it]++; 

        unordered_map<int, int> vis;

        if (n % groupSize != 0) return false;

        for (auto tt : mp) {
            int start = tt.first;
            int freq = tt.second;

            if (freq == 0) continue; 

            int cnt = 1;
            vis[start] = 1;
            for (int i = 1; i < groupSize; ++i) {
                int next = start + i;
                if (mp[next] < freq) {
                    return false;
                }
                mp[next] -= freq;
                if (mp[next] == 0) {
                    mp.erase(next);
                }
                cnt++;
            }
            mp[start] = 0;
        }

        return true;
    }
};
