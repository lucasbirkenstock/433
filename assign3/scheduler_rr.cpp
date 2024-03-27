/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"
#include <list>
#include <map>

// TODO: add implementation of SchedulerRR constructor, destrcutor and
// member functions init, print_results, and simulate here

    // Constructor
    SchedulerRR::SchedulerRR(int time_quantum) {
        // TODO default time quantum of 10 may need to be reiterated here
        tq = time_quantum;
    }

    // Destructor
    SchedulerRR::~SchedulerRR() {

    }

    void SchedulerRR::init(std::vector<PCB>& process_list) {
        for(PCB pcb : process_list) {
            pcb_list.push_back(pcb);
            time_map[pcb.name] = pcb.burst_time;
        }
    }

    void SchedulerRR::print_results() {
        double avg_turnaround_time = total_turnaround_time / time_map.size();
        double avg_waiting_time = total_waiting_time / time_map.size();
        cout << "Average turn-around time = " << avg_turnaround_time << ", Average waiting time = " << avg_waiting_time << endl;
    }

    void SchedulerRR::simulate() {
        while(num_done < pcb_list.size()) {
            for(PCB& pcb : pcb_list) {

                if(pcb.burst_time == 0) {
                    cout << "skipping " << pcb.name << ", burst time = 0. time = " << time << endl;
                } else if(pcb.burst_time <= tq) {
                    time += pcb.burst_time;
                    pcb.burst_time = 0;
                    cout << pcb.name << " turn-around time = " << time << ", waiting time = " << time - time_map[pcb.name] << endl;
                    total_turnaround_time += time;
                    total_waiting_time += time - time_map[pcb.name];
                    num_done++;

                } else {
                    pcb.burst_time = pcb.burst_time - tq;
                    time += tq;
                    cout << pcb.name << " went for 10 seconds, moving on time = " << time << endl;
                }
            }
        }
    }
