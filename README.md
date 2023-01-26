# pi Estimation using Monte Carlo method

One method to estimate the value of π (3.141592…) is by using a Monte Carlo method. This
method consists of drawing on a canvas a square with an inner circle. We then generate a large
number of random points within the square and count how many fall in the enclosed circle.
We ask you to propose an implementation in C or
  .C++ of this algorithm respecting the following aspects.
  .Write the program in two separates files “main*” and “helpers*” (contains the method to
  .generate the random values and the one to check if a point is inside a circle)
  .The program needs to be compiled using GNU make.
  .In the implementation, you use the maximum number of threads that your computer can
  .run concurrently. These threads must be created using the function “pthread_create”
  .from the pthread library.
  .Before displaying pi, print the “circle_count” value of each thread.
  
**Output**. During your program execution, monitor the cpu and memory usage as well as the
execution time. Save this information and the program output in a “result.txt” file.
For this exercise, you must submit the source code and the “result.txt” file.  

## Exercice_01_Group_3
------------

This folder is the requested output for the Exercice: Pi ESTIMATION.

It comprises:
 * source_code_Group_3: A folder which contains:
 	- helpers.cpp
 	- main.cpp
 	- Makefile
 	- main.bin: the binary file (executable)
 
 * result_01_Group_3: A text file which contains the standard output main.bin execution
