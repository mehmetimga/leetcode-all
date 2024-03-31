#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &a, vector<bool> &bits)
    {
        if (a.size() == nums.size())
        {
            res.push_back(a);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (bits[i] || (i > 0 && nums[i] == nums[i - 1] && !bits[i - 1]))
                continue;

            bits[i] = true;

            a.push_back(nums[i]);
            bfs(res, nums, a, bits);
            a.pop_back();

            bits[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> a;
        vector<bool> vis(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtrack(res, nums, a, vis);
        return res;
    }
};

int main()
{
    vector<int> a{1, 1, 2};
    vector<vector<int>> r = Solution().permuteUnique(a);
    for (auto i : r)
    {
        cout << "[";
        for (auto k : i)
        {
            cout << k << ",";
        }
        cout << ']' << endl;
    }
    return 0;
}
