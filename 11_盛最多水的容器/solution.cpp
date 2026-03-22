#include<vector>
using namespace std;
//暴力算法，超时
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            int s=0;
            for(int j=i;j<height.size();j++)
            {
                s=(j-i)*min(height[i],height[j]);
                ans=max(ans,s);
            }
        }
        return ans;
    }
};

//优化算法--双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,ans=0;
        int right=height.size()-1;
        while(left<right)
        {
            int area=(right-left)*min(height[right],height[left]);
            ans=max(ans,area);
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};