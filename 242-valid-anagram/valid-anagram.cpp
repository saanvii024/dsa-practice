class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
      
        unordered_map <char, int> num;

        for(auto x : s){
            num[x]++;
        }
        for(auto x : t){
            num[x]--;
        }

        for(auto x : num){
            if(x.second != 0){
                return false;
            }
        }

        return true;
        
    }
};