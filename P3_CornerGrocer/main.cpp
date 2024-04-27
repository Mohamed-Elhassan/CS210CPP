#include "ItemTracker.h"
#include <iostream>
#include <functional>
#include <map>
#include <limits>

// Displays and handles the main menu
void displayMenu(ItemTracker& tracker) {
    std::map<int, std::function<void()>> menuOptions;  // Maps integers to corresponding functions
    menuOptions[1] = [&tracker]() {
        std::string item;
        std::cout << "Enter item name: ";
        std::cin >> item;
        tracker.displayItemFrequency(item);
        };
    menuOptions[2] = [&tracker]() {
        tracker.displayAllFrequencies();
        };
    menuOptions[3] = [&tracker]() {
        tracker.displayHistogram();
        };
    menuOptions[4] = [&tracker]() {
        std::string item;
        int count;
        std::cout << "Enter item name and count to add: ";
        std::cin >> item >> count;
        tracker.addItem(item, count);
        };
    menuOptions[5] = [&tracker]() {
        std::string item;
        int delta;
        std::cout << "Enter item name and frequency adjustment: ";
        std::cin >> item >> delta;
        tracker.adjustItemFrequency(item, delta);
        };
    menuOptions[6] = [&tracker]() {
        bool byFrequency;
        std::cout << "Sort by frequency (1) or alphabetically (0): ";
        std::cin >> byFrequency;
        tracker.sortHistogram(byFrequency);
        };
    menuOptions[7] = []() {
        std::cout << "Exiting program." << std::endl;
        exit(0);
        };

    int choice;
    do {
        std::cout << "1. Display frequency of a specific item" << std::endl;
        std::cout << "2. Display all item frequencies" << std::endl;
        std::cout << "3. Display histogram of item frequencies" << std::endl;
        std::cout << "4. Add items" << std::endl;
        std::cout << "5. Adjust item frequency" << std::endl;
        std::cout << "6. Sort histogram" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Please enter numbers only.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (menuOptions.find(choice) != menuOptions.end()) {
            menuOptions[choice]();
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (true);
}

int main() {
    ItemTracker tracker;
    displayMenu(tracker);  // Call the display menu function to manage user interaction
    return 0;
}
