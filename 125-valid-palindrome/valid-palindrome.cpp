class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        
        for(int i = 0; i < s.size(); i++)
            if(isalpha(s[i]) || isdigit(s[i]))
                v.push_back(tolower(s[i]));

        int i = 0;
        int j = v.size() - 1;

        while(i < j){
            if(v[i] != v[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};