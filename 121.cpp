/*
Time complexity (best and worst): O(n),O(n)
Space complexity: O(1),O(1)
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int current_buy = numeric_limits<int>::max();
        int current_return = 0;
        for (auto sale : prices)
        {
            if (sale < current_buy)
            {
                current_buy = sale;
            }
            else if (sale - current_buy > current_return)
            {
                current_return = sale - current_buy;
            }
        }
        return current_return;
    }
};

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int current_buy = numeric_limits<int>::max();
//         int current_return = 0;
//         for (auto buy = prices.begin(); buy != prices.end(); buy++)
//         {
//             if (*buy >= current_buy)
//             {
//                 continue;
//             }
//             else
//             {
//                 for (auto sale = buy + 1; sale != prices.end(); sale++)
//                 {
//                     int difference = *sale - *buy;
//                     if (difference > current_return)
//                     {
//                         current_return = difference;
//                         current_buy = *buy;
//                     }
//                 }
//             }
//         }
//         return current_return;
//     }
// };

int main()
{
    Solution solution;
    vector<int> prices = {7, 6, 4, 3, 1};
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    cout << result << endl;
    return 0;
}