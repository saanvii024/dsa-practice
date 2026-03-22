class Solution {
public:

    //function to rotate matrix 90 degrees clockwise
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        //new matrix to store rotated values
        vector<vector<int>> temp(n, vector<int>(n));

        
        // element at (i, j) goes to (j, n-1-i), rotation logic
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = mat[i][j];
            }
        }

        //copy rotated matrix back to original
        mat = temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        //trying all 4 possible rotations
        for (int k = 0; k < 4; k++) {

            //if at any stage matrices match, return true
            if (mat == target)
                return true;

            //rotate and try again
            rotate(mat);
        }

        // if none matched
        return false;
    }
};