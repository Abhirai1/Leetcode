class Solution {
public:
    int findGCD(vector<int>& nums) {
     sort(nums.begin(),nums.end()); 
     int l=nums.size();
     return gcd(nums[0],nums[l-1]);   
    }
};