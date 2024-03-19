/**
* Assignment 3: CPU Scheduler
 * @file scheduler.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief Cpp file for scheduler    
 * @version 0.1
 */

#pragma once


#include "scheduler.h"
#include "scheduler_fcfs.h"

class Scheduler {
    public: 
        std::vector<PCB> process_array;

        Scheduler() {

        }

        ~Scheduler() {

        }

        // Copy inputs into process_array member variable
        void init(std::vector<PCB>& process_list) {
            process_array = process_list;
        }

        void print_results() {

        }

        // Adds processes to FCFS
        void simulate() {
            // Create FCFS scheduler object, init process array
            SchedulerFCFS fcfs_obj = SchedulerFCFS();
            fcfs_obj.init(process_array);

            // Simulate the FCFS algorithm
            fcfs_obj.simulate();

        }


};


