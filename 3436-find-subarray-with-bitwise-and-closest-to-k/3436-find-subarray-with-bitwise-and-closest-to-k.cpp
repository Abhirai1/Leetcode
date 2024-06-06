class Solution {
public:

    void update(int num, vector<int> &bits) {
        for (int i = 0; i < 32; i++) {
            if ((num & (1 << i))) {
                bits[i]++;
            }
        }

        // cout<<"update ki array"<<endl;

        // for(auto it:bits) cout<<it<<" ";
        // cout<<endl;
    }

    int getNewAnd(vector<int> &bits, int num, int sz) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if ((num & (1 << i))) bits[i]--;
        }

        // cout<<"update ki array -> sz ki value"<<sz<<endl;

        // for(auto it:bits) cout<<it<<" ";
        // cout<<endl;

        for (int i = 0; i < 32; i++) {
            if (bits[i] == sz) {
                ans |= (1 << i);
                // cout<<"getnewand-> "<<ans<<endl;
            }
        }
        // cout<<"getnewand-> "<<ans<<endl;
        return ans;
    }

    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int ans = INT_MAX;
        int opr = nums[0];  

        vector<int> bits(32, 0);

        while (j < n) {
            opr &= nums[j];
            update(nums[j], bits);
            ans = min(ans, abs(k - opr));
            // cout<<"upper-> "<<opr<<endl;
            if (k < opr) j++;
            else if (k == opr) return 0;
            else {
                while (i <= j && k > opr) {
                    opr = getNewAnd(bits, nums[i], (j - i));
                    i++;
                    // cout<<"in while-> "<<opr<<endl;
                    ans = min(ans, abs(k - opr));
                }
                j++;
            }
        }

        return ans;
    }
};
