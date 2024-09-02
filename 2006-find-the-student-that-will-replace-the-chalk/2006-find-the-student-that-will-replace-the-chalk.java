class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int ret=0;
        int i=0;
        int n=chalk.length;
        while(true){
            if(chalk[i]>k){
                return i;
            }
            k-=chalk[i];
            i++;
            // i=i%n;
            if(i==chalk.length){
                i=0;
            }
        }
    }
}