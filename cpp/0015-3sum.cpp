#include <iostream>
#include <vector>

// 15. 3Sum
// Medium

// Share
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 1;
        while (left < right - 1)
        {
            if (nums[left] + nums[mid] + nums[right] == 0)
            {
                vector<int> v = {nums[left], nums[mid], nums[right]};
                res.push_back(v);
                do
                {
                    mid++;
                } while (nums[mid] == nums[mid - 1] && mid < right);
            }
            else if (nums[left] + nums[mid] + nums[right] < 0)
            {
                mid++;
            }
            else if (nums[left] + nums[mid] + nums[right] > 0)
            {
                right--;
            }
            if (mid == right)
            {
                do
                {
                    left++;
                } while (nums[left] == nums[left - 1] && left < right - 1);
                mid = left + 1;
                right = nums.size() - 1;
            }
        }
        return res;
    }
};

int main()
{
    // vector<int> nums = {0,0,0,0,0};
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = Solution().threeSum(nums);
    for (auto item : result)
    {
        for (int i : item)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    return 0;
}