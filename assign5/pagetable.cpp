/**
* Assignment 5: Page replacement algorithms
 * @file pagetable.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief This class represents a traditional pagetable data structure.
 * @version 0.1
 */


#include "pagetable.h"

// Constrcutor

PageTable::PageTable(int num_pages) : pages(num_pages, PageEntry(-1, false, false)){
    
}

// Destructor
PageTable::~PageTable() {

}
