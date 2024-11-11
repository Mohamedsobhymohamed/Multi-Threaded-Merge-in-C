# Multithreaded Merge Sort in C

This project implements the merge sort algorithm in C, with both a traditional single-threaded version and a multithreaded version using POSIX threads (pthread). The program reads an array of integers from a file, sorts it using the merge sort algorithm, and outputs the sorted array.
Features

    Normal Merge Sort: A traditional merge sort implementation that sorts the array using a single thread.
    Multithreaded Merge Sort: A parallelized version of merge sort that utilizes multiple threads to sort the array more efficiently.
    File Input: The program reads the input array from a file, making it easy to test with different datasets.

# Requirements

    GCC (GNU Compiler Collection) or compatible C compiler
    POSIX threads (pthread) library for the multithreaded version
    A file containing the array to be sorted in the format:
        The first line contains the number of elements.
        The second line contains the list of integers to be sorted.

# Compilation & Usage
Compilation

To compile the program, run the following command in your terminal:

make

This will create the following executables:

    normal_sort: The non-threaded (standard) merge sort.
    thread_sort: The multithreaded merge sort.

Running the Program

To run the normal (single-threaded) merge sort:

make merge

To run the multithreaded merge sort:

make thread

Input Format

The program expects an input file called input with the following format:

11
100 20 15 3 4 8 7 -1 0 33 55

Where the first line contains the number of elements (in this case, 11), and the second line contains the integers to be sorted.
Output

After sorting, the program will print the sorted array to the console:

Sorted array:
-1 0 3 4 7 8 15 20 33 55 100

# Example

    Prepare your input file (e.g., input):

11
100 20 15 3 4 8 7 -1 0 33 55

Run the normal merge sort:

make merge

Run the multithreaded merge sort:

make thread
