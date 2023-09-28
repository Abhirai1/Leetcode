class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }

        int odd=-1; 
        int even=-1;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]%2) !=0){
                odd=i; 
                break;
            }
        }

        for(int i=n-1;i>=0;i--){
            if((nums[i]%2)==0){
                even=i; 
                break;
            }
        }

        if(odd==-1 || even==-1)
        return nums;

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