#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); // 二维数组排序
        int curL = intervals[0][0];
        int curR = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= curR) // 合并
            {
                curR = max(curR, intervals[i][1]);
            }
            else
            {
                ans.push_back({curL, curR});
                curL = intervals[i][0];
                curR = intervals[i][1];
            }
        }
        ans.push_back({curL, curR}); // 别忘了把最后的区间弹进去
        return ans;
    }
};