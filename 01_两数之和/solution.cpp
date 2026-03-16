#include <vector>
using namespace std;

//暴力算法O(n²)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//优化算法：哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;//定义一个哈希表 键值对：key: 数字 value: 索引
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (numMap.find(need) != numMap.end()) {//mp.end() 表示没找到
                return {numMap[need], i};//取出 key 为 need 对应的 value
            }
            numMap[nums[i]] = i;//没找到 就把当前数字和索引存入哈希表
        }
        return {};
    }
};