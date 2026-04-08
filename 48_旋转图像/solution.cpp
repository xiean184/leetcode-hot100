#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(); // 行数/列数，方阵

        // 1. 先转置
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. 再把每一行左右翻转
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};