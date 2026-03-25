#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> need(128, 0); // 记录每个字符还需要多少个，一共128个，初始化为0
        for (char c : t)          // 统计 t 中每个字符需要多少个
        {
            need[c]++;
        }

        int left = 0;         // 左指针，表示当前窗口左边界
        int start = 0;        // 记录最终答案子串的起始位置。
        int minLen = INT_MAX; // 记录目前找到的最短合法窗口长度
        int n = t.size();     // 表示当前窗口还缺多少个字符

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];

            if (need[c] > 0)
            {
                n--;
            }
            need[c]--;

            while (n == 0) // 满足t窗口了
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                char d = s[left];
                need[d]++;

                if (need[d] > 0)
                {
                    n++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};