#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (c == ')' || c == ']' || c == '}')
            {
                if (st.empty())
                    return false;
                char cc = st.top();
                st.pop();
                if (c == ')' && cc != '(')
                {
                    return false;
                }
                else if (c == ']' && cc != '[')
                {
                    return false;
                }
                else if (c == '}' && cc != '{')
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    // ListNode* head= new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8,new ListNode(9,new ListNode(10,new ListNode(11)))))))))));
    string s = "]";
    cout << "Result:" << s << "-" << Solution().isValid(s) << endl;

    cout << "Result:(]-" << Solution().isValid("(]") << endl;
    cout << "Result:()" << Solution().isValid("()") << endl;
    return 0;

    return 0;
}