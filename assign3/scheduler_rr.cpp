/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author Lucas Birkenstock and Connor Toro
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"
#include <list>
#include <map>


    // Constructor
    SchedulerRR::SchedulerRR(int time_quantum) {
        // default time quantum of 10 may need to be reiterated here
        tq = time_quantum;
    }

    // Destructor
    SchedulerRR::~SchedulerRR() {

    }

    void SchedulerRR::init(std::vector<PCB>& process_list) {
        // Copy parameter PCBs into member variable data structure
        for(PCB pcb : process_list) {
            pcb_list.push_back(pcb);
            // Also map PCB name to its burst time
            time_map[pcb.name] = pcb.burst_time;
        }
    }

    void SchedulerRR::print_results() {
        // Calculate averages and print them out
        double avg_turnaround_time = total_turnaround_time / time_map.size();
        double avg_waiting_time = total_waiting_time / time_map.size();
        cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
    }

    void SchedulerRR::simulate() {
        // While there are still processes left to execute
        while(num_done < pcb_list.size()) {

            // For each process in the list,
            for(PCB& pcb : pcb_list) {

                // If the remaining burst time is 0, skip/do nothing
                if(pcb.burst_time == 0) {
                    cout << "skipping " << pcb.name << ", burst time = 0. time = " << time << endl;
                    
                    // If the burst time is less than the time quantum
                } else if(pcb.burst_time <= tq) {
                    // Update statistical variables and print individual stats
                    time += pcb.burst_time;
                    pcb.burst_time = 0;
                    cout << pcb.name << " turn-around time = " << time << ", waiting time = " << time - time_map[pcb.name] << endl;
                    total_turnaround_time += time;
                    total_waiting_time += time - time_map[pcb.name];

                    // Increment loop var
                    num_done++;

                    // If burst time is larger than the TQ:
                } else {
                    
                    // Update stat vars
                    pcb.burst_time = pcb.burst_time - tq;
                    time += tq;
                    cout << pcb.name << " went for 10 seconds, moving on time = " << time << endl;
                }
            }
        }
    }
