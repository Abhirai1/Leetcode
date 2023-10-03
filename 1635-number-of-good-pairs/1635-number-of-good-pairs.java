class Solution {
    public int numIdenticalPairs(int[] nums) {
        int cp = 0 , n;
        n = nums.length;
        for(int i = 0 ; i < n ; i++){
            for (int j = i+1 ; j < n ; j++){
                if(nums[i] == nums[j])
                {
                    cp++;
                }
                
            }
        }
        return cp;
    }
}