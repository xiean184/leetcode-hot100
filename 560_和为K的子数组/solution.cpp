#include <vector>
using namespace std;

// 最优算法
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp; // 哈希表用来记录前缀和出现的次数
        mp[0] = 1;                  // 前缀和为 0 出现 1 次

        int sum = 0;
        int count = 0;

        for (int x : nums)
        {
            sum += x;

            if (mp.count(sum - k))
            {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};