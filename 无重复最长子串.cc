//leetcode 3.  https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
//采用滑动窗口,以左侧窗口为基，右侧窗口右移。 当字符串出现重复时,左侧窗口右移

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        char set_[128] = {0};

        int max = 0;
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            while (j < s.size()){
                if (set_[s[j]] == 0){
                    set_[s[j]] = 1;
                    cnt++;
                    j++;
                    if (cnt > max) max = cnt;
                }
                else
                    break;
            }
            if (j == s.size()) return max;
            set_[s[i]] = 0;
            cnt--;
        }
        return max;
    }
};