#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long res = 0;
        int max_cnt = 0;
        int max_n = *max_element(nums.begin(), nums.end());
        int l = 0;
        for (int i : nums)
        {
            if (i == max_n)
                max_cnt++;

            while (max_cnt == k)
            {
                if (nums[l] == max_n)
                {
                    max_cnt -= 1;
                }
                l++;
            }
            res += l;
        }

        return res;
    }
};

int main()
{
    vector<int> a{1, 3, 2, 3, 3};
    int r = Solution().countSubarrays(a, 3);
    cout << "Result:" << r << endl;

    return 0;
}