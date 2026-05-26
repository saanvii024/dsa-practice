class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char, int> mp;

        // store unique characters
        for(char c : word){

            if(mp.count(c) == 0){

                mp[c] = c;
            }
        }

        int ans = 0;

        // check lowercase letters only
        for(auto it : mp){

            char c = it.first;

            // if lowercase
            if(c >= 'a' && c <= 'z'){

                // check if uppercase exists
                if(mp.count(c - 32)){

                    ans++;
                }
            }
        }

        return ans;
    }
};