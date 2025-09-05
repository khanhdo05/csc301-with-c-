/*
 * CSC-301
 * worksheet2.hpp
 * Fall 2025
 * Eric A. Autry
 * 09/02/25
 */

#ifndef WORKSHEET2_HPP_
#define WORKSHEET2_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <chrono>

/*
 * findMax: finds and returns the maximum double in a vector of doubles.
 *
 * INPUTS
 * vector<double> vec: the vector of doubles.
 *
 * OUTPUTS
 * double max: the max element in the input vector.
 */
double findMax(std::vector<double> &vec);

/*
 * fibRec: recursively finds and returns the nth Fibonacci number.
 *
 * INPUTS
 * int n: which Fibonacci number to return.
 *
 * OUTPUTS
 * int: the nth Fibonacci number.
 */
int fibRec(int n);

/*
 * fibIter: iteratively finds and returns the nth Fibonacci number.
 *
 * INPUTS
 * int n: which Fibonacci number to return.
 *
 * OUTPUTS
 * int: the nth Fibonacci number.
 */
int fibIter(int n);/*
 * printHanoi: returns a string to print the ascii Hanoi puzzle's current state.
 *
 * INPUTS
 * vector<vector<int>> prongs: the prongs as vectors of block sizes.
 *
 * OUTPUTS
 * hanoiS.str(): the ascii drawing as a string to print.
 */
std::string printHanoi(std::vector<std::vector<int>> &prongs);

/*
 * move: moves the top block from a src prong to a dest prong.
 *
 * INPUTS
 * int src: the index of the src prong.
 * int dest: the index of the dest prong.
 * vector<vector<int>> prongs: the prongs as vectors of block sizes.
 * int &work: an int (reference) to track work.
 * bool toPrint: a flag to allow printing.
 *
 * OUTPUTS
 * Side Effect: the last (top) element of the src prong will be removed and 
 *              added to the rear of the dest prong.
 * Side Effect: work is incremented.
 * Side Effect: will print tower if printing enabled.
 */
void move(int src, int dest, std::vector<std::vector<int>> &prongs, int &work,
          bool toPrint);

/*
 * Hanoi: moves the top k blocks from src to dest, using swap as swap space.
 *
 * INPUTS
 * int k: the number of blocks to move (k>0).
 * int src: the index of the src prong.
 * int dest: the index of the dest prong.
 * int swap: the index of the swap prong.
 * vector<vector<int>> prongs: the prongs as vectors of block sizes.
 * int &work: an int (reference) to track work.
 * bool toPrint: a flag to allow printing.
 *
 * OUTPUTS
 * Side Effect: the last (top) k elements of the src prong will be removed and 
 *              added to the rear of the dest prong.
 * Side Effect: work is incremented for each move.
 * Side Effect: will print tower if printing enabled.
 */
void Hanoi(int k, int src, int dest, int swap, 
           std::vector<std::vector<int>> &prongs, int &work, bool toPrint);

/* main
 * 
 * Runs all examples/problems and prints the results.
 *
 * Compile with:
 *
 *     make
 *
 * Run with:
 *
 *     worksheet2
 *
 */
int main(int argc, char* argv[]);

#endif  // WORKSHEET2_HPP_