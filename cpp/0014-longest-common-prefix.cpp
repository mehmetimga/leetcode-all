#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret;
        bool loop = true;
        if (strs.size() == 1 || strs[0].length() == 0)
            return strs[0];
        int j = 0;
        do
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++)
            {
                if (c != strs[i][j] || j >= strs[i].length())
                {
                    loop = false;
                    break;
                }
            }
            j++;
            if (loop)
            {
                ret += c;
            }
        } while (loop && j < strs[0].length());
        return ret;
    }
};

int main()
{
    vector<string> strs = {"flower", "flower", "flower"};
    cout << "Roman(1994): " << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}