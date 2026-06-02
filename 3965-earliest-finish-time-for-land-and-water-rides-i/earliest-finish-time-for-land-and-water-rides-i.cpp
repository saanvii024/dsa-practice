class Solution {
public:
    int calFinishTime(vector<int>& first_start,vector<int>& first_duration,vector<int>& second_start,vector<int>& second_duration) {

        int minn = INT_MAX;

        for (int i = 0; i < first_start.size(); i++) {
            minn = min(minn, first_start[i] + first_duration[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < second_start.size(); i++) {
            ans = min(ans,max(minn, second_start[i]) + second_duration[i]);
        }

        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            calFinishTime(landStartTime,landDuration,waterStartTime,waterDuration),
            calFinishTime(waterStartTime,waterDuration,landStartTime,landDuration)
        );
    }
};