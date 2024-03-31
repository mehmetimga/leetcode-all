#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool f(string s, string p, int j, int i, vector<vector<int>> &dp)
    {
        if (dp[j][i] != -1)
            return dp[j][i];

        if (j >= s.size() && i >= p.size())
            return dp[j][i] = true;
        //
        //        if (p[i]=='*' && i+1<p.size() && j==s.size())
        //            return false;

        if (i < p.size() && j == s.size())
        {
            for (int ii = i; ii < p.size(); ii++)
            {
                if (p[ii] != '*')
                {
                    return dp[j][i] = false;
                }
            }
            return dp[j][i] = true;
        }

        if (s[j] == p[i] || p[i] == '?')
            return dp[j][i] = f(s, p, j + 1, i + 1, dp);

        if (p[i] == '*')
            return dp[j][i] = (f(s, p, j + 1, i, dp) || f(s, p, j, i + 1, dp));

        return dp[j][i] = false;
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return f(s, p, 0, 0, dp);
    }
};

int main()
{
    if (Solution().isMatch("aa", "a"))
        cout << "string matched";
    else
        cout << "string did not matched";
    return 0;
}
