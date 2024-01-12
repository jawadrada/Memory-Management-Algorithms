#ifndef MEMORY_PARTITION_H
#define MEMORY_PARTITION_H

#include <string>
using namespace std;

class MemoryPartition {
public:
    MemoryPartition();
    MemoryPartition(string partitionId, string jobId, bool isInUse, int size);
    
    string getPartitionId();
    void setPartitionId(string partitionId);
    string getJobId();
    void setJobId(string jobId);
    bool getIsInUse();
    void setIsInUse(bool isInUse);
    int getSize();
    void setSize(int size);

private:
    string partitionId;
    string jobId;
    bool isInUse;
    int size;
};

#endif // MEMORY_PARTITION_H

