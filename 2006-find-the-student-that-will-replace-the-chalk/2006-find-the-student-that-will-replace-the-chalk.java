class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int ret=0;
        int i=0;
        while(true){
            if(chalk[i]>k){
                return i;
            }
            k-=chalk[i];
            i++;
            if(i==chalk.length){
                i=0;
            }
        }
    }
}