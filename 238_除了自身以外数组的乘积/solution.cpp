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
