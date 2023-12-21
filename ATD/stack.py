class Stack:
    def __init__(self, max_size=None):
        self.items = []
        self.max_size = max_size

    def is_empty(self):
        return len(self.items) == 0

    def is_full(self):
        if self.max_size is None:
            return False
        return len(self.items) == self.max_size

    def push(self, item):
        if not self.is_full():
            self.items.append(item)
            print("Pushed", item)
        else:
            print("Error: Stack is full")

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None  # Return None instead of raising an IndexError

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            return None  # Return None instead of raising an IndexError

    def size(self):
        return len(self.items)

    def top(self):
        return self.peek()


def print_menu():
    print("\nMenu:")
    print("1. Push")
    print("2. Pop")
    print("3. Peek")
    print("4. Size")
    print("5. Is Empty")
    print("6. Is Full")
    print("7. Top")
    print("8. Exit")


def main():
    max_size = int(input("Enter the maximum size of the stack (Enter 0 for unlimited size): "))
    stack = Stack(max_size)

    while True:
        print_menu()
        choice = input("Enter your choice (1-8): ")

        if choice == "1":
            item = input("Enter the item to push: ")
            stack.push(item)
        elif choice == "2":
            popped_item = stack.pop()
            if popped_item is not None:
                print("Popped Item:", popped_item)
            else:
                print("Error: Stack is empty")
        elif choice == "3":
            top_item = stack.peek()
            if top_item is not None:
                print("Top of the Stack:", top_item)
            else:
                print("Error: Stack is empty")
        elif choice == "4":
            print("Size of the Stack:", stack.size())
        elif choice == "5":
            print("Is Empty:", stack.is_empty())
        elif choice == "6":
            print("Is Full:", stack.is_full())
        elif choice == "7":
            top_item = stack.top()
            if top_item is not None:
                print("Top of the Stack:", top_item)
            else:
                print("Error: Stack is empty")
        elif choice == "8":
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 8.")


# Execute the program directly without the if __name__ block
main()
