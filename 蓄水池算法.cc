#include <vector>
//382.蓄水池算法 https://leetcode-cn.com/problems/linked-list-random-node/
//随机在数组中找出M个数，要求选出概率相同
//分布式蓄水池(未解决) 

//leetcode 382解法 M=1的蓄水池
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getRandom() {
        int count = 1;
        int val = h->val;
        ListNode *ptr = h->next;
        while (ptr){
            if (rand() % (count + 1) == 0){
                val = ptr->val;
            }
            ptr = ptr->next;
            count++;
        }
        return val;
    }
};

//拓展到M的蓄水池解法
vector<int> getReservoir(vector<int> arr, int M){
    //arr为输入数据, M为公平选出的M个数
    int len = arr.size();
    vector<int> res;
    for (int i = 0; i < M; i++){
        res.push_back(arr[i]);//容量为M的蓄水池
    }
    //蓄水池外的第一个元素开始,进行包含该元素的随机抽取，抽取到蓄水池内元素的概率为M/i, 即该元素被换入蓄水池的概率
    //而要保证该元素最终被保留，还需要后面的每轮抽取不被抽取到，不被抽取到概率为i-1/i; 后面每一轮的不被抽取概率约分后得到M / arr.size()
    for (int i = M; i < arr.size(); i++){
        int r = rand() % (i + 1);
        if (r < M) res[r] = arr[i];
    }
    //每个选出的概率都是 M / arr.size();
    return res;
}


int main(void){
    
}