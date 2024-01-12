#include "Process.h"

Process::Process() {
    jobId = "-";
    jobStatus = "waiting";
    partitionId = "-";
    waste = 0;
    size = 0;
}

Process::Process(string jobId, string jobStatus, string partitionId, int waste, int size) {
    this->jobId = jobId;
    this->jobStatus = jobStatus;
    this->partitionId = partitionId;
    this->waste = waste;
    this->size = size;
}

string Process::getJobId() {
    return jobId;
}

void Process::setJobId(string jobId) {
    this->jobId = jobId;
}

string Process::getJobStatus() {
    return jobStatus;
}

void Process::setJobStatus(string jobStatus) {
    this->jobStatus = jobStatus;
}

string Process::getPartitionId() {
    return partitionId;
}

void Process::setPartitionId(string partitionId) {
    this->partitionId = partitionId;
}

int Process::getWaste() {
    return waste;
}

void Process::setWaste(int waste) {
    this->waste = waste;
}

int Process::getSize() {
    return size;
}

void Process::setSize(int size) {
    this->size = size;
}

