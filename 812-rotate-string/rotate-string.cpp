class Solution {
public:
    bool rotateString(string s, string goal) {
        if (goal.size()!=s.size()) return false;
        string s2 = s + s;
        for(int i = 0; i < s.size(); i++){
            if(goal == s2.substr(i, s.size())) return true;
        }
        
        return false;        
    }
};
