class Solution {
public:
bool isPossible(vector<int> arr ,int n, int m,int mid ){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum + arr[i] <= mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i]> mid){
                return false;
            }
            pageSum=arr[i];
        }
        
    }
    return true;
} 
long long oprSection(int n, int m, vector<int> arr) 
{
    int sum=0; 
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        sum+=arr[i];
    } 
    int s=mini; 
    int e= sum;
    int mid=s+(e-s)/2;
    int ans=-1; 
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid; 
            e=mid-1;
        } 
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
} 
    int splitArray(vector<int>& nums, int k) {
        return oprSection(nums.size(),k,nums);
    }
};