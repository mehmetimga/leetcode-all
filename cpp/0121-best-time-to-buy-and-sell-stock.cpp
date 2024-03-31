class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minprice > prices[i])
                minprice = prices[i];
            else if (maxprofit < prices[i] - minprice)
            {
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }
};

// O(n)
//  brutforce==
//  2 for loop and calculate each profit and return max profit.