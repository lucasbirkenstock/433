/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */


#include "scheduler_fcfs.h"
#include <deque>
#include "pcb.h"


    // Readyqueue
    deque<PCB> readyqueue;

    // Process array
    std::vector<PCB> process_array;

    

    // Statistic variables
    int avg_turnaround_time = 0;
    int avg_waiting_time = 0;
    int current_time = 0;
    std::vector<int> turnaround_time_arr;
    std::vector<int> waiting_time_arr;

    // Constructor 
    SchedulerFCFS::SchedulerFCFS() {

    }
   
    // Destructor 
    SchedulerFCFS::~SchedulerFCFS() {

    }

    /**
     * @brief This function is called once before the simulation starts.
     *        It is used to initialize the scheduler.
     * @param process_list The list of processes in the simulation.
     */
    void SchedulerFCFS::init(std::vector<PCB>& process_list){
        process_array = process_list;
    };

    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */

    // Print turnaround + waiting time of EACH process, AND the average turnaround/waiting times
    void SchedulerFCFS::print_results() {

    }

    /**
     * @brief This function simulates the scheduling of processes in the ready queue.
     *        It stops when all processes are finished.
     */
    void SchedulerFCFS::simulate() {
        // Copy process array to readyqueue
        for (PCB process : this->process_array) {
            readyqueue.push_back(process);
        }

        while (!readyqueue.empty()) {
            // Copy first PCB in RQ and remove it from the queue
            PCB current_process = readyqueue.front();
            readyqueue.pop_front();

            // Add to waiting time array before updating variable from burst time
            waiting_time_arr.push_back(current_time);

            // Add burst time of current process to global time counter
            current_time += current_process.burst_time;

            // Add to turnaround time array after current_time is updated
            turnaround_time_arr.push_back((current_time - current_process.arrival_time));
            
        }


    }