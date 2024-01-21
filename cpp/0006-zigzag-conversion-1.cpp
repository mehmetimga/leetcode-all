#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
            return s;
        string ret;
        int mode_base = numRows + (numRows - 2);
        int i = 0;
        int j = 0;
        int left = 0;
        int right = mode_base;

        while (j < s.length())
        {
            int base = i * mode_base;
            if (base > s.length())
            {
                i = 0;
                base = i * mode_base;
                left++;
                right--;
            }
            i++;
            if (base + left < s.length())
            {
                ret += s[base + left];
                j++;
            }
            if (left != right && left != 0)
            {
                if (base + right < s.length())
                {
                    ret += s[base + right];
                    j++;
                }
            }
        }
        return ret;
    }
};

int main()
{
    cout << "Input(AB):" << Solution().convert("AB", 3) << endl;
    cout << "input(PAYPALISHIRING):" << endl;

    cout << "result(PAHNAPLSIIGYIR):";
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;

    cout << "result(PINALSIGYAHRPI):";
    cout << Solution().convert("PAYPALISHIRING", 4) << endl;
}