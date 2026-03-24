#include <vector>
#include <deque>

using namespace std;
// 双端队列
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // 存储的是下标
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 1. 保持队尾单调：如果新数比队尾大，队尾就没用了
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // 2. 当前数入队（存储下标）
            dq.push_back(i);

            // 3. 检查队首是否过期：如果队首下标已经在窗口左侧之外了
            if (dq.front() == i - k)
            {
                dq.pop_front();
            }

            // 4. 记录答案：当窗口正式形成（长度达到k）时开始记录
            if (i >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};