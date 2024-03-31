#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums1.size())
        {
            findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = nums1.size();

        while (low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = (nums1.size() + nums2.size() + 1) / 2 - partitionX;

            int Aleft = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            int Aright = partitionX == nums1.size() ? INT_MAX : nums1[partitionX];
            int Bleft = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
            int Bright = partitionY == nums2.size() ? INT_MAX : nums2[partitionY];

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if ((nums1.size() + nums2.size()) % 2 == 0)
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2;
                else
                    return max(Aleft, Bleft);
            }
            else if (Aleft < Bright)
            {
                low = partitionX + 1;
            }
            else
            {
                high = partitionX - 1;
            }
        }

        return 0.0;
    }
};

int main()
{
    vector<int> v11 = {1, 2, 5, 6};             // 4
    vector<int> v22 = {3, 4, 8, 9, 12, 14, 15}; // 7
    cout << "result:" << Solution().findMedianSortedArrays(v11, v22) << endl;
}