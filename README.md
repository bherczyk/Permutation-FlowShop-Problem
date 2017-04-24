# Permutation Flow-Shop Problem

### Introduction
Author: Bartosz Herczyk 

Requirements: C++

Program to solve the permutation flow-shop problem using NEH algorithm.


### Problem
The Flow-Shop problem is an NP-hard problem. There are m machinses and n jobs. Each job contains exactly m operations. 
The i-th operation of the job must be executed on the i-th machine. No machine can perform more than one operation 
simultaneously. For each operation of each job, execution time is specified. Operations within one job must be performed in 
the specified order. The first operation gets executed on the first machine, then (as the first operation is finished) the second 
operation on the second machine, and so until the n-th operation. Jobs can be executed in any order, however. 
Problem definition implies that this job order is exactly the same for each machine. The problem is to determine the optimal such 
arrangement, i.e. the one with the shortest possible total job execution makespan.





**Computational complexity - O(n!)**

### NEH algorithm

**Step 1** Order the jobs by non-increasing sums of precessing times on the machines

**Step 2** Take the first two jobs and schedule them in order to minimise the partial makespan as if there were only these jobs

**Step 3** For k = 3 to n do **Step 4**

**Step 4** Insert the *k*th job at the place, which minimises the partial makespan among the k possible ones.





**Computational complexity - O(n(n+1)/2-1)**
