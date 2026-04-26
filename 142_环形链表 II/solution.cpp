#include <vector>
using namespace std;
// 暴力解法：一边遍历链表，一边将访问过的节点地址存储起来
// 时间复杂度：O(n)，空间复杂度：O(n)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        vector<ListNode *> visited;
        while (head != nullptr)
        {
            for (ListNode *node : visited) // 遍历访问过的节点，判断当前节点是否在其中
            {
                if (node == head)
                    return head; // 如果当前节点在访问过的节点中，说明链表存在环，返回当前节点地址
            }
            visited.push_back(head); // 将当前节点地址存储起来
            head = head->next;       // 继续遍历链表
        }
    }
};

// 快慢指针解法：使用两个指针，快指针每次移动两步，慢指针每次移动一步，如果链表存在环，快指针和慢指针最终会相遇
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) // 如果快慢指针相遇，说明链表存在环
            {
                ListNode *ptr = head; // 从链表头部开始遍历，直到快慢指针再次相遇

                while (ptr != slow) // 当快慢指针再次相遇时，说明找到了环的入口节点，返回该节点地址
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};