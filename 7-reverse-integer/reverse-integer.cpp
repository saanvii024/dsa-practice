class Solution {
public:
    int reverse(int x) {
        int ans = 0; 
        while (x != 0) {
            int digit = x % 10; //last digit
            
            //check for over/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; //0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; //append the digit to the reversed number
            x = x / 10; //remove the last digit from x
        }
        return ans;
    }
};