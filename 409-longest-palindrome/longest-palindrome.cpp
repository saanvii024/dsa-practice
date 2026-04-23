class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        bool hasOdd = false;

        for (auto ch : s) {
            m[ch]++;
        }

        for (auto p : m) {
            if (p.second % 2 == 0) {
                ans += p.second;
            } else {
                ans += p.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) ans += 1;

        return ans;
    }
};