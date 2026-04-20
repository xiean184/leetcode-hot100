#include <vector>
using namespace std;
// 暴力算法
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        for (ListNode *a = headA; a != nullptr; a = a->next)
        {
            for (ListNode *b = headB; b != nullptr; b = b->next)
            {
                if (a == b)
                    return a;
            }
        }
        return nullptr;
    }
};

// 优化算法
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        return a;
    }
};