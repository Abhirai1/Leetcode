class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long int sum=0; for(auto it:chalk) sum+=it; 

       sum = (k%sum);

        for(int i=0;i<chalk.size();i++){
            if(sum<chalk[i]) return i;
            sum-=chalk[i];
        }

        return 0;
    }
};