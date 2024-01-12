/*
Memory Managment Project
Created by Jawad Rada
Date: 10/14/23.
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include "Process.h"
#include "MemoryPartition.h"

using namespace std;

//fixed partitions
void bestFit(vector<Process>& processList, vector<MemoryPartition>& partitionList, int numJobs, int numPartitions) {
    for (int i = 0; i < numJobs; i++) {
        int bestIndex = -1;
        int bestWaste = 1000000;

        for (int j = 0; j < numPartitions; j++) {
            if (!partitionList[j].getIsInUse() && processList[i].getSize() <= partitionList[j].getSize()) {
                int waste = partitionList[j].getSize() - processList[i].getSize();

                if (waste < bestWaste) {
                    bestIndex = j;
                    bestWaste = waste;
                }
            }
        }

        if (bestIndex == -1) {
            
        }
        
        else {
            processList[i].setPartitionId(partitionList[bestIndex].getPartitionId());
            partitionList[bestIndex].setJobId(processList[i].getJobId());
            partitionList[bestIndex].setIsInUse(true);
            processList[i].setJobStatus("running");
            processList[i].setWaste(partitionList[bestIndex].getSize() - processList[i].getSize());
        }
    }
}

void firstFit(vector<Process>& processList, vector<MemoryPartition>& partitionList, int numJobs, int numPartitions){
    for(int i = 0; i < numJobs; i++){
        for(int j = 0; j < numPartitions; j++){
            if(processList[i].getSize() <= partitionList[j].getSize() && partitionList[j].getIsInUse() == false){
                partitionList[j].setIsInUse(true);
                partitionList[j].setJobId(processList[i].getJobId());

                processList[i].setJobStatus("running");
                processList[i].setPartitionId(partitionList[j].getPartitionId());
                processList[i].setWaste(partitionList[j].getSize() - processList[i].getSize());

                break;
            }
        }
    }
}



void nextFit(vector<Process>& processList, vector<MemoryPartition>& partitionList, int numJobs, int numPartitions){
    int lastIndex = 0;
    int numPartitionsChecked = 0;

    for (int i = 0; i < numJobs; i++){
        bool jobAssigned = false;

        for (int j = lastIndex; !jobAssigned && (numPartitionsChecked < numPartitions); j++){
            if (processList[i].getSize() <= partitionList[j].getSize() && !partitionList[j].getIsInUse()){
                partitionList[j].setIsInUse(true);
                partitionList[j].setJobId(processList[i].getJobId());

                processList[i].setJobStatus("running");
                processList[i].setPartitionId(partitionList[j].getPartitionId());
                processList[i].setWaste(partitionList[j].getSize() - processList[i].getSize());

                lastIndex = j;
                jobAssigned = true;
                numPartitionsChecked = 0;
            }
            else{
                if (j == numPartitions - 1){
                    j = -1;
                }
                numPartitionsChecked++;
            }
        }
    }
}

void worstFit(vector<Process>& processList, vector<MemoryPartition>& partitionList, int numJobs, int numPartitions) {
    map<int, int> subdivisionCounter;

    for (int i = 0; i < numJobs; i++) {
        int worstIndex = -1;
        int worstWaste = -1;

        for (int j = 0; j < numPartitions; j++) {
            if (processList[i].getSize() <= partitionList[j].getSize() && !partitionList[j].getIsInUse()) {
                int waste = partitionList[j].getSize() - processList[i].getSize();
                if (waste > worstWaste) {
                    worstWaste = waste;
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            partitionList[worstIndex].setIsInUse(true);
            partitionList[worstIndex].setJobId(processList[i].getJobId());
            processList[i].setPartitionId(partitionList[worstIndex].getPartitionId());
            processList[i].setJobStatus("running");

            MemoryPartition newPartition;
            newPartition.setSize(worstWaste);

            subdivisionCounter[worstIndex]++;
            char suffix = 'a' + (subdivisionCounter[worstIndex] - 1); 
            string newPartitionId = partitionList[worstIndex].getPartitionId() + suffix;
            newPartition.setPartitionId(newPartitionId);

            newPartition.setIsInUse(false);
            newPartition.setJobId("");

            partitionList.push_back(newPartition);
            partitionList[worstIndex].setSize(processList[i].getSize());

            numPartitions++;
        } else {
            processList[i].setJobStatus("waiting");
        }
    }
}

void switchAlgorithm(int num, vector<Process>& processList, vector<MemoryPartition>& partitionList, int numJobs, int numPartitions) {
    switch (num) {
        case 0:
            cout << "Best Fit" << endl;
            bestFit(processList, partitionList, numJobs, numPartitions);
            break;
        case 1:
            cout << "First Fit" << endl;
            firstFit(processList, partitionList, numJobs, numPartitions);
            break;
        case 2:
            cout << "Next Fit" << endl;
            nextFit(processList, partitionList, numJobs, numPartitions);
            break;
        case 3:
            cout << "Worst Fit" << endl;
            worstFit(processList, partitionList, numJobs, numPartitions);
            break;
        default:
            return;
    }
}

void output(){
    cout << left << setw(14) << "Process #" << setw(9) << "Size"
         << setw(16) << "Partition #" << setw(9) << "Size"
         << setw(10) << "Waste" << setw(4) << "Status" << endl;
    cout<<"----------------------------------------------------------------" << endl;
}

int data(int processes, vector<Process>& processList, vector<MemoryPartition>& partitionList){
    int waste = 0;
    for(int i = 0; i < processes; i++){
        string partitionId = processList.at(i).getPartitionId();
        int partitionSize = 0;

        for (int j = 0; j < partitionList.size(); j++) {
            if (partitionList[j].getPartitionId() == partitionId) {
                partitionSize = partitionList[j].getSize();
                break;
            }
        }

        cout << left << setw(14) << processList.at(i).getJobId() << setw(9) << processList.at(i).getSize()
            << setw(16) << partitionId << setw(9) << partitionSize << setw(10) << processList.at(i).getWaste()
            << setw(4) << processList.at(i).getJobStatus() << endl;

        waste += processList.at(i).getWaste();
    }
    return waste;
}

int main() {
    const int numAlgorithms = 4;
    int numProcesses;
    int numPartitions;
    vector<Process> processList;
    vector<MemoryPartition> partitionList;
    
    cout<<"Enter the number of Processes: ";
    cin >> numProcesses;
    cout<<"Enter the size for each Process: "<< endl;
    
    for (int i = 0; i < numProcesses; i++) {
        int size;
        cout<<"Process " << i + 1 <<" = ";
        cin>>size;
        processList.emplace_back(to_string(i + 1), "waiting", "-", 0, size);
    }
    
    cout<<"\nEnter the number of Partitions: ";
    cin >> numPartitions;
    cout<<"Enter the size for each Partition: "<< endl;
    
    for (int i = 0; i < numPartitions; i++) {
        int size;
        cout<<"Partition " << i + 1 <<" = ";
        cin>>size;
        partitionList.emplace_back(to_string(i + 1), "-", false, size);
    }
    
    cout <<endl;
    vector<Process> originalProcessList = processList;
    vector<MemoryPartition> originalPartitionList = partitionList;

      for (int i = 0; i < numAlgorithms; i++) {
          int totalWaste = 0;
          switchAlgorithm(i, processList, partitionList, numProcesses, numPartitions);
          output();
          totalWaste = data(numProcesses, processList, partitionList);
          cout << "Total Waste: " << totalWaste << endl << endl;

          processList = originalProcessList;
          partitionList = originalPartitionList;
      }
    
    return 0;
}
