/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "fifo_replacement.h"
#include <queue>
#include <iostream>

// TODO: Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {
    // TODO: Add necessary code here
}

// Access an invalid page, but free frames are available
void FIFOReplacement::load_page(int page_num) {
    // TODO: Update your data structure FIFO replacement and pagetable
    num_faults++;
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);
    fifo_queue.push(page_num);
    frames_left--;
}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) {
    // TODO: Update your data structure FIFO replacement and pagetable
    int victim = fifo_queue.front();
    fifo_queue.pop();

    int victim_frame = page_table[victim].frame_num;
    page_table[victim].valid = false;
    page_table[page_num] = PageEntry(victim_frame, true, false);
    fifo_queue.push(page_num);

    num_replacements++;
    return victim;
}

void FIFOReplacement::touch_page(int page_num) {
    touches++;
}
