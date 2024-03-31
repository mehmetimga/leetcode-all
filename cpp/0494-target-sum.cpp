class Solution
{
public:
    int bfs(vector<int> &nums, unordered_map<string, int> m, int target, int i, int total)
    {
        if (i == nums.size())
        {
            if (total == target)
                return 1;
            else
                return 0;
        }

        string str;
        str = to_string(i) + "-" + to_string(total);
        if (m.count(str) > 0)
            return m[str];

        m[str] = bfs(nums, m, target, i + 1, total - nums[i]) + bfs(nums, m, target, i + 1, total + nums[i]);
        return m[str];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<string, int> m;
        return bfs(nums, m, target, 0, 0);
    }
};