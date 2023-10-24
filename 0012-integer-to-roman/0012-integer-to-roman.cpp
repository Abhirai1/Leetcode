class Solution {
public:
    string intToRoman(int num)
    {
        string roman;
        vector<string> notations={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> value={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        for(int i = 12; i>=0;i--){
            while(num >= value[i]){
                roman=roman+notations[i];
                num=num-value[i];
            }
        }
         return roman;
    }
};