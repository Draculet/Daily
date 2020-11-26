//leetcode 1143. https://leetcode-cn.com/problems/longest-common-subsequence/
//https://blog.csdn.net/ggdhs/article/details/90713154 题解参考

//dp公式: if(s[i] == s[j]) dp[i][j] = dp[i-1][j-1]
//        else dp[i][j] = max(dp[i-1][j], dp[i][j-1])

//dp[i][j]的含义是前i个字符组成的字符串和前j个字符组成的字符串的最长公共子序列长度

//还原时,从得到的dp矩阵右下开始，如果s[i]==s[j],往dp[i-1][j-1]方向移动，否则往dp[i-1][j]和dp[i][j-1]中大的方向前进;
//如果dp[i-1][j]==dp[i][j-1]则选择一个方向，并在以后再次遇到这种情况时以相同方向移动

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1);
        for (int i = 0; i <= text1.size(); i++)
            dp[i].resize(text2.size() + 1);
        for (int i = 1; i <= text1.size(); i++){
            for (int j = 1; j <= text2.size(); j++){
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};