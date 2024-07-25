class Solution {
public:
    string losingPlayer(int x, int y) {
        int p=x; 
        int t=y/4; 

        if(min(p,t)&1) return "Alice";

        return "Bob";
    }
};