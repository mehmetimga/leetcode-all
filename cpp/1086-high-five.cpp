#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        sort(items.begin(), items.end(), [](auto a, auto b)
             { return a[0] < b[0]; });
        vector<vector<int>> result;
        int k = 0;
        int a = 0;
        int j = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (i == items.size() - 1 || items[i][0] != items[i + 1][0])
            {
                if (j < 5)
                    a += items[i][1];

                vector<int> r(2, 0);

                r[0] = items[i][0];
                r[1] = a / 5;
                result.push_back(r);
                j = 0;
                a = 0;
            }
            else
            {
                if (j < 5)
                    a += items[i][1];
                j++;
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> s = {{1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}};
    vector<vector<int>> r = Solution().highFive(s);
    return 0;
}
