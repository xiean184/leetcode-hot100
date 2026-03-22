#include <vector>
using namespace std;

// 优化算法
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int slow = 0, ans = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            while (st.count(s[fast])) // 当前窗口里出现重复字符了
            {
                st.erase(s[slow]); // 把窗口左边的字符移出去，然后左边界右移
                slow++;
            }
            st.insert(s[fast]);
            ans = max(ans, fast - slow + 1);
        }
        return ans;
    }
};