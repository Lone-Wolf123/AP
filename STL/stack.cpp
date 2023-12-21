#include <iostream>
#include <stack>

class Stack {
private:
    std::stack<int> mystack;

public:
    void push(int value) {
        mystack.push(value);
        std::cout << "Pushed: " << value << std::endl;
    }

    void pop() {
        if (!mystack.empty()) {
            std::cout << "Popped: " << mystack.top() << std::endl;
            mystack.pop();
        } else {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
    }

    void display() const {
        if (!mystack.empty()) {
            std::cout << "Stack: ";
            std::stack<int> tempStack = mystack;
            while (!tempStack.empty()) {
                std::cout << tempStack.top() << " ";
                tempStack.pop();
            }
            std::cout << "\n";
        } else {
            std::cout << "Stack is empty.\n";
        }
    }

    bool is_empty() const {
        return mystack.empty();
    }
};

int main() {
    Stack myStack;

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Is Empty?\n";
        std::cout << "5. Exit\n";

        // User input
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Push
                {
                    int value;
                    std::cout << "Enter a value to push: ";
                    std::cin >> value;
                    myStack.push(value);
                }
                break;

            case 2: // Pop
                myStack.pop();
                break;

            case 3: // Display
                myStack.display();
                break;

            case 4: // Is Empty?
                std::cout << (myStack.is_empty() ? "Stack is empty.\n" : "Stack is not empty.\n");
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
