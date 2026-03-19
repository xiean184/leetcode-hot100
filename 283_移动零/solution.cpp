#include <vector>
using namespace std;

//暴力解法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        for(int i:nums)
        {
            if(i!=0)
            {
                temp.push_back(i);
            }
        }
        int len=nums.size()-temp.size();
        for(int i=0;i<len;i++)
        {
            temp.push_back(0);
        }
        nums=temp;
    }
};

//优化解法：双指针法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;//指向下一个该放非零元素的位置
        for(int fast=0;fast<nums.size();fast++)//fast用来遍历整个数组寻找非零元素
        {
            if(nums[fast]!=0)
            {
                nums[slow]=nums[fast];
                slow++;//指向下一个可以放非零元素的位置
            }
        }
        while(slow<nums.size())//补够0
        {
            nums[slow]=0;
            slow++;
        }
    }
};