class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count =0;
        for(char j : jewels){
            for(char s : stones){
                if ( j==s){
                    count++;
                }
            }
        }
        return count;
        
    }
};