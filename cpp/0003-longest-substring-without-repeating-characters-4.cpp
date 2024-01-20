#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> m;
    int maxlen = 0;
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
      auto it = m.find(s[i]);
      if (it != m.end() && len >= i - it->second)
      {
        len = i - it->second;
      }
      else
      {
        len++;
      }
      m[s[i]] = i;
      maxlen = max(maxlen, len);
    }

    return maxlen;
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