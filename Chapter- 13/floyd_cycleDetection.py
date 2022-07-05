class Node:
    def __init__(self, V):
        self.value = V
        self.next = None

head = None

def detect_Loop(head):
    slowPointer = head
    fastPointer = head

    while slowPointer != None and fastPointer != None and fastPointer.next != None:
        slowPointer = slowPointer.next
        fastPointer = fastPointer.next.next
        if slowPointer == fastPointer:
            return 1

    return 0


head = Node(1)
head.next = Node(10)
head.next.next = Node(32)
head.next.next.next = Node(21)
head.next.next.next.next = Node(7)

temp = head
while (temp.next != None):
    temp = temp.next

temp.next = head

if (detect_Loop(head)):
    print(" Loop exists in the Linked List ")
else:
    print(" Loop doesn't exists in the Linked List ")