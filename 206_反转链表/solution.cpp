#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *nxt = cur->next; // 先保存后继
            cur->next = prev;          // 当前节点反向指向前一个节点
            prev = cur;                // prev 前进
            cur = nxt;                 // cur 前进
        }

        return prev;
    }
};