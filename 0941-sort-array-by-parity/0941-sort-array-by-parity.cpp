class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }

        int n=nums.size();

        int odd=0; 
        int even=n-1;

        cout<<"odd -> "<<odd<<" even -> "<<even<<endl;

        while(odd<even){
            if((nums[odd]%2!=0 && nums[even]%2==0)){
                 swap(nums[odd],nums[even]);
                 odd++,even--;
            }
           else if(nums[even]%2!=0){
                even--;
            }
            else if(nums[odd]%2==0){
                odd++;
            }
            
           
        }

        return nums;

    }
};