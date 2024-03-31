class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int goals = nums.size() - 1;
        for (int k = nums.size() - 1; k >= 0; k--)
        {
            if (k + nums[k] >= goals)
                goals = k;
        }
        return goals == 0;
    }
};