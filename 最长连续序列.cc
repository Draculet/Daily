//leetcode 128 https://leetcode-cn.com/problems/longest-consecutive-sequence/
//先去重,然后找出去除数组中 可能连续的数的末尾x,从末尾开始往前使用set查找x-1 x-2 ...直到set中找不到下一个连续的数
//注意：使遍历单向进行，而非双向搜索

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int res = 0;
        for (auto i : s){
            int cur;
            if (s.find(i + 1) != s.end()){
                continue;
            }
            else{
                cur = 1;
                int num = i - 1;
                while (s.find(num) != s.end() ){
                    num--;
                    cur++;
                }
                if (cur > res) res = cur;
            }
        }
        return res;
    }
};