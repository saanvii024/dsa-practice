class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        //we only go till k/2 because we swap top rows with bottom rows
        for (int i = 0; i < k / 2; i++) {

            
            int topRow = x + i;
            int bottomRow = x + (k - 1 - i);

            //y is not constant → it moves across the width of the square
            for (int j = 0; j < k; j++) {

                int col = y + j;  //column moves from y → y+k-1

                //swap corresponding elements of top and bottom rows
                swap(grid[topRow][col], grid[bottomRow][col]);
            }
        }

        return grid;
    }
};