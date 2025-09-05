/*
 * CSC-301
 * worksheet2.cpp
 * Fall 2025
 * Eric A. Autry
 * 09/02/25
 */

#include "worksheet2.hpp"

using namespace std;

/*
 * findMax: finds and returns the maximum double in a vector of doubles.
 *
 * INPUTS
 * vector<double> vec: the vector of doubles.
 *
 * OUTPUTS
 * double max: the max element in the input vector.
 */
double findMax(vector<double> &vec) {
    double max = -std::numeric_limits<double>::infinity(); // Negative Infinity
    for (int n=0; n<vec.size(); n++) {
        if (max < vec[n]) {
            max = vec[n];
        }
    }
    return max;
}

/*
 * fibRec: 
 */
int fibRec(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibRec(n-1) + fibRec(n-2);
}

/*
 * fibIter: 
 */
int fibIter(int n) {
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Most efficient:
// int fibIter(int n) {
//     int a = 0;
//     int b = 1;
//     for (int i = 0; i < n; i++) {
//         int temp = a + b;
//         a = b;
//         b = temp;
//     }

//     return a;
// }

/*
 * printHanoi: returns a string to print the ascii Hanoi puzzle's current state.
 *
 * INPUTS
 * vector<vector<int>> prongs: the prongs as vectors of block sizes.
 *
 * OUTPUTS
 * hanoiS.str(): the ascii drawing as a string to print.
 */
string printHanoi(vector<vector<int>> &prongs) {
    // Find number of prongs and total number of blocks.
    int numProngs = prongs.size();
    int numBlocks = 0;
    for (int i=0; i<numProngs; i++) {
        numBlocks += prongs[i].size();
    }

    // Create the stringstream for the drawing.
    stringstream hanoiS;

    // First row of the display, no blocks, 1 space between prongs, 
    // 1 space on either side of full display.
    hanoiS << " ";
    for (int p=0; p<numProngs; p++) {
        for (int b=0; b<numBlocks; b++) {
            hanoiS << " ";
        }
        hanoiS << "|";
        for (int b=0; b<numBlocks; b++) {
            hanoiS << " ";
        }
        hanoiS << " ";
    }
    hanoiS << endl;

    // Middle rows, one for each possible block.
    for (int b=numBlocks; b>0; b--) {
        // Left space for display.
        hanoiS << " ";

        // Loop over prongs and check if there is a block here.
        for (int p=0; p<numProngs; p++) {
            // Set printing size for block chars.
            int blockSize = 0;

            // Check if there is a block at this height.
            if (prongs[p].size() >= b) {
                blockSize = prongs[p][b-1];
            }

            // Set the number of spaces to print.
            int spaceSize = numBlocks-blockSize;

            // Print the block on this prong.
            for (int ch=0; ch<spaceSize; ch++) {
                hanoiS << " ";
            }
            for (int ch=0; ch<blockSize; ch++) {
                hanoiS << "-";
            }
            hanoiS << "|";
            for (int ch=0; ch<blockSize; ch++) {
                hanoiS << "-";
            }
            for (int ch=0; ch<spaceSize; ch++) {
                hanoiS << " ";
            }
            hanoiS << " ";
        }
        hanoiS << endl;
    }

    // Last row of display, all capital T.
    int fullWidth = 2 + (numProngs-1) + numProngs*(2*numBlocks+1);
    for (int ch=0; ch<fullWidth; ch++) {
        hanoiS << "T";
    }
    hanoiS << endl;

    // Return as a string.
    return hanoiS.str();
}

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
void move(int src, int dest, vector<vector<int>> &prongs, int &work, 
          bool toPrint) {
    // Save the top element of src prong
    int toBeMovedBlock = prongs[src].back();

    // Remove from src
    prongs[src].pop_back();
    work++;

    // Add to rear of dest
    prongs[dest].push_back(toBeMovedBlock);
    work++;

    // Print if printing enabled.
    if (toPrint) {
        cout << printHanoi(prongs);
        cout << endl;
    }
}

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
void Hanoi(int k, int src, int dest, int swap, vector<vector<int>> &prongs,
           int &work, bool toPrint) {
    if (k == 1) {
        move(src, dest, prongs, work, toPrint);
    } else {
        Hanoi(k-1, src, swap, dest, prongs, work, toPrint);
        move(src, dest, prongs, work, toPrint);
        Hanoi(k-1, swap, dest, src, prongs, work, toPrint);
    }
}

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
int main(int argc, char* argv[]) {

    /********************
     * Example: findMax *
     ********************/

    // Set up a simple test for the findMax function.
    vector<double> v1{-.3, 2.7, -5.6, 2.8, 1.2}; // initializing the vector
    double m1 = findMax(v1);
    cout << endl; // print a blank line first, looks nice
    cout << "Find max of vector: {"; // cout prints to terminal ("c-out")
    for (int n=0; n<v1.size()-1; n++) { // a simple for loop in c++
        cout << v1[n] << ", "; // cout can print numbers and strings easily
    }
    cout << v1[v1.size()-1] << "}" << endl; // last element looks different
    cout << endl; // print a blank line
    cout << "\t"; // start next line with a tab for formatting
    cout << "Max found: " << m1 << endl; // note: endl prints a new line char
    // cout << "Printing the vector: " << v << endl; // cannot print a vector!
    cout << endl; // blank line to make result easier to read

    // Set up another simple test (but important to check!).
    vector<double> v2{-.3, -2.7, -5.6, -2.8, -1.2};
    double m2 = findMax(v2);
    cout << endl;
    cout << "Find max of vector: {";
    for (int n=0; n<v2.size()-1; n++) {
        cout << v2[n] << ", ";
    }
    cout << v2[v2.size()-1] << "}" << endl;
    cout << endl;
    cout << "\t";
    cout << "Max found: " << m2 << endl;
    cout << endl;

    /*********************
     * Problem 1: fibRec *
     *********************/

    cout << "Testing fibRec:" << endl << endl;

    // Add some testing code that tests your fibRec function.
    // Note: use small input values! You don't want to wait too long!
    cout << "\tfibRec(5) = " << fibRec(5) << endl << endl;

    /**********************
     * Problem 2: fibIter *
     **********************/

    cout << "Testing fibIter:" << endl << endl;

    // Add some testing code that tests your fibIter function.
    cout << "\tfibIter(5) = " << fibIter(5) << endl;
    cout << endl;

    /***********************
     * Example: Timing Fib *
     ***********************/

    cout << "Timing Fib Code:" << endl << endl;

    // Compare some timing for you fib functions!
    auto start = chrono::high_resolution_clock::now();
    fibRec(10);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>
                    (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibRec(10): " << duration.count() << " ms" << endl;
    start = chrono::high_resolution_clock::now();
    fibIter(10);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>
               (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibIter(10): " << duration.count() << " ms" << endl;
    cout << endl;
    start = chrono::high_resolution_clock::now();
    fibRec(20);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>
                    (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibRec(20): " << duration.count() << " ms" << endl;
    start = chrono::high_resolution_clock::now();
    fibIter(20);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>
               (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibIter(20): " << duration.count() << " ms" << endl;
    cout << endl;
    start = chrono::high_resolution_clock::now();
    fibRec(40);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>
                    (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibRec(40): " << duration.count() << " ms" << endl;
    start = chrono::high_resolution_clock::now();
    fibIter(40);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>
               (stop - start); // Get the duration in microseconds.
    cout << "\t";
    cout << "Time for fibIter(40): " << duration.count() << " ms" << endl;
    cout << endl;

    /********************
     * Problem 3: Hanoi *
     ********************/

    cout << "Tower of Hanoi:" << endl << endl;

    bool toPrint = false; // Set to true to print the full moves!
    int numBlocks = 3; // 12 is max for displaying in 80 char window.
    vector<vector<int>> testProngs{{},{},{}};
    int A = 0;
    int B = 1;
    int C = 2;
    for (int i=numBlocks; i>0; i--) {
        testProngs[A].push_back(i);
    }
    cout << "\tStarting Tower:\n\n";
    cout << printHanoi(testProngs);
    cout << endl;
    int work = 0;
    Hanoi(testProngs[0].size(), A, C, B, testProngs, work, toPrint);
    cout << "\tFinal Tower:\n\n";
    cout << printHanoi(testProngs);
    cout << endl;
    cout << "Total Work: " << work << endl << endl;

    return 0;
}