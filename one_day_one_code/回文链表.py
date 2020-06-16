# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None:
            return True

        first_half_end = self.end_of_first_half(head)
        second_half_start = self.reverse_list(first_half_end.next)

        result = True
        first_position = head
        second_position = second_half_start
        while result and second_position is not None:
            if first_position.val != second_position.val:
                result = False
            first_position = first_position.next
            second_position = second_position.next

        # 恢复链表
        first_half_end.next = self.reverse_list(second_half_start)
        return result

    def end_of_first_half(self, head):
        """
        利用快慢指针寻找链表中点
        :param self:
        :param head: 表头
        :return: 2n链表，返回n点
                 2n+1链表，返回n点
        """
        fast = head
        slow = head
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
        return slow

    def reverse_list(self, head):
        """
        反转链表
        :param self:
        :param head: 反转链表的头
        :return: 反转后的链表起始点
        """
        previous = None
        curt = head
        while curt is not None:
            next_node = curt.next
            curt.next = previous
            previous = curt
            curt = next_node
        return previous


class Solution2:
    def isPalindrome(self, head: ListNode) -> bool:
        """
        利用列表逆序进行比较
        :param head:
        :return:
        """
        vals = []
        curt_node = head
        while curt_node is not None:
            vals.append(curt_node.val)
            curt_node = curt_node.next
        return vals == vals[::-1]
