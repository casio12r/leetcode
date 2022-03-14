/*
Time complexity (best and worst): O(log(n)),O(log(n))
Space complexity: O(1),O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* 
    f(n) = f(n-1) + f(n-2)
    [f(n) f(n-1)]^T = [1 1; 1 0] [f(n-1) f(n-2)]^T
    [f(n) f(n-1)]^T = [1 1; 1 0]^(n-2) [f(2) f(1)]^T, n>=3
    */
    int climbStairs(int n)
    {
        vector<vector<int>> matrix = {{1, 1}, {1, 0}};
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        else
        {
            vector<vector<int>> result = power(matrix, n - 2);
            return result[0][0] * 2 + result[0][1];
        }
    }
    vector<vector<int>> power(vector<vector<int>> matrix, int n)
    {
        vector<vector<int>> temp = {{1, 0}, {0, 1}};
        while (n > 1)
        {
            if (n % 2 == 1)
            {
                n -= 1;
                temp = multiply(matrix, temp);
            }
            else
            {
                n = n / 2;
                matrix = multiply(matrix, matrix);
            }
        }
        matrix = multiply(matrix, temp);
        return matrix;
    }

    vector<vector<int>> multiply(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
    {
        int row = matrix1.size();
        int col = matrix2[0].size();
        int mid = matrix1[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                int sum = 0;
                for (int k = 0; k < mid; k++)
                {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                temp.push_back(sum);
            }
            result.push_back(temp);
        }
        return result;
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
//             vector<int> num_method(2);
//             num_method[0] = 1;
//             num_method[1] = 2;
//             for (int i = 2; i < n; ++i)
//             {
//                 int current = num_method[0] + num_method[1];
//                 num_method[0] = num_method[1];
//                 num_method[1] = current;
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
    int result = solution.climbStairs(5);
    cout << result << endl;
    return 0;
}