#pragma once
#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <unordered_map>

class ItemTracker {
public:
    ItemTracker();  // Constructor to initialize the ItemTracker
    void displayItemFrequency(const std::string& item);  // Displays frequency of a specified item
    void displayAllFrequencies();  // Displays frequencies of all items
    void displayHistogram();  // Displays a histogram of item frequencies
    void addItem(const std::string& item, int count);  // Adds or increments an item's count
    void adjustItemFrequency(const std::string& item, int delta);  // Adjusts the frequency of an item
    void sortHistogram(bool byFrequency);  // Sorts and displays the histogram by frequency or alphabetically

private:
    std::unordered_map<std::string, int> frequencies;  // Map to store item frequencies
    void loadData(const std::string& filename);  // Loads data from a file
    void backupData(const std::string& filename);  // Backs up data to a file
};

#endif
