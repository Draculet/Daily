//剑指offer04. https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size()){
            if (matrix[row][col] > target) row--;
            else if (matrix[row][col] < target) col++;
            else return true;
        }
        return false;
    }
};