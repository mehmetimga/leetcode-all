class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;
        int l = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k++] = nums[i];
                l = 0;
            }
            else if (nums[i] == nums[i - 1] && l == 0)
            {
                nums[k++] = nums[i];
                l++;
            }
        }
        return k;
    }
};