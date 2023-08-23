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
    int s=0; 
    int sum=0; 
    for(int i=0;i<n;i++){
        sum+=arr[i];
    } 
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