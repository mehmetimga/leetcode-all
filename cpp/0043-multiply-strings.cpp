#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int N = num1.size() + num2.size();
        string result(N, '0');
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        int carry = 0;
        for (int i = 0; i < num1.size(); i++)
        {
            int n1 = num1[i] - '0';
            for (int j = 0; j < num2.size(); j++)
            {
                int n2 = num2[j] - '0';
                int numZeros = i + j;
                carry = result[numZeros] - '0';
                result[numZeros] = '0' + (n1 * n2 + carry) % 10;
                result[numZeros + 1] += (n1 * n2 + carry) / 10;
            }
        }
        if (result.back() == '0')
        {
            result.pop_back();
        }
        reverse(begin(result), end(result));
        return result;
    }
};

int main()
{
    string num1 = "123", num2 = "456";
    string r = Solution().multiply(num1, num2);

    cout << endl
         << "r=" << r << endl;
    cout << "result=" << 123 * 456 << endl;

    return 0;
}
