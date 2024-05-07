/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lru_replacement.h"
#include <iostream>

// TODO: Add your implementation here
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Complete this constructor
}

// TODO: Add your implementations for desctructor, touch_page, load_page, replace_page here
LRUReplacement::~LRUReplacement()
{
    // TODO: Add necessary code here
}

// Accesss a page alreay in physical memory
void LRUReplacement::touch_page(int page_num) {
    touches++;
    lru_map[page_num] = touches + num_faults + num_replacements;
}

// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) {
    num_faults++;
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);
    lru_map[page_num] = touches + num_faults + num_replacements;
    frames_left--;
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {
    num_replacements++;
    lru_map[page_num] = touches + num_faults + num_replacements;

    //find lru element in map (find key with smallest value)
    int lru = 999999999;
    int victim = -1;
    for (auto it = lru_map.begin(); it != lru_map.end(); ++it) {
        if (it->second < lru) {
            victim = it->first;
            lru = it->second;
        }
    }
    if(victim == -1) return 0;
    lru_map.erase(victim);
    int victim_frame = page_table[victim].frame_num;
    page_table[victim].valid = false;
    page_table[page_num] = PageEntry(victim_frame, true, false);

    return victim;
}

