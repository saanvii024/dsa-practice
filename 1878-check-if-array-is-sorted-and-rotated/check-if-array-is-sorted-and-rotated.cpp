class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        // create sorted version
        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end());

        // create doubled array
        vector<int> doubled = nums;

        for(int i = 0; i < n; i++) {
            doubled.push_back(nums[i]);
        }

        // check if sorted array exists inside doubled
        for(int i = 0; i < n; i++) {

            bool match = true;

            for(int j = 0; j < n; j++) {

                if(doubled[i + j] != sortedNums[j]) {
                    match = false;
                    break;
                }
            }

            if(match)
                return true;
        }

        return false;
    }
};