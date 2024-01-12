#ifndef PROCESS_H
#define PROCESS_H

#include <string>
using namespace std;

class Process {
public:
    Process();
    Process(string jobId, string jobStatus, string partitionId, int waste, int size);
    
    string getJobId();
    void setJobId(string jobId);
    string getJobStatus();
    void setJobStatus(string jobStatus);
    string getPartitionId();
    void setPartitionId(string partitionId);
    int getWaste();
    void setWaste(int waste);
    int getSize();
    void setSize(int size);

private:
    string jobId;
    string jobStatus;
    string partitionId;
    int waste;
    int size;
};

#endif // PROCESS_H

