//leetcode 72. https://leetcode-cn.com/problems/edit-distance/
/*
以 A = horse，B = ros 作为例子。

在单词 A 中插入一个字符：如果我们知道 horse 到 ro 的编辑距离为 a，那么显然 horse 到 ros 的编辑距离不会超过 a + 1。这是因为我们可以在 a 次操作后将 horse 和 ro 变为相同的字符串，只需要额外的 1 次操作，在单词 A 的末尾添加字符 s，就能在 a + 1 次操作后将 horse 和 ro 变为相同的字符串；

在单词 B 中插入一个字符：如果我们知道 hors 到 ros 的编辑距离为 b，那么显然 horse 到 ros 的编辑距离不会超过 b + 1，原因同上；

修改单词 A 的一个字符：如果我们知道 hors 到 ro 的编辑距离为 c，那么显然 horse 到 ros 的编辑距离不会超过 c + 1 (当两个末尾字符相同时为c)，原因同上。

那么从 horse 变成 ros 的编辑距离应该为 min(a + 1, b + 1, c + 1) 或 min(a + 1, b + 1, c)。

*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1);
        for (int i = 0; i <= word1.size(); i++)
            dp[i].resize(word2.size() + 1);

        for (int i = 0; i <= word1.size(); i++){
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++){
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++){
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = min3( dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] );
                else
                    dp[i][j] = min3( dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1);
            }
        }

        return dp[word1.size()][word2.size()];
    }

    int min3(int a, int b, int c){
        int m = 0x7fffffff;
        m = min(a, m);
        m = min(b, m);
        m = min(c, m);
        return m;
    }
};