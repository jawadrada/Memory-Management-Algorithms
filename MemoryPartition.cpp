#include "MemoryPartition.h"

MemoryPartition::MemoryPartition() {
    partitionId = "-";
    jobId = "-";
    isInUse = false;
    size = 0;
}

MemoryPartition::MemoryPartition(string partitionId, string jobId, bool isInUse, int size) {
    this->partitionId = partitionId;
    this->jobId = jobId;
    this->isInUse = isInUse;
    this->size = size;
}

string MemoryPartition::getPartitionId() {
    return partitionId;
}

void MemoryPartition::setPartitionId(string partitionId) {
    this->partitionId = partitionId;
}

string MemoryPartition::getJobId() {
    return jobId;
}

void MemoryPartition::setJobId(string jobId) {
    this->jobId = jobId;
}

bool MemoryPartition::getIsInUse() {
    return isInUse;
}

void MemoryPartition::setIsInUse(bool isInUse) {
    this->isInUse = isInUse;
}

int MemoryPartition::getSize() {
    return size;
}

void MemoryPartition::setSize(int size) {
    this->size = size;
}

