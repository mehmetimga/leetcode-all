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
    int right = 0;

    while (right < s.length())
    {
      char r = s[right];
      chars[r]++;

      while (chars[r] > 1)
      {
        char l = s[left];
        chars[l]--;
        left++;
      }

      ret = max(ret, right - left + 1);
      right++;
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