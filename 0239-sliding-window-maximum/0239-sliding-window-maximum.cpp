class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; 
        deque<int> dq; 
        multiset<int> mst;
        int i=0;
        int j=0;
        int n=nums.size(); 
        
        while(j<n){
            mst.insert(nums[j]); 

            if((j-i+1)<k){
                j++;
            }
            else if((j-i+1)==k){
                cout<<*(prev(mst.end()))<<endl;
                ans.push_back(*(prev(mst.end()))); 
                mst.erase(mst.lower_bound(nums[i]));
                i++;
                j++;
            }

            // if(dq.size()==0){
            //     dq.push_back(nums[j]);
            // }
            // else{
            //     if(nums[j]>=dq.front()){
            //         dq.push_front(nums[j]);
            //     }
            //     else{
            //         dq.push_back(INT_MIN);
            //     }
            // }
            
            // if((j-i+1)<k){
            //     j++;
            // }
            // else if((j-i+1)==k){
            //     ans.push_back(dq.front()); 
            //     if(nums[i]==dq.front()){
            //         dq.pop_front();
            //     }
            //     i++;
            //     j++;
            // }
        }
        return ans;
    }
};