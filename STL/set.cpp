#include <iostream>
#include <set>

class FixedSet {
private:
    std::set<int> myset;
    size_t max_size;

public:
    FixedSet(size_t size) : max_size(size) {}

    void insert(int value) {
        if (myset.size() < max_size) {
            myset.insert(value);
            std::cout << "Inserted: " << value << std::endl;
        } else {
            std::cout << "Set is full. Cannot insert.\n";
        }
    }

    void erase(int value) {
        auto it = myset.find(value);
        if (it != myset.end()) {
            myset.erase(it);
            std::cout << "Erased: " << value << std::endl;
        } else {
            std::cout << "Value not found in the set. Cannot erase.\n";
        }
    }

    void display() const {
        if (!myset.empty()) {
            std::cout << "Set: ";
            for (const auto &value : myset) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Set is empty.\n";
        }
    }

    bool is_empty() const {
        return myset.empty();
    }

    bool is_full() const {
        return myset.size() == max_size;
    }

    // Find function to search for a value in the set
    bool find(int value) const {
        return myset.find(value) != myset.end();
    }
};

int main() {
    // Example of a fixed-size set
    FixedSet mySet(5);

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Erase\n";
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
            case 1: // Insert
                {
                    int value;
                    std::cout << "Enter a value to insert: ";
                    std::cin >> value;
                    mySet.insert(value);
                }
                break;

            case 2: // Erase
                {
                    int value;
                    std::cout << "Enter a value to erase: ";
                    std::cin >> value;
                    mySet.erase(value);
                }
                break;

            case 3: // Display
                mySet.display();
                break;

            case 4: // Is Empty?
                std::cout << (mySet.is_empty() ? "Set is empty.\n" : "Set is not empty.\n");
                break;

            case 5: // Is Full?
                std::cout << (mySet.is_full() ? "Set is full.\n" : "Set is not full.\n");
                break;

            case 6: // Find
                {
                    int value;
                    std::cout << "Enter a value to find: ";
                    std::cin >> value;
                    std::cout << (mySet.find(value) ? "Value found in the set.\n" : "Value not found in the set.\n");
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
