#include <iostream>
#include <vector>

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ret = 0;
        int i = 0;
        int l = s.length();

        while (i < l && s[i] == 'M')
        {
            i++;
            ret += 1000;
        }

        if (i < l - 1 && s[i] == 'C' && s[i + 1] == 'M')
        {
            i += 2;
            ret += 900;
        }
        if (i < l && s[i] == 'D')
        {
            i++;
            ret += 500;
        }

        if (i < l - 1 && s[i] == 'C' && s[i + 1] == 'D')
        {
            i += 2;
            ret += 400;
        }

        while (i < l && s[i] == 'C')
        {
            i++;
            ret += 100;
        }

        if (i < l - 1 && s[i] == 'X' && s[i + 1] == 'C')
        {
            i += 2;
            ret += 90;
        }

        if (i < l && s[i] == 'L')
        {
            i++;
            ret += 50;
        }

        if (i < l - 1 && s[i] == 'X' && s[i + 1] == 'L')
        {
            i += 2;
            ret += 40;
        }

        while (i < l && s[i] == 'X')
        {
            i++;
            ret += 10;
        }

        if (i < l - 1 && s[i] == 'I' && s[i + 1] == 'X')
        {
            i += 2;
            ret += 9;
        }

        if (i < l && s[i] == 'V')
        {
            i++;
            ret += 5;
        }

        if (i < l - 1 && s[i] == 'I' && s[i + 1] == 'V')
        {
            i += 2;
            ret += 4;
        }

        while (i < l && s[i] == 'I')
        {
            i++;
            ret += 1;
        }

        return ret;
    }
};
int main()
{
    // s = "MCMXCIV"  M = 1000, CM = 900, XC = 90 and IV = 4.
    cout << "Roman(9): " << Solution().romanToInt("IX") << endl;
    cout << "Roman(1994): " << Solution().romanToInt("MCMXCIV") << endl;
    return 0;
}