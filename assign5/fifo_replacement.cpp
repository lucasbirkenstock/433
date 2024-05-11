/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */


#include "fifo_replacement.h"
#include <queue>
#include <iostream>

// Constructor
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // Nothing needed
}

// Destructor
FIFOReplacement::~FIFOReplacement() {
    // Nothing needed
}

// Access an invalid page, but free frames are available
void FIFOReplacement::load_page(int page_num) {
    // Increment number of faults
    num_faults++;

    // Updates page table with information about new page
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);
    fifo_queue.push(page_num);

    // Decrement number of remaining free frames
    frames_left--;
}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) {
    // Choose first page as victim page, remove it from the fifo queue
    int victim = fifo_queue.front();
    fifo_queue.pop();

    // Get victim frame number from the page table, set it to invalid (because it is being removed)
    int victim_frame = page_table[victim].frame_num;
    page_table[victim].valid = false;

    // Put the victim frame in the page table at [page_num]
    page_table[page_num] = PageEntry(victim_frame, true, false);
    fifo_queue.push(page_num);

    // Increment the number of replacements, return victim 
    num_replacements++;
    return victim;
}

void FIFOReplacement::touch_page(int page_num) {
    // Increment touches
    touches++;
}
