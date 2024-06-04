class Solution {
public:
    int longestPalindrome(string s) {
        int even=0,odd=0; 

        unordered_map<char,int> ump; 
        for(auto it:s) ump[it]++; 
        int isodd=0;
        for(auto it:ump){
            if(it.second&1) {odd+=(it.second-1);
                isodd=1;
            }
            else even+=it.second;
        }

        return (odd+even + (isodd));
    }
};