// mac937@nyu.edu
// hw11 question 4

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int UNKNOWN = -1;

/**
 * Finds the lowest cost for a sequence of moves in the game Jump.
 * The rules of the game are as follows: The number in each column represents 
 * the cost to enter that column. You always start the game in the first 
 * column and have two types of moves. You can either move to the adjacent 
 * column or jump over the adjacent column to land two columns over. The cost 
 * of a game is the sum of the costs of the visited columns.
 * @param board the board
 * @param numColumns number of columns
 * @param knownMinimum minimum previously found, or -1 if not known
 * @return minimum minimum cost to play Jump
 */
int findMinimumCost(const int* board, int numColumns, int accumulatedCost, int knownMinimum) {
    return 0;
}

int findMinimumCost(const int* board, int numColumns) {
    return findMinimumCost(board, numColumns, 0, UNKNOWN);
}

void testFindMinimumCost(const vector<int>& board, int expected) {
    int actual = findMinimumCost(board.data(), board.size());
    if (expected != actual) {
        cerr << "expected " << expected << " but got " << actual << " on board of size " << board.size() << endl;
        for (int column : board) {
            cerr << column << ' ';
        }
        cerr << endl;
    }
    assert(expected == actual);
}

int main() {
    testFindMinimumCost({1}, 1);
    testFindMinimumCost({2, 4}, 6);
    testFindMinimumCost({2, 4, 8}, 10);
    testFindMinimumCost({2, 4, 8, 16}, 2 + 4 + 16);
    testFindMinimumCost({0, 3, 80, 6, 57, 10}, 0 + 3 + 6 + 10);
    return 0;
}
