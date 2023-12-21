class Queue:
    def __init__(self, max_size=None):
        self.items = []
        self.max_size = max_size

    def is_empty(self):
        return len(self.items) == 0

    def is_full(self):
        if self.max_size is None:
            return False
        return len(self.items) == self.max_size

    def enqueue(self, item):
        if not self.is_full():
            self.items.append(item)
            print("Enqueued", item)
        else:
            print("Error: Queue is full")

    def dequeue(self):
        if self.is_empty():
            print("Error: Cannot dequeue from an empty queue")
        else:
            return self.items.pop(0)

    def front(self):
        if self.is_empty():
            print("Error: Cannot get front from an empty queue")
        else:
            return self.items[0]

    def rear(self):
        if self.is_empty():
            print("Error: Cannot get rear from an empty queue")
        else:
            return self.items[-1]

    def size(self):
        return len(self.items)


def print_menu():
    print("\nMenu:")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Front")
    print("4. Rear")
    print("5. Size")
    print("6. Exit")


def main():
    max_size = int(input("Enter the maximum size of the queue (Enter 0 for unlimited size): "))
    queue = Queue(max_size)

    while True:
        print_menu()
        choice = input("Enter your choice (1-6): ")

        if choice == "1":
            item = input("Enter the item to enqueue: ")
            queue.enqueue(item)
        elif choice == "2":
            dequeued_item = queue.dequeue()
            if dequeued_item is not None:
                print("Dequeued Item:", dequeued_item)
        elif choice == "3":
            front_item = queue.front()
            if front_item is not None:
                print("Front of the Queue:", front_item)
        elif choice == "4":
            rear_item = queue.rear()
            if rear_item is not None:
                print("Rear of the Queue:", rear_item)
        elif choice == "5":
            print("Size of the Queue:", queue.size())
        elif choice == "6":
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 6.")


# Execute the program directly without the if __name__ block
main()
