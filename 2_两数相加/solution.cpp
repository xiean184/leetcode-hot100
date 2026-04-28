#include <vector>
using namespace std;
// 链表模拟竖式加法
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0; // 是否需要进位

        while (l1 != nullptr || l2 != nullptr || carry != 0) // 当l1和l2都为空，并且没有进位时，才结束循环
        {
            int x = 0, y = 0; // 当前位的值，默认为0，如果l1或l2不为空，则更新为对应的值

            if (l1 != nullptr) // 如果l1不为空，则更新x为l1当前节点的值，并将l1指向下一个节点
            {
                x = l1->val; // 更新x为l1当前节点的值
                l1 = l1->next;
            }

            if (l2 != nullptr) // 如果l2不为空，则更新y为l2当前节点的值，并将l2指向下一个节点
            {
                y = l2->val;
                l2 = l2->next;
            }

            int sum = x + y + carry; // 当前位的和等于x、y和carry的和
            carry = sum / 10;        // 更新carry为sum除以10的商，如果sum小于10，则carry为0；如果sum大于等于10，则carry为1

            cur->next = new ListNode(sum % 10); // 创建一个新的节点，值为sum除以10的余数，即当前位的值，并将cur的next指向这个新节点
            cur = cur->next;
        }

        return dummy->next;
    }
};