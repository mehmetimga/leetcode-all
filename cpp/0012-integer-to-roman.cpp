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
    string intToRoman(int num)
    {
        string ret;
        while (num >= 1000)
        {
            num -= 1000;
            ret += "M";
        }
        if (num >= 900)
        {
            num -= 900;
            ret += "CM";
        }
        if (num >= 500)
        {
            num -= 500;
            ret += "D";
        }

        if (num >= 400)
        {
            num -= 400;
            ret += "CD";
        }
        while (num >= 100)
        {
            num -= 100;
            ret += "C";
        }
        if (num >= 90)
        {
            num -= 90;
            ret += "XC";
        }

        if (num >= 50)
        {
            num -= 50;
            ret += "L";
        }

        if (num >= 40)
        {
            num -= 40;
            ret += "XL";
        }

        while (num >= 10)
        {
            num -= 10;
            ret += "X";
        }
        if (num >= 9)
        {
            num -= 9;
            ret += "IX";
        }
        if (num >= 5)
        {
            num -= 5;
            ret += "V";
        }

        if (num >= 4)
        {
            num -= 4;
            ret += "IV";
        }

        while (num >= 1)
        {
            num -= 1;
            ret += "I";
        }
        return ret;
    }
};
int main()
{
    cout << "Roman: " << Solution().intToRoman(200) << endl;
    return 0;
}