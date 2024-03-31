class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int XOR = 0;
        for (int i = 0; i < nums.size() + 1; i++)
        {
            XOR ^= i;
            if (i != nums.size())
                XOR ^= nums[i];
        }
        return XOR;
    }
};
