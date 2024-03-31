#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(2, -1);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] == target && nums[mid] > nums[mid - 1] || mid == 0 && nums[mid] == target)
            {
                result[0] = mid;
                left = mid;
                break;
            }
            else if (target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        right = nums.size() - 1;
        left = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid < nums.size() - 1 && nums[mid] == target && nums[mid] < nums[mid + 1] || mid == nums.size() - 1 && nums[mid] == target)
            {
                result[1] = mid;
                break;
            }
            else if (target >= nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> a{
        2,
    };
    vector<int> r = Solution().searchRange(a, 2);

    for (auto k : r)
    {
        cout << k << ",";
    }

    return 0;
}
