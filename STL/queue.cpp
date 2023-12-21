#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> myqueue;

public:
    void enqueue(int value) {
        myqueue.push(value);
        std::cout << "Enqueued: " << value << std::endl;
    }

    void dequeue() {
        if (!myqueue.empty()) {
            std::cout << "Dequeued: " << myqueue.front() << std::endl;
            myqueue.pop();
        } else {
            std::cout << "Queue is empty. Cannot dequeue.\n";
        }
    }

    void display() const {
        if (!myqueue.empty()) {
            std::cout << "Queue: ";
            std::queue<int> tempQueue = myqueue;

            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            std::cout << "\n";
        } else {
            std::cout << "Queue is empty.\n";
        }
    }

    bool is_empty() const {
        return myqueue.empty();
    }
};

int main() {
    Queue myQueue;

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "4. Is Empty?\n";
        std::cout << "5. Exit\n";

        // User input
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Enqueue
                {
                    int value;
                    std::cout << "Enter a value to enqueue: ";
                    std::cin >> value;
                    myQueue.enqueue(value);
                }
                break;

            case 2: // Dequeue
                myQueue.dequeue();
                break;

            case 3: // Display
                myQueue.display();
                break;

            case 4: // Is Empty?
                std::cout << (myQueue.is_empty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;

            case 5: // Exit
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
