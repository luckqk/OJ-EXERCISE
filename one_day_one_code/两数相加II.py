# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
        它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
        你可以假设除了数字 0 之外，这两个数字都不会以零开头。
        
        使用栈来解决
        建链的顺序可以区别于两数相加.py
        :param l1: 
        :param l2: 
        :return: 
        """
        S1, S2 = [], []
        while l1:
            S1.append(l1.val)
            l1 = l1.next
        while l2:
            S2.append(l2.val)
            l2 = l2.next

        carry = 0
        head = ListNode(0)
        ans = None
        while S1 or S2 or carry != 0:
            curt_sum = carry
            if S1:
                curt_sum += S1.pop()
            if S2:
                curt_sum += S2.pop()
            carry, curt_num = divmod(curt_sum, 10)
            curt_node = ListNode(curt_num)
            curt_node.next = ans
            ans = curt_node

        return ans

def main():
    ans = Solution().addTwoNumbers(ListNode(2), ListNode(3))
    print(ans)

if __name__ == '__main__':
    main()
