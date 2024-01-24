#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<vector<int>> ret;

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int left = j + 1;
                int right = n - 1;
                int cummulative = nums[i] + nums[j];
                while (left < right)
                {
                    int total = cummulative + nums[left] + nums[right];
                    if (total == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ret.push_back(temp);
                        // Processing the duplicates of number 3
                        while (left < right && nums[left] == temp[2])
                            ++left;

                        // Processing the duplicates of number 4
                        while (left < right && nums[right] == temp[3])
                            --right;
                    }
                    else if (total < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = Solution().fourSum(nums, 0);
    for (auto i : ret)
    {
        cout << "[";

        for (auto k : i)
        {
            cout << k << ",";
        }
        cout << "], ";
    }

    cout << endl
         << "--------" << endl;
    nums = {2, 2, 2, 2, 2};
    ret = Solution().fourSum(nums, 8);
    for (auto i : ret)
    {
        cout << "[";

        for (auto k : i)
        {
            cout << k << ",";
        }
        cout << "], ";
    }

    cout << endl
         << "--------" << endl;
    nums = {1000000000, 1000000000, 1000000000, 1000000000};
    ret = Solution().fourSum(nums, 0);
    for (auto i : ret)
    {
        cout << "[";

        for (auto k : i)
        {
            cout << k << ",";
        }
        cout << "], ";
    }

    return 0;
}