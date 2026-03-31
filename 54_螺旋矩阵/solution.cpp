#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();    // 行数
        int n = matrix[0].size(); // 列数

        vector<int> ans;
        int top = 0, bottom = m - 1; // 第一行和最后一行 边界
        int left = 0, right = n - 1; // 第一列和最后一列 边界

        while (top <= bottom && left <= right) // 避免中心值被连续访问两次
        {
            // 1. 从左到右
            for (int j = left; j <= right; j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // 2. 从上到下
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. 从右到左
            if (top <= bottom) // 必须先判断 left <= right，否则可能已经没有左边这一列了
            {
                for (int j = right; j >= left; j--)
                {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // 4. 从下到上
            if (left <= right) // 必须先判断 left <= right，否则可能已经没有左边这一列了
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};