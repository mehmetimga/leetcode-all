#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int total = nums1.size() + nums2.size();
    int p1 = 0;
    int p2 = 0;

    int curr = 0;
    int prev = 0;

    for (int i = 0; i <= total / 2; i++)
    {
      prev = curr;
      if (p2 < nums2.size() && (p1 >= nums1.size() || nums1[p1] > nums2[p2]))
      {
        curr = nums2[p2];
        p2++;
      }
      else
      {
        curr = nums1[p1];
        p1++;
      }
    }
    if (total % 2 == 1)
    {
      return curr;
    }
    double ret = ((double)curr + (double)prev) / 2;
    return ret;
  }
};

int main()
{
  vector<int> v11 = {1, 2};
  vector<int> v22 = {3, 4};
  cout << "result:" << Solution().findMedianSortedArrays(v11, v22) << endl;
}