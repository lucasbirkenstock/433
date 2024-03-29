/**
* Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author Lucas Birkenstock and Connor Toro
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"
#include "pcb.h"
#include <vector>
#include <algorithm>



        // Constructor
        SchedulerSJF::SchedulerSJF() {

        }

        // Destructor
        SchedulerSJF::~SchedulerSJF() {

        }

        void SchedulerSJF::init(std::vector<PCB>& process_list) {
            // Copy input to member var data structure
            for(PCB pcb : process_list) {
                sorted_list.push_back(pcb);
            }
            // Sort the list based on PCB burst time with helper function
            std::sort(sorted_list.begin(), sorted_list.end(), compare_pcb);
        }

        void SchedulerSJF::print_results() {
            // Calculate averages and print stats
            double avg_turnaround_time = total_turnaround_time / sorted_list.size();
            double avg_waiting_time = total_waiting_time / sorted_list.size();
            cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
        }

        void SchedulerSJF::simulate() {
            // For each PCB in the sorted list,
            for(PCB pcb : sorted_list) {
                // Update stat vars
                turnaround_time += pcb.burst_time;
                cout << pcb.name << " turn-around time = " << turnaround_time << ", waiting time = " << waiting_time << endl;
                waiting_time += pcb.burst_time;
                total_turnaround_time += turnaround_time;
            }
            total_waiting_time = total_turnaround_time - turnaround_time;
        }

        // Helper function for the init function
        bool SchedulerSJF::compare_pcb(PCB a, PCB b) {
            return a.burst_time < b.burst_time;
        }
