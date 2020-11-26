//leetcode 1. https://leetcode-cn.com/problems/container-with-most-water/

//如果我们保持左指针(小的那个指针)的位置不变，那么无论右指针在哪里，这个容器的容量都不会超过min(x,y)∗t了。
//这个左指针对应的数就不能作为容器的边界了，我们就可以丢弃这个位置，将左指针向右移动一个位置，此时新的左指针于原先的右指针之间的左右位置，才可能会作为容器的边界。

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 1) return 0;
        if (height.size() == 2) return min(height[0], height[1]);
        int left = 0, right = height.size() - 1;
        int maxv = 0;
        while (left < right){
            maxv = max(  min(height[left], height[right]) * (right - left), maxv);
            if (height[left] < height[right]){
                left++;
            } else right--;
        }
        return maxv;
    }
};