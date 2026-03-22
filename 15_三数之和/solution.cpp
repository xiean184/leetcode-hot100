#include<vector>
using namespace std;

//暴力算法+额外去重
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//优化算法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;//返回一个数组，每个数组里是一个三数组
        sort(nums.begin(),nums.end());//排序方便去重

        for(int i=0;i<nums.size();i++)
        {
            if (nums[i] > 0) break;//当前数大于0，往后的数都大于0，没有遍历的必要了
            if(i>0&&nums[i]==nums[i-1]) continue;//如果遍历当前的数和上一个数相同，没必要在遍历一遍了

            int left = i + 1;
            int right=nums.size()-1;

            while(left<right)//左右指针没相遇
            {
                if(nums[i]+nums[left]+nums[right]>0)//当总和大于0
                    right--;//右指针变小，和才可能变小
                else if(nums[i]+nums[left]+nums[right]<0)//当总和小于0
                    left++;//左指针变大，和才可能变大
                else//当总和为0，符合题意
                {
                    ans.push_back({nums[i],nums[left],nums[right]});//把答案弹进去
                    left++;
                    right--;
                    while(left<right&&nums[left]==nums[left-1]) left++;
                    while(left<right&&nums[right]==nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};