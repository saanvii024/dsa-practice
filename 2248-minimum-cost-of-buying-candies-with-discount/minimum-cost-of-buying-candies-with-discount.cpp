class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {  //every 3rd candy is free
                ans += cost[i];
            }
        }

        return ans;
    }
};
//reverse pattern
//6 5 4 3 2 1
//0 1 2 3 4 5
// 2 3 5 6 9 - odd - 23, 20 backward way
//9 6 5 3 2 
//0 1 2 3 4 
//n - 1 where n is %3==0 i starts from 1

        

//3rd candy <= min(c[0] , c[1])
//min cost of buying candies