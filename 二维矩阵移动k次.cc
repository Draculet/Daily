//https://leetcode-cn.com/problems/shift-2d-grid/
//1260 leetcode
//时间空间都是O(N*M)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int total = grid.size() * grid[0].size();
        vector<int> arr(total, 0);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                arr[(i * col + j + k) % total] = grid[i][j]; //打为一维数组后，计算移动k位后在一维数组的位置
            }
        }
        
        for (int i = 0; i < total; i++){
            grid[i / col][i % col] = arr[i];
        }
        return grid;
    }
};