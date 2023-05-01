class Solution {
public:  
void merge(vector<int> &nums , int s , int e){
    int mid=s+(e-s)/2; 
    int length1=mid-s+1; 
    int length2=e-mid;
    vector<int> m1; 
    vector<int> m2; 

    // value copy kr lete hai 
    int mainVectorIndex=s;
    for(int i=0;i<length1;i++){
        m1.push_back(nums[mainVectorIndex++]);
    } 
     mainVectorIndex=mid+1;
    for(int i=0;i<length2;i++){
        m2.push_back(nums[mainVectorIndex++]);
    } 

    // ab merge karte hai array ko  


    int index1=0; 
    int index2=0; 

    mainVectorIndex=s;

    while(index1<length1 && index2<length2){
        if(m1[index1] < m2[index2])
        nums[mainVectorIndex++] = m1[index1++]; 
        else
        nums[mainVectorIndex++] = m2[index2++]; 
 
    } 

    while(index1 < length1){
        nums[mainVectorIndex++] = m1[index1++]; 
    } 
    while(index2 < length2){
        nums[mainVectorIndex++] = m2[index2++]; 
    }

}
void mergeSort(vector<int> &nums , int s , int e){
    if(s>=e){
        return;
    } 
    int mid=s+(e-s)/2;
    // left portion
    mergeSort(nums,s,mid); 

    // right portion
    mergeSort(nums,mid+1,e); 

    // add jod do dono ko 

    merge(nums,s,e);
}
    vector<int> sortArray(vector<int>& nums) {
        int s=0; 
        int e=nums.size()-1; 
        mergeSort(nums,s,e); 
        return nums;
    }
};