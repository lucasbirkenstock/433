/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code


#include "scheduler_priority.h"
#include "pcb.h"
#include <vector>
#include <algorithm>

// TODO: add implementation of SchedulerPriority constructor, destrcutor and
// member functions init, print_results, and simulate here


// Constructor
SchedulerPriority::SchedulerPriority() {

}

// Destructor
SchedulerPriority::~SchedulerPriority() {

}

 void SchedulerPriority::init(std::vector<PCB>& process_list) {
    for(PCB pcb : process_list) {
        sorted_list.push_back(pcb);
    }
    std::sort(sorted_list.begin(), sorted_list.end(), compare_pcb);
 }

void SchedulerPriority::print_results() {
    double avg_turnaround_time = total_turnaround_time / sorted_list.size();
    double avg_waiting_time = total_waiting_time / sorted_list.size();
    cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
}

void SchedulerPriority::simulate() {
    for(PCB pcb : sorted_list) {
        turnaround_time += pcb.burst_time;
        cout << pcb.name << " turn-around time = " << turnaround_time << ", waiting time = " << waiting_time << endl;
        waiting_time += pcb.burst_time;
        total_turnaround_time += turnaround_time;
    }
    total_waiting_time = total_turnaround_time - turnaround_time;
}

bool SchedulerPriority::compare_pcb(PCB a, PCB b) {
    return a.priority > b.priority;
}

