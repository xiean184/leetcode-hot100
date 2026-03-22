#include <vector>
using namespace std;

// 暴力算法
// 对每一个位置 i，单独算它上面能接多少水
// 一个位置能不能接水，不取决于它自己有多高，而取决于：
// 它左边最高的柱子
// 它右边最高的柱子
//
//
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int left = 0;
            int right = 0;
            for (int j = 0; j <= i; j++) // 往左扫一遍，找左边最高柱子
                left = max(left, height[j]);
            for (int k = i; k < height.size(); k++) // 往右扫一遍，找右边最高柱子
                right = max(right, height[k]);
            ans += min(right, left) - height[i];
        }
        return ans;
    }
};

// 优化算法
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0; // 定义目前左右两边看到的最高柱子
        int ans = 0;

        while (left < right)
        {
            if (height[left] < height[right]) // 当前左边更矮，那么左边这一格的水量可以先确定
            {
                if (height[left] >= leftMax) // 如果当前左柱子比 leftMax 还高，那就更新左边最高值
                {
                    leftMax = height[left];
                }
                else // 说明当前位置可以接水
                {
                    ans += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};