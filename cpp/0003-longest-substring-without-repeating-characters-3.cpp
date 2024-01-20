#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int ret = 0;
    unordered_map<char, int> chars;
    int left = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (chars.find(s[i]) != chars.end())
      {
        left = chars[s[i]] + 1;
      }
      chars[s[i]] = i;
      ret = max(ret, i - left + 1);
    }
    return ret;
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