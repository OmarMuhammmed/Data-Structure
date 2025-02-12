class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None  # Reference to previous node

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        new_node.prev = last

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("None")

dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.append(30)
dll.display()  # Output: 10 <-> 20 <-> 30 <-> None
