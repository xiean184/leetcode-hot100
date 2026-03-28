#include <vector>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && (nums[i] <= nums.size()) && nums[nums[i] - 1] != nums[i]) // 这个语句执行顺序是从左往右，要先判断数值边界
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};