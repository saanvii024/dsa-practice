class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;

        // store all jewels
        for(char ch : jewels){
            m[ch] = 1;
        }

        int cnt = 0;

        // count matching stones
        for(char ch : stones){
            if(m[ch] == 1){ // check if stone is a jewel
                cnt++;
            }
        }

        return cnt;
    }
};