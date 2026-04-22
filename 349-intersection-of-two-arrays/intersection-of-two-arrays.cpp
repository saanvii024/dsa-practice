class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;

        // Store elements of nums1
        for(int i : nums1){
            m[i] = 1;  // mark presence
        }

        // Traverse nums2 and find intersection
        for(int i : nums2){
            if(m[i] == 1){
                ans.push_back(i);  // add to result
                m[i] = 0;          // mark as used (avoid duplicates)
            }
        }

        return ans;
    }
};