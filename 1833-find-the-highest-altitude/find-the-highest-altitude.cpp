class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int netGain = 0;
        for(int i = 0; i< gain.size(); i++){
            netGain += gain[i];
            ans = max(ans, netGain);
        }
        return ans;
        
    }
};

