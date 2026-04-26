class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        // Step 1: Fill maps
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (first.find(x) == first.end()) {
                first[x] = i;  // store first occurrence
            }

            last[x] = i;      // keep updating last occurrence
            freq[x]++;        // count frequency
        }

        // Step 2: Find degree
        int degree = 0;
        for (auto p : freq) {
            degree = max(degree, p.second);
        }

        // Step 3: Find minimum length
        int ans = nums.size();

        for (auto p : freq) {
            if (p.second == degree) {
                int len = last[p.first] - first[p.first] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};