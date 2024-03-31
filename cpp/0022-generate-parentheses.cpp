#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> arr;
    void recursive(string str, int n, int openN, int closedN)
    {
        if (openN == n && closedN == n)
        {
            arr.push_back(str);
            return;
        }
        if (openN < n)
        {
            str.append("(");
            recursive(str, n, openN + 1, closedN);
            str = str.substr(0, str.length() - 1);
        }
        if (openN > closedN)
        {
            str.append(")");
            recursive(str, n, openN, closedN + 1);
            str = str.substr(0, str.length() - 1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        recursive("", n, 0, 0);
        return arr;
    }
};

int main()
{
    int n = 3;
    vector<string> str = Solution().generateParenthesis(n);
    for (auto item : str)
    {
        cout << item << endl;
    }
    return 0;
}