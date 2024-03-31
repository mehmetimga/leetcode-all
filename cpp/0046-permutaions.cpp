#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &item, vector<bool> &vis)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (item.size() == nums.size())
            {
                res.push_back(item);
                return;
            }
            if (vis[i])
                continue;

            vis[i] = true;
            item.push_back(nums[i]);
            helper(res, nums, item, vis);
            item.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> item;
        vector<bool> vis(nums.size(), false);
        backtrack(res, nums, item, vis);
        return res;
    }
};

int main()
{
    vector<int> a{1, 1, 2};
    vector<vector<int>> r = Solution().permute(a);
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
