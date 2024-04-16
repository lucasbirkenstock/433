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
    this->size = size;
    this->data = new buffer_item[size];
}

// Destructor
Buffer::~Buffer() {
    delete[] data;
}

//copy constructor
Buffer::Buffer(const Buffer& other) {
    // Copy size and allocate memory
    size = other.size;
    data = new buffer_item[size];

    // Copy elements
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }

    // Copy other attributes
    in = other.in;
    out = other.out;
    num_elements = other.num_elements;
}

//operator=
Buffer& Buffer::operator=(const Buffer& other) {
    if (this != &other) {  // Check for self-assignment
        // Delete existing data
        delete[] data;

        // Copy size and allocate memory
        size = other.size;
        data = new buffer_item[size];

        // Copy elements
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

        // Copy other attributes
        in = other.in;
        out = other.out;
        num_elements = other.num_elements;
    }
    return *this;
}

bool Buffer::insert_item(buffer_item item) {

    // If the buffer isn't full:
    if (!is_full()) {
        // Insert the element at in, increment in, return true;
        data[in] = item;
        in = (in + 1) % size;
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

    *item = data[out];
    out = (out + 1) % size;
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
    return (((in + 1) % size) == out);
}

int Buffer::get_count() {
    return num_elements;
}

void Buffer::print_buffer() {
    if(is_empty()) return;
    std::cout << "Buffer[";
    int index = 0;

    for(int i = 0; i < num_elements-1; i++) {
        index = (out + i)%size;
        std::cout << data[index] << ", ";
    }

    // Print last element
    std::cout << data[(index+1)%size] << "]" << std::endl;
}
