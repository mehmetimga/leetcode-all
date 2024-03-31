class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = m - 1;
        int l = n - 1;
        int i = m + n - 1;
        while (k >= 0 && l >= 0)
        {
            if (nums1[k] < nums2[l])
            {
                nums1[i--] = nums2[l--];
            }
            else
            {
                nums1[i--] = nums1[k--];
            }
        }
        while (l >= 0)
        {
            nums1[i--] = nums2[l--];
        }
    }
};