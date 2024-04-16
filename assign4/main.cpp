/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

// global buffer object
Buffer buffer;

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

// Producer thread function
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);

    while (true) {
        /* sleep for a random period of time */
        //cout << "Producer " << item << ": sleeping..." << endl;
        usleep(rand() % 1000000 + 1);
        //cout << "Producer " << item << ": woke up!" << endl;
        // TODO: Add synchronization code here

        //wait until room in buffer
        //cout << "Producer " << item << ": Waiting for full semaphore" << endl;
        sem_wait(&full);
        //cout << "Producer " << item << ": passed full semaphore" << endl;

        // Lock the thread
        //cout << "Producer " << item << ": Waiting for mutex lock" << endl;
        pthread_mutex_lock(&mutex);
        //cout << "Producer " << item << ": Mutex locked" << endl;

        //
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }

        // Unlock the thread
        pthread_mutex_unlock(&mutex);

        //signal filled slot
        sem_post(&empty);
    }
}

// Consumer thread function
void *consumer(void *param) {
    buffer_item item;
    int id = *((int *)param);

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000 + 1);

        // wait while empty
        sem_wait(&empty);

        // Lock the thread
        pthread_mutex_lock(&mutex);

        if (buffer.remove_item(&item)) {
            cout << "Consumer " << id << ": Removed item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Consumer: " << id << " error condition" << endl;    // shouldn't come here
        }

        // Unlock the thread
         pthread_mutex_unlock(&mutex);

        //increment full semaphore
        sem_post(&full);
    }
}

int main(int argc, char *argv[]) {
    /* 1. Get command line arguments argv[1],argv[2],argv[3] */
    if (argc == 4) {
        int sleep_time = std::stoi(argv[1]);    // How long main thread sleeps before terminating (seconds)
        int num_producers = std::stoi(argv[2]); // Convert input to int
        int num_consumers = std::stoi(argv[3]); // Convert input to int

        /* TODO: 2. Initialize buffer and synchronization primitives */
        Buffer theBuffer = Buffer(5);
        pthread_mutex_init(&mutex, NULL);
        sem_init(&empty, 0, 0);
        sem_init(&full, 0, 5);

        /* TODO: 3. Create producer thread(s).
        * You should pass an unique int ID to each producer thread, starting from 1 to number of threads */

        // Create an array of pthread identifiers to identify the producer threads which will be created
        pthread_t producer_threads[num_producers];

        for (int i = 1; i <= num_producers; ++i) {
            int* id = new int(i);
            pthread_create(&producer_threads[i - 1], NULL, producer, (void *)id);
        }


        /* TODO: 4. Create consumer thread(s) */
        // Create an array of pthread identifiers to identify the consumer threads which will be created
        pthread_t consumer_threads[num_consumers];

        for (int i = 1; i <= num_consumers; ++i) {
            // Create a consumer thread
            // Access index i-1 of the identifier array (because this loop starts at 1)
            // NULL specifies default thread attributes
            // Point to consumer function
            // Idk the last one
            int* id = new int(i);
            pthread_create(&consumer_threads[i - 1], NULL, consumer, (void *)id);
        }
        /* 5. Main thread sleep */
        sleep(sleep_time);


    } else {
        // Print error if there is an incorrect number of inputs
        std::cerr << "Usage" << argv[0] << " <arg1> <arg2> <arg3>" << std::endl;
    }


    /* TODO: 6. Exit */
    exit(0);
}
