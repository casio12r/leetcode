/*
Time complexity (best and worst): O(n),O(n)
Space complexity: O(1),O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            vector<int> num_method(2);
            num_method[0] = 1;
            num_method[1] = 2;
            for (int i = 2; i < n; ++i)
            {
                int current = num_method[0] + num_method[1];
                num_method[0] = num_method[1];
                num_method[1] = current;               
            }
            return num_method.back();
        }
    }
};

// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n == 1)
//         {
//             return 1;
//         }
//         else if (n == 2)
//         {
//             return 2;
//         }
//         else
//         {
//             vector<int> num_method(n);
//             num_method[0] = 1;
//             num_method[1] = 2;
//             for (int i = 2; i < n; ++i)
//             {
//                 num_method[i] = num_method[i - 1] + num_method[i - 2];
//             }
//             return num_method.back();
//         }
//     }
// };

// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n == 1)
//         {
//             return 1;
//         }
//         else if (n == 2)
//         {
//             return 2;
//         }
//         else
//         {
//             return climbStairs(n - 1) + climbStairs(n - 2);
//         }
//     }
// };

int main()
{
    Solution solution;
    int result = solution.climbStairs(3);
    cout << result << endl;
    return 0;
}