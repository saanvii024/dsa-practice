class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxx = 0;
        unordered_map<char, int> mp;
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            if (mp.count(s[r]) == 0 || mp[s[r]] < l) {
                mp[s[r]] = r;
                maxx = max(maxx, r - l + 1);
            } else {
                l = mp[s[r]] + 1;
                mp[s[r]] = r;
            }
        }
        
        return maxx;
    }
};