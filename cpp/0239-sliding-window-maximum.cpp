#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> d;
        for (int i = 0; i < nums.size(); i++)
        {

            // remove window begining if greater than 3
            if (!d.empty() && i - k == d.front())
                d.pop_front();

            // remove all left less than current cell value
            while (!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();

            // add left as min to back since we removed all smaller values from back
            d.push_back(i);

            // add front value as max for the windows after window size == k
            if (i >= k - 1)
                result.push_back(nums[d.front()]);
        }
        return result;
    }
};

int main()
{

    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> r = Solution().maxSlidingWindow(a, 3);
    for (auto i : r)
        cout << i << ", ";
    return 0;
}