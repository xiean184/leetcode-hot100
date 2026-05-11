#include <vector>
#include <algorithm>
using namespace std;

// 暴力算法
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 0;       // 计算链表长度
        ListNode *cur = head; // 遍历链表

        while (cur != nullptr) // 计算链表长度
        {
            length++;
            cur = cur->next;
        }

        ListNode *dummy = new ListNode(0); // 创建一个虚拟头节点
        dummy->next = head;                // 将虚拟头节点指向链表头节点

        cur = dummy; // 从虚拟头节点开始遍历链表

        int steps = length - n; // 计算需要移动的步数，即链表长度减去 n

        for (int i = 0; i < steps; i++) // 移动到需要删除节点的前一个节点
        {
            cur = cur->next; // 移动到需要删除节点的前一个节点
        }

        cur->next = cur->next->next; // 删除节点，即将前一个节点的 next 指向需要删除节点的下一个节点

        return dummy->next; // 返回链表头节点，即虚拟头节点的下一个节点
    }
};

// 双指针算法：快慢指针
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i < n; i++) // 快指针先移动 n 步
        {
            fast = fast->next;
        }

        while (fast->next != nullptr) // 快慢指针同时移动，直到快指针到达链表末尾
        {
            fast = fast->next; // 快指针移动
            slow = slow->next; // 慢指针移动
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};