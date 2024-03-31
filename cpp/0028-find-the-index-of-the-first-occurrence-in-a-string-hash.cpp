#include <iostream>
#include <vector>

using namespace std;
int search(string source, string pattern)
{
    int slen = source.length();
    int plen = pattern.length();

    int b = 256;
    int q = INT_MAX;

    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < plen - 1; i++)
        h = (h * b) % q;

    int t = 0; // hash for text
    int p = 0; // hash for pattern
    for (int i = 0; i < plen; i++)
    {
        t = (b * t + source[i]) % q;
        p = (b * p + pattern[i]) % q;
    }

    for (int i = 0; i <= slen - plen; i++)
    {
        if (t == p)
        {
            bool found = true;
            for (int j = 0; j < plen; j++)
            {
                if (source[j + i] != pattern[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }

        // remove fist and add last char to rolling hash algorith.
        t = (b * (t - source[i] * h) + source[i + plen]) % q;

        if (t < 0)
            t += q;
    }

    return -1;
}

int main()
{
    cout << search("abdabcdefabcdxabd", "abcdx");
    return 0;
}