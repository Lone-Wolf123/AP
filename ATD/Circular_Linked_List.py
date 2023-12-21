class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
        else:
            last_node = self.head
            while last_node.next != self.head:
                last_node = last_node.next
            last_node.next = new_node
            new_node.next = self.head

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        last_node = self.head
        while last_node.next != self.head:
            last_node = last_node.next
        last_node.next = new_node
        self.head = new_node

    def delete(self, data):
        current_node = self.head
        prev_node = None

        while current_node and current_node.data != data:
            prev_node = current_node
            current_node = current_node.next

        if current_node is None:
            return

        if prev_node:
            prev_node.next = current_node.next
        else:
            # If the deleted node is the head, update the head
            last_node = self.head
            while last_node.next != self.head:
                last_node = last_node.next
            last_node.next = current_node.next
            self.head = current_node.next

    def display(self):
        current_node = self.head
        if not current_node:
            print("None")
            return
        while True:
            print(current_node.data, end=" -> ")
            current_node = current_node.next
            if current_node == self.head:
                break
        print("Head")


def print_menu():
    print("\nMenu:")
    print("1. Append")
    print("2. Prepend")
    print("3. Delete")
    print("4. Display")
    print("5. Exit")


def main():
    circular_linked_list = CircularLinkedList()

    while True:
        print_menu()
        choice = input("Enter your choice (1-5): ")

        if choice == "1":
            data = input("Enter the data to append: ")
            circular_linked_list.append(data)
        elif choice == "2":
            data = input("Enter the data to prepend: ")
            circular_linked_list.prepend(data)
        elif choice == "3":
            data = input("Enter the data to delete: ")
            circular_linked_list.delete(data)
        elif choice == "4":
            print("Circular Linked List:")
            circular_linked_list.display()
        elif choice == "5":
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")


# Execute the program directly without the if __name__ block
main()
