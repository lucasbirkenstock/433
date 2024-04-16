/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author ??? (TODO: your name)
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;

// global buffer object
Buffer buffer;

pthread_mutex_t mutex;

// Producer thread function
// TODO: Add your implementation of the producer thread here
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);

    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);
        // TODO: Add synchronization code here

        // Lock the thread
        pthread_mutex_lock(&mutex);
        //
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }

        
    }
    // Unlock the thread
    pthread_mutex_unlock(&mutex);
}

// Consumer thread function
// TODO: Add your implementation of the consumer thread here
void *consumer(void *param) {
    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);
        // TODO: Add synchronization code here

        // Lock the thread
        pthread_mutex_lock(&mutex);

        if (buffer.remove_item(&item)) {
            cout << "Consumer " << item << ": Removed item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Consumer error condition" << endl;    // shouldn't come here
        }
    }
    // Unlock the thread
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[]) {
    /* TODO: 1. Get command line arguments argv[1],argv[2],argv[3] */
    if (argc == 4) {
        //------------------------------- TODO may need to convert these to int --------------------------
        char* sleep_time = argv[1]; // How long main thread sleeps before terminating (seconds)
        char* num_producers = argv[2]; 
        char* num_consumers = argv[3]; 
    } else {
        // Print error if there is an incorrect number of inputs
        std::cerr << "Usage" << argv[0] << " <arg1> <arg2> <arg3>" << std::endl;
    }
    /* TODO: 2. Initialize buffer and synchronization primitives */
    Buffer theBuffer = Buffer(5);
    /* TODO: 3. Create producer thread(s).
     * You should pass an unique int ID to each producer thread, starting from 1 to number of threads */
    /* TODO: 4. Create consumer thread(s) */
    /* TODO: 5. Main thread sleep */
    /* TODO: 6. Exit */
}
