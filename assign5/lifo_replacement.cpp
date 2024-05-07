/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the Last in First Out (LIFO) page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lifo_replacement.h"

// TODO: Add your implementation here
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
LIFOReplacement::~LIFOReplacement() {
    // TODO: Add necessary code here
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    num_faults++;
    page_table[page_num] = PageEntry(num_frames-frames_left, true, false);
    lifo_stack.push(page_num);
    frames_left--;
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    // TODO: Add necessary code here
    int victim = lifo_stack.top();
    lifo_stack.pop();

    int victim_frame = page_table[victim].frame_num;
    page_table[victim].valid = false;
    page_table[page_num] = PageEntry(victim_frame, true, false);
    lifo_stack.push(page_num);

    num_replacements++;
    return victim;
}

void LIFOReplacement::touch_page(int page_num) {
    touches++;
}
