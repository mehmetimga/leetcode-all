#include <iostream>
#include <vector>

using namespace std;

// binary search
int helper(vector<int> s, int num, int first, int last)
{
    if (first > last)
        return -1;

    int mid = first + (last - first) / 2;
    if (s[mid] == num)
    {
        return mid;
    }
    else if (s[mid] >= s[first])
    {
        if (s[first] <= num && s[mid] > num)
            return helper(s, num, first, mid - 1);
        else
            return helper(s, num, mid + 1, last);
    }
    else
    {
        if (s[last] >= num && s[mid] < num)
            return helper(s, num, mid + 1, last);
        else
            return helper(s, num, first, mid - 1);
    }
}

int shiftedArrSearch(const vector<int> &shiftArr, int num)
{
    return helper(shiftArr, num, 0, shiftArr.size() - 1);
}

int main()
{

    vector<int> a = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    cout << "location:" << shiftedArrSearch(a, 8);
    return 0;
}