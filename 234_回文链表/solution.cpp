#include <vector>
#include <unordered_map>
using namespace std;
// 暴力算法
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> num;
        while (head != nullptr)
        {
            num.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = num.size() - 1;
        while (left < right)
        {
            if (num[left] != num[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// 优化算法：快慢指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        } // 单节点本身是回文
        // 1. 找中点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. 如果链表长度为奇数，slow 需要再前进一步
        if (fast != nullptr)
        {
            slow = slow->next;
        }
        // 3. 反转后半部分链表
        ListNode *cur = slow;
        ListNode *pre = nullptr;
        while (cur != nullptr)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        // 4. 比较前半部分和后半部分数值
        while (pre != nullptr)
        {
            if (head->val != pre->val)
                return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};