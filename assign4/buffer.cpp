/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author ??? (TODO: your name)
 * @brief Implementation file for the buffer class
 * @version 0.1
 */


#include "buffer.h"
#include <iostream>


// Constructor 
Buffer::Buffer(int size) {
    // Initialize out/in, and create data array to be sized of the input
    this->out = 0;
    this->in = 0;
    this->data = new buffer_item[size];
}

// Destructor 
Buffer::~Buffer() {
    delete[] data;
}

bool Buffer::insert_item(buffer_item item) {

    // If the buffer isn't full:
    if (!is_full()) {
        // Insert the element at in, increment in, return true;
        data[in] = item;
        in = (in + 1) % get_count();
        num_elements++;
        return true;
    } else { 
        // If buffer is full, return false.
        return false;
    }
}

 bool Buffer::remove_item(buffer_item *item) {
    if (is_empty()) {
        return false; 
    }

    //buffer_item removed_item = data[out];
    out = (out + 1) % get_count();
    num_elements--;
    return true;
    
 }


// Helper functions //

// Bounded buffers are empty if in == out
bool Buffer::is_empty() {
    return in == out;
}

// Buffer is full if in is one slot behind out
bool Buffer::is_full() {
    return (((in + 1) % get_count()) == out);
}

int Buffer::get_count() {
    return num_elements;
}

void Buffer::print_buffer() {
    std::cout << "Buffer[";

    int index = out;

    while (index != in - 1) {
        // Print everything except the last filled element
        std::cout << data[index] << ", ";
        index++;
    }

    // Print last element
    std::cout << data[++index] << "]" << std::endl;
}