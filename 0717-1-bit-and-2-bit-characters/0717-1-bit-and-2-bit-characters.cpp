class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        int pos=0; 

        while(pos<bits.size()){
            if(pos==bits.size()-1){
                return true;
            }
            if(bits[pos]==1){
                pos+=2;
            }
            else{
                pos++;
            }
        }

        return false;

    }
};