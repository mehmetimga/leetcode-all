#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sp = 0;
        int pp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[sp] == p[pp] || p[pp] == '.')
            {
                if (pp == p.length() || sp == s.length())
                    return true;
                sp++;
                pp++;
                continue;
            }
            else if (p[pp] == '*')
            {
                pp++;
                while (s[sp] != p[pp])
                {
                    sp++;
                }
                if (pp == p.length() || sp == s.length())
                    return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
int main()
{
    cout << "Input(123) isPalindrome:" << Solution().isMatch("abcddddeffgd", "a..d*f*d") << endl;
    cout << "Input(123) isPalindrome:" << Solution().isMatch("avcddddeffgc", "a..d*f*d") << endl;
}