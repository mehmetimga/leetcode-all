#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;

        if (x % 10 == 0 || x < 0)
            return false;

        int reversed = 0;
        while (reversed < x)
        {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }
        return reversed == x || x == reversed / 10;
    }
};

int main()
{
    cout << "Input(123) MyAtoi:" << Solution().isPalindrome(123454321) << endl;
}