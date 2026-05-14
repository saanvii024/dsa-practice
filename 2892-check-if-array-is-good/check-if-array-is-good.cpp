class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxx = n-1;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 1; i < maxx; i++){
            if(mp[i]!=1){
                return false;
            }
        }
        return mp[maxx] == 2; //if ==2 it returns true,else false
        
    }
};