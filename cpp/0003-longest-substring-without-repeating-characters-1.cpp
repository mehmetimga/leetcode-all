#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    string ret = "";
    if (s.length() <= 1)
      return s.length();

    for (int i = 0; i < s.length(); i++)
    {
      unordered_set<char> cset;
      cset.insert(s[i]);
      for (int j = i + 1; j < s.length(); j++)
      {
        if (cset.find(s[j]) != cset.end())
        {
          if (ret.length() < j - i)
          {
            ret = s.substr(i, j - i);
          }
          break;
        }
        else if (j == s.length() - 1)
        {
          if (ret.length() < j - i + 1)
          {
            ret = s.substr(i, j - i + 1);
          }
          break;
        }
        else
        {
          cset.insert(s[j]);
        }
      }
    }
    return ret.length();
  }
};

int main()
{
  cout << "result:" << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
  cout << "result:" << Solution().lengthOfLongestSubstring("bbbbb") << endl;
  cout << "result:" << Solution().lengthOfLongestSubstring("pwwkew") << endl;
  cout << "result:" << Solution().lengthOfLongestSubstring("au") << endl;
  cout << "result:" << Solution().lengthOfLongestSubstring(" ") << endl;
}