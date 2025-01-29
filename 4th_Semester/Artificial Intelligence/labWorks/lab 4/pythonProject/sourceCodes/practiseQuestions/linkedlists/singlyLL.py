class Node:
    def __init__(self, data):
        self.data = data
        self.nextNode = None


class SinglyLinkedList:
    value = None
    head = None

    def insert_in_list(self, value):
        self.value = value

        newNode = Node(self.value)

        if self.head is None:
            self.head = newNode
            return

        temp = self.head
        while temp.nextNode is not None:
            temp = temp.nextNode
        temp.nextNode = newNode

    def traverse_list(self):
        temp = self.head

        if self.head is None:
            print("Can't traverse the list is empty")

        while temp is not None:
            print(temp.data)
            temp = temp.nextNode
        return


s1 = SinglyLinkedList()
s1.insert_in_list(5)
s1.insert_in_list(6)
s1.insert_in_list(7)
s1.traverse_list()
