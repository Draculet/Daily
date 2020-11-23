//leetcode 398 https://leetcode-cn.com/problems/random-pick-index/

//解法仍是蓄水池法,要注意在arrs[i] == target成立的数组元素中进行随机抽取
//count可以理解为蓄水池外待抽取元素和蓄水池内的元素个数
//当蓄水池内还没有元素时,count为1,rand()%count抽取的恒为0,将i对应的元素加入水池

//在处理容量为M的水池时,一般从M下标开始,此时的count为M+2,因为水池内元素已定,第一个元素需要进行包含自己在内的抽样
//需要遵守的原则就是,进行rand()抽样时,需要包含蓄水池内元素,自身,以及符合条件需要进行抽样的先前所有元素.

class Solution {
public:
    Solution(vector<int>& nums) {
        arrs = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int pool = 0;
        for (int i = 0; i < arrs.size(); i++){
            if (arrs[i] == target){
                count++;
                int r = rand() % count;
                if (r == 0)
                    pool = i;
            }
        }
        return pool;
    }
    vector<int> arrs;
};
