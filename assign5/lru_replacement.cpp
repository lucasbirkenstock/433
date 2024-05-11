/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */


#include "lru_replacement.h"
#include <iostream>

// Constructor
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // Not needed
}

// Destructor
LRUReplacement::~LRUReplacement()
{
    // Nothing needed here
}

// Accesss a page already in physical memory
void LRUReplacement::touch_page(int page_num) {
    // Increment number of touches
    touches++;
    // Update value stored for page number key, since touches was updated
    lru_map[page_num] = touches + num_faults + num_replacements;
}

// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) {
    // Increment the number of faults
    num_faults++;

    // Update the page table with page entry info
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);

    // Update val for page num key
    lru_map[page_num] = touches + num_faults + num_replacements;

    // Decrement number of remaining frames
    frames_left--;
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {
    num_replacements++;
    lru_map[page_num] = touches + num_faults + num_replacements;

    //find lru element in map (find key with smallest value)
    // Huge value so anything is smaller
    int lru = 999999999;
    int victim = -1;

    // For each key in the map, 
    for (auto it = lru_map.begin(); it != lru_map.end(); ++it) {
        // If value from key is less than LRU, replace info for LRU with this key
        if (it->second < lru) {
            victim = it->first;
            lru = it->second;
        }
    }

    // If no victim is less than lru, return 0
    if(victim == -1) return 0;

    // Remove the LRU frame from the map
    lru_map.erase(victim);

    // Select the victim frame as the LRU frame [info stored before being removed from map]
    int victim_frame = page_table[victim].frame_num;

    // Set valid bit to false
    page_table[victim].valid = false;

    // Update page table information
    page_table[page_num] = PageEntry(victim_frame, true, false);

    return victim;
}

