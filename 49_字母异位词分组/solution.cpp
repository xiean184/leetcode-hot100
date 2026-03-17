#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;//哈希表：特征字符串 -> 这一组所有原字符串
        for(string s:strs)//把 strs 里的每个字符串依次取出来，名字叫 s
        {
            string key=s;
            sort(key.begin(),key.end());//把 key 里的字符从小到大排序
            mp[key].push_back(s);//把原字符串 s 放进 key 对应的那一组里
        }
        vector<vector<string>> ans;
        for (auto& pair : mp) //把哈希表里的每一项都取出来 pair.first 是键 pair.second 是值
        {
            ans.push_back(pair.second);//把这一组字符串加入结果
        }
        return ans;
    }

}