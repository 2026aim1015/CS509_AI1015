# Assignment 01 
 General Matrix Multiplication(GEMM)

## Assignment Type 
 Single

## Objective 
 The objective of this assignment is to implement and compare two matrix multiplication techniques that is Simple General Matrix Multiplication (GEMM) and Blocked GEMM.We will measure the execution time of both algorithms with different matrix sizes to compare their performance.

## Algorithm
# Simple GEMM 
 Simple GEMM computes each output element one by one using a direct row-by-column dot product. It is easy to write but highly inefficient because it constantly re-fetches data from slow main memory for every single math operation.
 
# Block GEMM 
 Block GEMM algorithm divides large matrices into smaller sub-matrices called blocks or tiles to load them into high-speed CPU or GPU cache memory, maximizing data reuse and performance.

## Input Format
Each file is given to driver as:
m k n

Matrix_A (m × k)

Matrix_B (k × n)

where 
m is number of column in Matrix_A ,
k is number of column in Matrix_A and is number of row in Matrix_B ,
n is number of column in Matrix_B

## Assumptions

- The dimensions of the matrices (`m`, `k`, and `n`) are all positive integers.
- The number of columns in Matrix A is the same as the number of rows in Matrix B.
- All element in the matrices are integers.
- Input files follow the specified format.
- The execution time measures matrix multiplication algorithm.

## Constraints

- The matrix dimensions should be greater than zero.
- Matrix multiplication is performed only when the number of columns in Matrix A matches the number of rows in Matrix B.
- The program accepts integer values as matrix elements.
- Both small and large matrices can be processed. In this assignment, test cases up to (500 × 500 × 500) are used.
- the result is saved in the outputs folder .

## Source File

- gemm_simple.cpp: Implements the simple GEMM algorithm 

- gemm_blocking.cpp: Implements the Blocking GEMM algorithm. 

- gemm_simple.h: Contains the function declaration for the Simple GEMM implementation.

- gemm_blocking: Contains the function declaration for the Blocking GEMM implementation.

## Driver File
The driver.cpp file is the main program of the assignment. It reads the input from a test file, checks the matrix dimensions, calls both the Simple GEMM and Blocking GEMM functions, measures their execution time, and saves the results in the outputs folder.

## Test File

- test_01.txt : 2 x 3 x 2 Basic matrix multiplication.
- test_02.txt : 10 x 50 x20 Rectangular matrix multiplication.
- test_03.txt : 10 × 5 × 19 Rectangular matrix multiplication with large values.
- test_04.txt : 10 x 10 x 10 matrix multiplication.
- test_05.txt : 50 x 50 x 50 matrix multiplication.
- test_06.txt : 100 x 100 x 100 matrix multiplication.
- test_07.txt : 200 x 200 x 200 matrix multiplication.
- test_08.txt : 10 x 10 x 10 Matrix with negative values
- test_09.txt : 100 x 50 x 20 matrix multiplication.
- test_10.txt : 500 x 500 x 500 matrix multiplication.

## Compilation and Execution

Open a terminal in the assignment_01 directory and compile the program using:
g++ -std=c++17 driver/main.cpp src/*.cpp ../common_wrapper/wrapper.cpp -o driver

This command compiles the driver program, source files, and the common wrapper into a single executable named driver.

## Execution
After successful compilation, run the executable.
driver.exe

The program reads the input from the test file, performs matrix multiplication using both Simple GEMM and Blocked GEMM, displays the results, and records the execution time of each algorithm.

## Results

The following table summarizes the results obtained after executing both Simple GEMM and Blocked GEMM on all the test cases.

| Test File | Matrix Size (m × k × n) | Simple GEMM Time (μs) | Blocked GEMM Time (μs) |
|-----------|-------------------------|----------------------:|-----------------------:|
| test_01.txt | 2 × 3 × 2 | 0 | 0 |
| test_02.txt | 10 × 50 × 20 | 0 | 0 |
| test_03.txt | 10 × 5 × 19 | 0 | 0 |
| test_04.txt | 10 × 10 × 10 | 0 | 0 |
| test_05.txt | 50 × 50 × 50 | 1,994 | 997 |
| test_06.txt | 100 × 100 × 100 | 14,960 | 12,965 |
| test_07.txt | 200 × 200 × 200 | 139,721 | 114,495 |
| test_08.txt | 10 × 10 × 10 (Negative Values) | 0 | 0 |
| test_09.txt | 100 × 50 × 20 | 1,996 | 1,040 |
| test_10.txt | 500 × 500 × 500 | 1,805,172 | 1,667,540 |

## Time and Space Complexity
- Simple GEMM
    Time Complexity: O(m × k × n)
    Space Complexity: O(m × n)
- Blocked GEMM
    Time Complexity: O(m × k × n)
    Space Complexity: O(m × n) 

    Although both algorithms have the same theoretical time complexity, Blocked GEMM performs better for larger matrices because it makes better use of the processor cache.