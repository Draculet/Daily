//leetcode 384. https://leetcode-cn.com/problems/shuffle-an-array/
//打乱数组

class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
        copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = arr.size() - 1; i >= 0; i--){
            int r = rand() % (i + 1);
            int tmp = arr[i];
            arr[i] = arr[r];
            arr[r] = tmp;
        }
        return arr;
    }
    vector<int> arr;
    vector<int> copy;
};