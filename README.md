# Bank Simulation
Simulation of a bank queue using a queue and a priority queue data structures in C++.
The program reads a file of customers with their arrival time and the duration of their stay.
It simulates a bank queue with one teller in duty and computes the total number of customers processed
and average waiting time for each customer.

**Example of an input file** (first column: arrival time, second column: duration of stay)
```
1 5
2 5
4 5
20 5
22 5
24 5
26 5
28 5
30 5
88 3

```

**Expected output**
```
Processing an arrival event at time: 1
Processing an arrival event at time: 2
Processing an arrival event at time: 4
Processing a departure event at time: 6
Processing a departure event at time: 11
Processing a departure event at time: 16
Processing an arrival event at time: 20
Processing an arrival event at time: 22
Processing an arrival event at time: 24
Processing a departure event at time: 25
Processing an arrival event at time: 26
Processing an arrival event at time: 28
Processing an arrival event at time: 30
Processing a departure event at time: 30
Processing a departure event at time: 35
Processing a departure event at time: 40
Processing a departure event at time: 45
Processing a departure event at time: 50
Processing an arrival event at time: 88
Processing a departure event at time: 91
Total number of customers processed: 10
Average amount of time spent waiting: 5.6
```
