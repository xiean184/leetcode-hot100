#include <vector>
using namespace std;
// 暴力算法：将两个有序链表中的值放进一个数组中，并进行排序，最后将数组中的值放进一个新的链表中
// 时间复杂度：O(nlogn)，空间复杂度：O(n)
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> sum;
        while (list1 != nullptr)
        {
            sum.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            sum.push_back(list2->val);
            list2 = list2->next;
        }
        sort(sum.begin(), sum.end());
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        for (int x : sum)
        {
            ListNode *temp = new ListNode(x);
            cur->next = temp;
            cur = cur->next;
        }
        return dummy->next;
    }
};
// 优化算法：直接比较两个链表的头节点，将较小的节点连接到新的链表中，直到其中一个链表为空，然后将另一个链表连接到新的链表的末尾  双指针+归并
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (list1 != nullptr)
        {
            cur->next = list1;
        }
        else
        {
            cur->next = list2;
        }

        return dummy->next;
    }
};