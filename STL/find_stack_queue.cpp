#include <iostream>
#include <stack>
#include <queue>

// Search for an element in a std::stack
template <typename T>
bool stackFind(std::stack<T>& mystack, const T& value) {
    std::stack<T> tempStack;

    while (!mystack.empty()) {
        if (mystack.top() == value) {
            std::cout << "Element found in the stack.\n";
            return true;
        }

        tempStack.push(mystack.top());
        mystack.pop();
    }

    // Restore the original stack
    while (!tempStack.empty()) {
        mystack.push(tempStack.top());
        tempStack.pop();
    }

    std::cout << "Element not found in the stack.\n";
    return false;
}

// Search for an element in a std::queue
template <typename T>
bool queueFind(std::queue<T>& myqueue, const T& value) {
    std::queue<T> tempQueue = myqueue;

    while (!tempQueue.empty()) {
        if (tempQueue.front() == value) {
            std::cout << "Element found in the queue.\n";
            return true;
        }

        tempQueue.pop();
    }

    std::cout << "Element not found in the queue.\n";
    return false;
}

int main() {
    // Example of a std::stack
    std::stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    int searchValueStack = 30;
    stackFind(myStack, searchValueStack);

    // Example of a std::queue
    std::queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);

    int searchValueQueue = 30;
    queueFind(myQueue, searchValueQueue);

    return 0;
}
