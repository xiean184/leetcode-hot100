#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans; // 定义答案数组，用来存所有异位词子串的起始下标
        int n = s.size(), m = p.size();

        if (n < m)
            return ans;

        vector<int> cntP(26, 0), cntS(26, 0); // 定义p中和当前窗口中第 i 个字母的出现次数。长度为26，初始值为0

        for (char c : p)
        {
            cntP[c - 'a']++; // cntP[0] = 1 表示 1 个 a
        }

        for (int right = 0; right < n; right++)
        {
            cntS[s[right] - 'a']++;

            if (right >= m) // 当窗口长度超过 m 时，说明窗口已经太长了，需要把最左边那个旧字符移出去
            {
                cntS[s[right - m] - 'a']--; // right - m 恰好就是当前窗口左边前一个位置
            }

            if (cntS == cntP)
            {
                ans.push_back(right - m + 1); // 收集首位、、起始下标
            }
        }

        return ans;
    }
};