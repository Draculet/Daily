
//https://blog.csdn.net/ggdhs/article/details/90713154 题解参考

//dp公式: if(s[i] == s[j]) dp[i][j] = dp[i-1][j-1]
//        else dp[i][j] = 0
//dp的含义是由s1的前i个字符和s2的前j个字符组成的两个串 的 以s1[i] s2[j]字符结尾的最长子串的长度（特别注意该最长子串是必须以s1[i]，也即s2[j]结尾）


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int max;
        vector<vector<int>> dp(text1.size() + 1);
        for (int i = 0; i <= text1.size(); i++)
            dp[i].resize(text2.size() + 1);
        for (int i = 1; i <= text1.size(); i++){
            for (int j = 1; j <= text2.size(); j++){
                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > max) max = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }
        return max;
    }
};