#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cur = nums[0]; // 以当前位置结尾的最大子数组和
        int ans = nums[0]; // 到目前为止，全局最大的子数组和
        for (int i = 1; i < nums.size(); i++)
        {
            cur = max(nums[i], cur + nums[i]);
            ans = max(cur, ans);
        }
        return ans;
    }
};