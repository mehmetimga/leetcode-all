class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int i = 0;
        int j = 0;
        while (i + 1 < matrix.size() && matrix[i + 1][j] <= target)
        {
            i++;
        }

        while (j + 1 < matrix[0].size() && matrix[i][j] < target)
        {
            j++;
        }

        if (matrix[i][j] == target)
            return true;
        return false;
    }
};