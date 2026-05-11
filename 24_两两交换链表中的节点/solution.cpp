#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 优化算法
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0); // 创建一个虚拟节点，指向链表的头节点
        dummy->next = head;

        ListNode *cur = dummy; // 维护一个指针，指向当前节点的前一个节点

        while (cur->next != nullptr && cur->next->next != nullptr) // 只要当前节点的下一个节点和下下个节点都不为空，就可以交换
        {
            ListNode *first = cur->next;        // 记录当前节点的下一个节点，即第一个节点
            ListNode *second = cur->next->next; // 记录当前节点的下下个节点，即第二个节点

            first->next = second->next; // 交换两个节点的指针关系
            second->next = first;       // 交换两个节点的指针关系
            cur->next = second;         // 交换两个节点的指针关系

            cur = first; // 交换完成后，cur指向第一个节点，即下一个需要交换的节点的前一个节点
        }

        return dummy->next;
    }
};