/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */


#include "scheduler_fcfs.h"
#include <queue>
#include "pcb.h"

class SchedulerFCFS {

public:
    // Readyqueue
    queue<PCB> readyqueue;

    // Process array
    std::vector<PCB> process_array;

    // Statistic variables
    int avg_turnaround_time = 0;
    int avg_waiting_time = 0;

    // Constructor 
    SchedulerFCFS() {

    }
   
    // Destructor 
    ~SchedulerFCFS() {

    }

    /**
     * @brief This function is called once before the simulation starts.
     *        It is used to initialize the scheduler.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list){
        process_array = process_list;
    };

    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */
    void print_results() {

    }

    /**
     * @brief This function simulates the scheduling of processes in the ready queue.
     *        It stops when all processes are finished.
     */
    void simulate() {
        
    }

};
