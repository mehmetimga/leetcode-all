#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isMatch(const string &text, const string &pattern)
    {
        if (pattern.empty())
            return text.empty();

        // First character match or pattern has '.' at this position
        bool first_match = (!text.empty() &&
                            (pattern[0] == text[0] || pattern[0] == '.'));

        // If the pattern has '*' in the second position
        if (pattern.size() >= 2 && pattern[1] == '*')
        {
            // Two possibilities:
            // 1. '*' represents zero of the preceding element
            // 2. First character of the string matches and move to the next character in the string
            return (isMatch(text, pattern.substr(2)) ||
                    (first_match && isMatch(text.substr(1), pattern)));
        }
        else
        {
            // Move to the next character in both the string and the pattern
            return first_match && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};
int main()
{
    cout << "Input(123) isPalindrome:" << Solution().isMatch("abcddddeffgd", "a..d*f*d") << endl;
    cout << "Input(123) isPalindrome:" << Solution().isMatch("avcddddeffgc", "a..d*f*d") << endl;
}