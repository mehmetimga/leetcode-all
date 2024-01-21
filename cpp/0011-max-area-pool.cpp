#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = w * h;
            max_area = max(max_area, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum water that can be contained is: " << Solution().maxArea(heights) << endl;

    return 0;
}