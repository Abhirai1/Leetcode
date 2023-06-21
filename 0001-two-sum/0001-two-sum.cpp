class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first;
        int second;
        for(int i = 0;i<nums.size();i++)
        {
            int flag = 0;
            for(int j = 0;j<nums.size();j++)
            {
                if(j != i && nums[i]+nums[j] == target)
                {
                    first = i;
                    second = j;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        return {first,second};
    }
};