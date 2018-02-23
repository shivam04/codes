'''Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.'''


"""
# Node Class    
class node:
    def __init__(self, val):
        self.data = val
        self.next = None
"""
# your task is to complete this function
# function should return true/false or 1/0
def isPalindrome(head):
    if head.next==None:
        return True
    slow_ptr = head
    fast_ptr = head
    prev_slow_ptr = None
    while fast_ptr!=None and fast_ptr.next!=None:
        fast_ptr = fast_ptr.next.next
        prev_slow_ptr = slow_ptr
        slow_ptr = slow_ptr.next
    if fast_ptr!=None:
        slow_ptr = slow_ptr.next
    second_half = slow_ptr
    prev_slow_ptr.next = None
    first_half = head
    prev = None
    current = second_half
    nextn = None
    while current!=None:
        nextn = current.next
        current.next = prev
        prev = current
        current = nextn
    second_half = prev
    while first_half!=None and second_half!=None:
        if second_half.data!=first_half.data:
            return False
        first_half = first_half.next
        second_half = second_half.next
    return True
