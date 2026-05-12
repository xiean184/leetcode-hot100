#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *Prev = dummy;

        while (true) // 循环直到链表末尾
        {
            ListNode *kth = Prev; // 先找到要翻转的链表的末尾

            for (int i = 0; i < k && kth != nullptr; i++) // 先找到要翻转的链表的末尾
            {
                kth = kth->next;
            }

            if (kth == nullptr) // 如果末尾为nullptr，说明剩余的链表长度不足k，不需要翻转了
            {
                break;
            }

            ListNode *Next = kth->next; // 记录下一个要翻转的链表的头节点

            ListNode *pre = Next; // 开始翻转链表，需要翻转k次
            ListNode *cur = Prev->next;

            while (cur != Next)
            {
                ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            ListNode *oldGroupHead = Prev->next; // 记录下当前要翻转的链表的头节点
            Prev->next = kth;                    // 将当前要翻转的链表的头节点连接到前一个链表的末尾
            Prev = oldGroupHead;
        }

        return dummy->next;
    }
};
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *end = dummy;

        while (true) // 循环直到链表末尾
        {
            for (int i = 0; i < k && end != nullptr; i++) // 先找到要翻转的链表的末尾
            {
                end = end->next;
            }

            if (end == nullptr) // 如果末尾为nullptr，说明剩余的链表长度不足k，不需要翻转了
            {
                break;
            }

            ListNode *start = pre->next;
            ListNode *then = start->next;

            for (int i = 1; i < k; i++) // 开始翻转链表，需要翻转k-1次
            {
                start->next = then->next;
                then->next = pre->next;
                pre->next = then;
                then = start->next;
            }

            pre = start;
            end = pre;
        }

        return dummy->next;
    }
};