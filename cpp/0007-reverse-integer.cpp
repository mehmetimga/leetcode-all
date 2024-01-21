#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        int y = abs(x);
        int sign = x / y;
        int ret = 0;
        do
        {
            int n = y % 10;
            if (ret > INT_MAX / 10)
                return 0;
            ret = ret * 10 + n;

            y = y / 10;
        } while (y > 0);

        return sign * ret;
    }
};

int main()
{
    cout << "Input(123) reverse:" << Solution().reverse(123) << endl;
}