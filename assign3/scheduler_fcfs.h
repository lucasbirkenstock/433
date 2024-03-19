/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.h
 * @author Lucas Birkenstock, Connor Toro
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#ifndef ASSIGN3_SCHEDULER_FCFS_H
#define ASSIGN3_SCHEDULER_FCFS_H

#include "scheduler.h"
/**
 * @brief This Scheduler class implements the FCFS scheduling algorithm.
 */
class SchedulerFCFS : public Scheduler {
private:
    // TODO: add necessary member variables here for your implementation

public:

    // Readyqueue
    deque<PCB> readyqueue;

    // process array
    std::vector<PCB> process_array;

    // Statistic variables
    int avg_turnaround_time = 0;
    int avg_waiting_time = 0;
    int current_time = 0;
    std::vector<int> turnaround_time_arr;
    std::vector<int> waiting_time_arr;
   
    // Constructor 
    SchedulerFCFS();
    
    // Destructor
    ~SchedulerFCFS() override;

    /**
     * @brief This function is called once before the simulation starts.
     *        It is used to initialize the scheduler.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */
    void print_results() override;

    /**
     * @brief This function simulates the scheduling of processes in the ready queue.
     *        It stops when all processes are finished.
     */
    void simulate() override;
};
#endif //ASSIGN3_SCHEDULER_FCFS_H
