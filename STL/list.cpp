#include <iostream>
#include <list>
#include <algorithm>

class FixedSizeList {
private:
    std::list<int> mylist;
    size_t max_size;

public:
    FixedSizeList(size_t size) : max_size(size) {}

    void push_front(int value) {
        if (mylist.size() < max_size) {
            mylist.push_front(value);
            std::cout << "Pushed Front: " << value << std::endl;
        } else {
            std::cout << "List is full. Cannot push to the front.\n";
        }
    }

    void pop_front() {
        if (!mylist.empty()) {
            std::cout << "Popped Front: " << mylist.front() << std::endl;
            mylist.pop_front();
        } else {
            std::cout << "List is empty. Cannot pop from the front.\n";
        }
    }

    void push_back(int value) {
        if (mylist.size() < max_size) {
            mylist.push_back(value);
            std::cout << "Pushed Back: " << value << std::endl;
        } else {
            std::cout << "List is full. Cannot push to the back.\n";
        }
    }

    void pop_back() {
        if (!mylist.empty()) {
            std::cout << "Popped Back: " << mylist.back() << std::endl;
            mylist.pop_back();
        } else {
            std::cout << "List is empty. Cannot pop from the back.\n";
        }
    }

    void display() const {
        if (!mylist.empty()) {
            std::cout << "List: ";
            for (const auto &value : mylist) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "List is empty.\n";
        }
    }

    bool is_empty() const {
        return mylist.empty();
    }

    bool is_full() const {
        return mylist.size() == max_size;
    }

    // Find function to search for a value in the list
    bool find(int value) const {
        return std::find(mylist.begin(), mylist.end(), value) != mylist.end();
    }
};

int main() {
    // Example of a fixed-size list
    FixedSizeList myList(5);

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Push Front\n";
        std::cout << "2. Pop Front\n";
        std::cout << "3. Push Back\n";
        std::cout << "4. Pop Back\n";
        std::cout << "5. Display\n";
        std::cout << "6. Is Empty?\n";
        std::cout << "7. Is Full?\n";
        std::cout << "8. Find\n";
        std::cout << "9. Exit\n";

        // User input
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Push Front
                {
                    int value;
                    std::cout << "Enter a value to push to the front: ";
                    std::cin >> value;
                    myList.push_front(value);
                }
                break;

            case 2: // Pop Front
                myList.pop_front();
                break;

            case 3: // Push Back
                {
                    int value;
                    std::cout << "Enter a value to push to the back: ";
                    std::cin >> value;
                    myList.push_back(value);
                }
                break;

            case 4: // Pop Back
                myList.pop_back();
                break;

            case 5: // Display
                myList.display();
                break;

            case 6: // Is Empty?
                std::cout << (myList.is_empty() ? "List is empty.\n" : "List is not empty.\n");
                break;

            case 7: // Is Full?
                std::cout << (myList.is_full() ? "List is full.\n" : "List is not full.\n");
                break;

            case 8: // Find
                {
                    int value;
                    std::cout << "Enter a value to find: ";
                    std::cin >> value;
                    std::cout << (myList.find(value) ? "Value found in the list.\n" : "Value not found in the list.\n");
                }
                break;

            case 9: // Exit
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
