class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //key=arr[i], val=i
        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i]; //to check if there is an exactly complement number to add to nums i to create target
            if(m.count(comp)){
                return {m[comp], i}; //return their index 
            }
            m[nums[i]] = i; //else add it in the hashtable with key as the number and val as its index
        }

        return {}; //if no solution found
        
    }
};