class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        auto total = reduce(nums.begin(), nums.end());

        vector<int> dp(2 * total + 1, 0);
        dp[nums[0] + total] = 1;
        dp[-nums[0] + total] += 1;
        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> next(2 * total + 1);
            for (int sum = -total; sum <= total; sum++)
            {
                if (dp[sum + total] > 0)
                {
                    next[sum + nums[i] + total] += dp[sum + total];
                    next[sum - nums[i] + total] += dp[sum + total];
                }
            }
            dp = next;
        }

        return abs(target) > total ? 0 : dp[target + total];
    }
};