#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int max = -1;
    string ret = "";
    for (int i = 0; i < s.size(); i++)
    {
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right])
      {
        left--;
        right++;
      }

      if (max < right - left - 1)
      {
        max = right - left - 1;
        ret = s.substr(left + 1, max);
      }

      left = i;
      right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right])
      {
        left--;
        right++;
      }

      if (max < right - left - 1)
      {
        ≥ max = right - left - 1;
        ret = s.substr(left + 1, max);
      }
    }
    return ret;
  }
};

int main()
{

  cout << "result:" << Solution().longestPalindrome("babad") << endl;
  cout << "result:" << Solution().longestPalindrome("cbbd") << endl;
}