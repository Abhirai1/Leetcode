class Solution {
public:
    bool winnerOfGame(string colors) {
        int ca=0;
        int cb=0; 

        int ra=0; 
        int rb=0; 
        int n=colors.size()-1;
        for(auto it:colors){
            if(it=='A'){
                ca++;
                // cout<<"in a , cb -> "<<cb<<endl;
                if(cb>2)
                rb+=(cb-2);

                cb=0;
            }
            else{
                // cout<<"in b, ca->  "<<ca<<endl;
                cb++;
                if(ca>2){ 
                ra+=(ca-2);
                }
                ca=0;
            }
        }
        if(cb>2)
            rb+=(cb-2);
        if(ca>2) 
            ra+=(ca-2);
        
        if(ra>rb) return true;

        return false;
    }
};