class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ansloc;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]>=target){
                ansloc = i;
                break;
            }
        }
    return ansloc;
    }
};