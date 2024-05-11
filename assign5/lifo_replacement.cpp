/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief A class implementing the Last in First Out (LIFO) page replacement algorithms
 * @version 0.1
 */


#include "lifo_replacement.h"

// Constructor
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // Not needed
}

// Destructor 
LIFOReplacement::~LIFOReplacement() {
    // Nothing needed
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    // Increment faults 
    num_faults++;

    // Update page table with new information
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);
    lifo_stack.push(page_num);

    // Decrement remaining number of free frames
    frames_left--;
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    // LIFO: victim is the top of a stack. This data structure is lifo. 
    int victim = lifo_stack.top();
    lifo_stack.pop();

    // Get victim frame number, set its valid bit to false
    int victim_frame = page_table[victim].frame_num;
    page_table[victim].valid = false;

    // Update the page table with information
    page_table[page_num] = PageEntry(victim_frame, true, false);
    lifo_stack.push(page_num);

    // Increment the number of replaced pages, return the victim page
    num_replacements++;
    return victim;
}

void LIFOReplacement::touch_page(int page_num) {
    // Increment number of touches
    touches++;
}
