#include <vector>
using namespace std;

// 暴力算法，超时
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int temp = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                temp *= nums[j];
            }
            ans[i] = temp;
        }
        return ans;
    }
};

// 优化算法
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++) // 算左积
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for (int i = n - 1; i >= 0; i--) // 算右积
        {
            ans[i] *= temp;
            temp *= nums[i];
        }
        return ans;
    }
};