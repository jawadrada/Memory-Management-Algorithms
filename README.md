# Memory-Management-Algorithms

## **Overview**
This project presents a simulation designed to analyze and compare various memory management algorithms in the context of fixed-size partitions. It's an educational tool aimed at helping users understand how different memory allocation strategies work in operating systems, particularly in allocating resources to processes.

Process and Partition Management: The simulation manages a collection of processes and memory partitions, each represented by custom Process and MemoryPartition classes. These classes handle the details of each process and partition, such as size, status, and waste.

### **Algorithms**

1. Best Fit
How it Works: This algorithm searches the entire list of available memory segments and allocates the smallest block that is large enough to accommodate the process's size.
2. First Fit
How it Works: Similar to Best Fit, but instead of searching for the smallest suitable block, it allocates the first block that is large enough to hold the process.
3. Next Fit
How it Works: A variation of First Fit. It keeps track of where it is in the memory list. When a new process arrives, it starts searching from the last allocated point rather than starting from the beginning of the list.
4. Worst Fit
How it Works: Allocates the largest available memory block to the process.

### **Technolgy Required**
This project requires the c++ programming language. Additionally, an Integrated Development Environment (IDE) capable of compiling and running c++ code is needed.

### **ScreenShot of Output**
<img width="525" alt="Screenshot 2023-12-20 at 6 36 33 PM" src="https://github.com/jawadrada/Memory-Management-Algorithms/assets/103535961/c79c9e3f-1c4c-41a8-87ef-09d73f7cab06">
