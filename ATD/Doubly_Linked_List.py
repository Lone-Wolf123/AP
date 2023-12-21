class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            last_node = self.head
            while last_node.next:
                last_node = last_node.next
            last_node.next = new_node
            new_node.prev = last_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node

    def delete(self, data):
        current_node = self.head
        while current_node and current_node.data != data:
            current_node = current_node.next

        if current_node is None:
            return

        if current_node.prev:
            current_node.prev.next = current_node.next
        else:
            self.head = current_node.next

        if current_node.next:
            current_node.next.prev = current_node.prev

    def display_forward(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=" -> ")
            current_node = current_node.next
        print("None")

    def display_backward(self):
        last_node = None
        current_node = self.head
        while current_node:
            last_node = current_node
            current_node = current_node.next

        while last_node:
            print(last_node.data, end=" -> ")
            last_node = last_node.prev
        print("None")


def print_menu():
    print("\nMenu:")
    print("1. Append")
    print("2. Prepend")
    print("3. Delete")
    print("4. Display Forward")
    print("5. Display Backward")
    print("6. Exit")


def main():
    doubly_linked_list = DoublyLinkedList()

    while True:
        print_menu()
        choice = input("Enter your choice (1-6): ")

        if choice == "1":
            data = input("Enter the data to append: ")
            doubly_linked_list.append(data)
        elif choice == "2":
            data = input("Enter the data to prepend: ")
            doubly_linked_list.prepend(data)
        elif choice == "3":
            data = input("Enter the data to delete: ")
            doubly_linked_list.delete(data)
        elif choice == "4":
            print("Doubly Linked List (Forward):")
            doubly_linked_list.display_forward()
        elif choice == "5":
            print("Doubly Linked List (Backward):")
            doubly_linked_list.display_backward()
        elif choice == "6":
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 6.")


# Execute the program directly without the if __name__ block
main()
