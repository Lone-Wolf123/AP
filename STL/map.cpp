#include <iostream>
#include <map>

class FixedMap {
private:
    std::map<int, std::string> mymap;
    size_t max_size;

public:
    FixedMap(size_t size) : max_size(size) {}

    void insert(int key, const std::string& value) {
        if (mymap.size() < max_size) {
            mymap[key] = value;
            std::cout << "Inserted: {" << key << ", " << value << "}\n";
        } else {
            std::cout << "Map is full. Cannot insert.\n";
        }
    }

    void erase(int key) {
        auto it = mymap.find(key);
        if (it != mymap.end()) {
            mymap.erase(it);
            std::cout << "Erased key: " << key << "\n";
        } else {
            std::cout << "Key not found in the map. Cannot erase.\n";
        }
    }

    void display() const {
        if (!mymap.empty()) {
            std::cout << "Map: ";
            for (const auto &entry : mymap) {
                std::cout << "{" << entry.first << ", " << entry.second << "} ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Map is empty.\n";
        }
    }

    bool is_empty() const {
        return mymap.empty();
    }

    bool is_full() const {
        return mymap.size() == max_size;
    }

    // Find function to search for a key in the map
    bool find(int key) const {
        return mymap.find(key) != mymap.end();
    }
};

int main() {
    // Example of a fixed-size map
    FixedMap myMap(5);

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
                    int key;
                    std::string value;
                    std::cout << "Enter a key to insert: ";
                    std::cin >> key;
                    std::cout << "Enter a value to insert: ";
                    std::cin >> value;
                    myMap.insert(key, value);
                }
                break;

            case 2: // Erase
                {
                    int key;
                    std::cout << "Enter a key to erase: ";
                    std::cin >> key;
                    myMap.erase(key);
                }
                break;

            case 3: // Display
                myMap.display();
                break;

            case 4: // Is Empty?
                std::cout << (myMap.is_empty() ? "Map is empty.\n" : "Map is not empty.\n");
                break;

            case 5: // Is Full?
                std::cout << (myMap.is_full() ? "Map is full.\n" : "Map is not full.\n");
                break;

            case 6: // Find
                {
                    int key;
                    std::cout << "Enter a key to find: ";
                    std::cin >> key;
                    std::cout << (myMap.find(key) ? "Key found in the map.\n" : "Key not found in the map.\n");
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
