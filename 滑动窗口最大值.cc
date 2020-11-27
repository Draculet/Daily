//leetcode 239. https://leetcode-cn.com/problems/sliding-window-maximum/
//滑动窗口最大值

//解法是维护一个单调递减的队列，队列中存的是当前窗口范围内最大数的下标
//先对k个数进行队列维护，得到一个单调递减队列，然后指针i向后移，每次去除队列中超出窗口范围的下标，插入当前的下标

/*
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l;
        int i;
        vector<int> res;
        for (i = 0; i < k; i++){
            while (!l.empty() && nums[l.back()] < nums[i])
                l.pop_back();
            l.push_back(i);
        }
        res.push_back(nums[l.front()]);
        for (;i < nums.size(); i++){
            while (!l.empty() && (i - l.front()) >= k)
                l.pop_front();

            while (!l.empty() && nums[l.back()] < nums[i])
                l.pop_back();
            l.push_back(i);
            res.push_back(nums[l.front()]);
        }
        return res;
    }
};