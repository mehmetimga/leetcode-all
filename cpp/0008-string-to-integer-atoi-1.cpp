#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int nStart = 0;
        int nEnd = 0;
        bool numberStarted = false;
        bool signedAppared = false;
        bool zeroAppared = false;
        string number;
        int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!numberStarted)
            {
                if (s[i] == ' ')
                {
                    if (signedAppared || zeroAppared)
                        return 0;
                    nStart++;
                }
                else if (s[i] == '-' || s[i] == '+' || s[i] == '0')
                {
                    if (signedAppared && s[i] != '0')
                        return 0;

                    if (s[i] == '-' || s[i] == '+')
                    {
                        signedAppared = true;
                        if (zeroAppared)
                            return 0;
                    }
                    if (s[i] == '0')
                    {
                        zeroAppared = true;
                    }

                    if (s[i] == '-')
                        sign = -1;
                    nStart++;
                }
                else if (isdigit(s[i]))
                {
                    numberStarted = true;
                    nEnd++;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (isdigit(s[i]))
                {
                    nEnd++;
                }
                else
                {
                    break;
                }
            }
        }
        number = s.substr(nStart, nEnd);
        for (int j = 0; j < number.length(); j++)
        {
            char c = number[j];
            int val = c - '0';
            // Check overflow and underflow conditions.
            if ((num > INT_MAX / 10) || (num == INT_MAX / 10 && val > INT_MAX % 10))
            {
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + val;
        }

        return sign * num;
    }
};

int main()
{
    cout << "Input(123) MyAtoi:" << Solution().myAtoi("-000000000000001") << endl;
}