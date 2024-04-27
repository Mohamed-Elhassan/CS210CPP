#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

// Constructor that initializes data loading and backup
ItemTracker::ItemTracker() {
    loadData("CS210_Project_Three_Input_File.txt");
    backupData("frequency.dat");
}

// Loads data from the specified file
void ItemTracker::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    std::string item;
    frequencies.clear();
    while (file >> item) {
        frequencies[item]++;  // Increment frequency for each item
    }
    file.close();
}

// Backs up data to the specified file
void ItemTracker::backupData(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    for (const auto& pair : frequencies) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
    outFile.close();
}

// Displays frequency of a specified item
void ItemTracker::displayItemFrequency(const std::string& item) {
    auto it = frequencies.find(item);
    if (it != frequencies.end()) {
        std::cout << it->first << " appears " << it->second << " times." << std::endl;
    }
    else {
        std::cout << item << " does not appear in the records." << std::endl;
    }
}

// Displays frequencies for all items
void ItemTracker::displayAllFrequencies() {
    for (const auto& pair : frequencies) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

// Displays a histogram of item frequencies
void ItemTracker::displayHistogram() {
    for (const auto& pair : frequencies) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Adds or increments an item's count
void ItemTracker::addItem(const std::string& item, int count) {
    frequencies[item] += count;
}

// Adjusts the frequency of an item
void ItemTracker::adjustItemFrequency(const std::string& item, int delta) {
    if (frequencies.find(item) != frequencies.end()) {
        frequencies[item] += delta;
    }
}

// Sorts and displays the histogram either by frequency or alphabetically
void ItemTracker::sortHistogram(bool byFrequency) {
    std::vector<std::pair<std::string, int>> freqVector(frequencies.begin(), frequencies.end());
    if (byFrequency) {
        std::sort(freqVector.begin(), freqVector.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;  // Sort by descending frequency
            });
    }
    else {
        std::sort(freqVector.begin(), freqVector.end());  // Sort alphabetically
    }
    for (const auto& pair : freqVector) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;  // Display sorted histogram
    }
}
