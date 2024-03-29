/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author Lucas Birkenstock and Connor Toro
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code


#include "scheduler_priority.h"
#include "pcb.h"
#include <vector>
#include <algorithm>



// Constructor
SchedulerPriority::SchedulerPriority() {

}

// Destructor
SchedulerPriority::~SchedulerPriority() {

}

 void SchedulerPriority::init(std::vector<PCB>& process_list) {
    // Copy parameter to member variable
    for(PCB pcb : process_list) {
        sorted_list.push_back(pcb);
    }

    // Sort the member variable data structure according to priority of each PCB
    std::sort(sorted_list.begin(), sorted_list.end(), compare_pcb);
 }

void SchedulerPriority::print_results() {
    // Calculate averages and print them out
    double avg_turnaround_time = total_turnaround_time / sorted_list.size();
    double avg_waiting_time = total_waiting_time / sorted_list.size();
    cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
}

void SchedulerPriority::simulate() {
    // For each process in the list,
    for(PCB pcb : sorted_list) {
        // Update statistical variables
        turnaround_time += pcb.burst_time;
        cout << pcb.name << " turn-around time = " << turnaround_time << ", waiting time = " << waiting_time << endl;
        waiting_time += pcb.burst_time;
        total_turnaround_time += turnaround_time;
    }
    total_waiting_time = total_turnaround_time - turnaround_time;
}

// Helper function for sorting PCB lists
bool SchedulerPriority::compare_pcb(PCB a, PCB b) {
    return a.priority > b.priority;
}

