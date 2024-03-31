class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        bool found;
        for (int i = 0; i < haystack.length(); i++)
        {
            int j = 0;
            for (j = 0; j < needle.length(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == needle.length())
                return i;
        }
        return -1;
    }
};