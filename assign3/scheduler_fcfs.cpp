/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Lucas Birkenstock, Connor Toro
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */

// TO TEST: ./fcfs schedule.txt

#include "scheduler_fcfs.h"
#include <deque>
#include "pcb.h"


    

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

    // Initialize member variable array to function input
    void SchedulerFCFS::init(std::vector<PCB>& process_list){
        process_array = process_list;
    };

    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */

    // Print turnaround + waiting time of EACH process, AND the average turnaround/waiting times
    void SchedulerFCFS::print_results() {
        // Calculate

        // Get sum of all waiting times
        for (int val : waiting_time_arr) {
            avg_waiting_time += val;
        }
        // Divide sum of waiting times by number of elements for the average
        avg_waiting_time = avg_waiting_time / waiting_time_arr.size();

        // Get sum of all turnaround times
        for (int val : turnaround_time_arr) {
            avg_turnaround_time += val;
        }

        // calculate average from sum
        avg_turnaround_time = avg_turnaround_time / turnaround_time_arr.size();

        // Print
        cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
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

        // Process number for printing results
        int proc_num = 1;

        // While queue isn't empty:
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
            
            std::cout << "T" << proc_num << " turn-around time = " << turnaround_time_arr.back() << ", waiting time = " << waiting_time_arr.back() << endl;
            proc_num++;
        }


    }