class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m; //storing element and its frequency

        //if num exists we change its freq, if not we add it in the hashmap
        //then check if freq of the key is >n/size

        for(int i=0; i< nums.size(); i++){
            if(m.count(nums[i])){
                m[nums[i]]++;   //if the freq exists, the number is in the hashtable, so increase its freq
            } else {
                m[nums[i]] = 1; //else make new key value pair with freq =1
            }


            
        }
                for(auto p : m){ //pair p in m hashtable
            if(p.second > nums.size()/2){
                return p.first;
            }

        }
        return 0;

        
    }
};