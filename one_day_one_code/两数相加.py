class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        给出两个非空的链表用来表示两个非负的整数。
        其中，它们各自的位数是按照逆序的方式存储的，
        并且它们的每个节点只能存储一位数字。如果，我们将这两个数相加起来，
        则会返回一个新的链表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0开头。
        :param l1: 
        :param l2: 
        :return: 
        """
        carry = 0
        head = ListNode(0)
        pre_node = head
        while l1 != None or l2 != None or carry != 0:
            if l1 != None:
                carry += l1.val
                l1 = l1.next
            if l2 != None:
                carry += l2.val
                l2 = l2.next
            carry, curt_pt = divmod(carry, 10)
            new_node = ListNode(curt_pt)
            pre_node.next = new_node
            pre_node = new_node

        return head.next

def main():
    pass


if __name__ == '__main__':
    main()
