class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp; //stores next greater for each element
        stack<int> st;

        //nums2
        for (int num : nums2) {

            //while current is greater than stack top
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num; //found next greater
                st.pop();
            }

            st.push(num);
        }

        //remaining elements → no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        //result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};