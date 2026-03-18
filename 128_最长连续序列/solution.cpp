#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());//把nums里的数值全部放进st中，自动去重且可以快速查找元素是否存在
        int ans=0;
        for(int s:st)//遍历哈希表更合适，因为已经去过重了
        {
            if(st.find(s-1)==st.end())//如果st中s-1不存在，就证明此时s是连续系列的第一个，从s开始数，如果存在，就不应该从它开始数。
            {//s-1不存在的执行块
                int cur=s;//定义当前正在向后扩展的数字
                int len=1;//定义当前这段连续序列的长度，起点自己已经算一个数了。
                while(st.find(cur+1)!=st.end())
                {
                    cur++;
                    len++;//找到下一个连续数字后，变成 2
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

//排序法代码
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i]) continue;
            else if(nums[i]==nums[i-1]+1)
            {
                len++;
            }
            else len=1;
            ans=max(ans,len);
        }
        return ans;
    }
};