#include <vector>
using namespace std;

// 额外数组法
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(n); // 开个数组暂存中间值
        k %= n;              // 注意边界不要爆炸
        for (int i = 0; i < n; i++)
        {
            temp[(i + k) % n] = nums[i]; // 右移，注意逻辑不要写成左移
        }

        nums = temp;
    }
};

// 最优：翻转法
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n; // 注意边界
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k); // 翻转前 k 个元素
        reverse(nums.begin() + k, nums.end());   // 翻转后面的，把后半段也恢复成正确顺序
    }
};