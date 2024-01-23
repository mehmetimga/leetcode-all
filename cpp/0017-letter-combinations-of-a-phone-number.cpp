#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 0	none (on some telephones, "OPERATOR" or "OPER")
// 1	none (on some older telephones, QZ)
// 2	ABC
// 3	DEF
// 4	GHI
// 5	JKL
// 6	MNO (on some older telephones, MN)
// 7	PQRS (on older telephones, PRS)
// 8	TUV
// 9	WXYZ (on older telephones, WXY)

class Solution
{
public:
    unordered_map<int, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> dm;
    vector<string> ret1;

    void permutations(int index, char c, string str)
    {
        for (char c : dm[index])
        {
            if (index == dm.size() - 1)
            {
                string str1 = str;
                str1 += c;
                ret1.push_back(str1);
            }
            else
            {
                string str1 = str + c;
                permutations(index + 1, c, str1);
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return ret1;
        }
        for (char c : digits)
        {
            dm.push_back(m[c]);
        }
        if (digits.size() == 1)
        {
            for (char c : dm[0])
            {
                string str1;
                str1 += c;
                ret1.push_back(str1);
            }
            return ret1;
        }
        for (char c : dm[0])
        {
            string str;
            str += c;
            permutations(1, c, str);
        }

        return ret1;
    }
};

int main()
{
    auto result = Solution().letterCombinations("234");
    for (auto item : result)
    {
        cout << "result:" << item << endl;
    }

    return 0;
}