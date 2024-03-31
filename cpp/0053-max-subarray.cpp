class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = 0;
        int max_store = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            max_sum = max_sum + nums[i];

            if (max_store < max_sum)
                max_store = max_sum;

            if (max_sum < 0)
                max_sum = 0;
        }
        return max_store;
    }
};