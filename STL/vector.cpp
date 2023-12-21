#include <iostream>
#include <vector>
#include <algorithm>

class FixedSizeVector {
private:
    std::vector<int> myvector;
    size_t max_size;

public:
    FixedSizeVector(size_t size) : max_size(size) {}

    void push_back(int value) {
        if (myvector.size() < max_size) {
            myvector.push_back(value);
            std::cout << "Pushed Back: " << value << std::endl;
        } else {
            std::cout << "Vector is full. Cannot push to the back.\n";
        }
    }

    void pop_back() {
        if (!myvector.empty()) {
            std::cout << "Popped Back: " << myvector.back() << std::endl;
            myvector.pop_back();
        } else {
            std::cout << "Vector is empty. Cannot pop from the back.\n";
        }
    }

    void display() const {
        if (!myvector.empty()) {
            std::cout << "Vector: ";
            for (const auto &value : myvector) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Vector is empty.\n";
        }
    }

    bool is_empty() const {
        return myvector.empty();
    }

    bool is_full() const {
        return myvector.size() == max_size;
    }

    // Find function to search for a value in the vector
    bool find(int value) const {
        return std::find(myvector.begin(), myvector.end(), value) != myvector.end();
    }
};

int main() {
    // Example of a fixed-size vector
    FixedSizeVector myVector(5);

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Push Back\n";
        std::cout << "2. Pop Back\n";
        std::cout << "3. Display\n";
        std::cout << "4. Is Empty?\n";
        std::cout << "5. Is Full?\n";
        std::cout << "6. Find\n";
        std::cout << "7. Exit\n";

        // User input
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Push Back
                {
                    int value;
                    std::cout << "Enter a value to push to the back: ";
                    std::cin >> value;
                    myVector.push_back(value);
                }
                break;

            case 2: // Pop Back
                myVector.pop_back();
                break;

            case 3: // Display
                myVector.display();
                break;

            case 4: // Is Empty?
                std::cout << (myVector.is_empty() ? "Vector is empty.\n" : "Vector is not empty.\n");
                break;

            case 5: // Is Full?
                std::cout << (myVector.is_full() ? "Vector is full.\n" : "Vector is not full.\n");
                break;

            case 6: // Find
                {
                    int value;
                    std::cout << "Enter a value to find: ";
                    std::cin >> value;
                    std::cout << (myVector.find(value) ? "Value found in the vector.\n" : "Value not found in the vector.\n");
                }
                break;

            case 7: // Exit
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
