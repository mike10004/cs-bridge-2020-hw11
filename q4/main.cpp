// mac937@nyu.edu
// hw11 question 4

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Finds the lowest cost for a complete sequence of moves in the game Jump.
 *
 * The rules of Jump are as follows: The number in each column represents 
 * the cost to enter that column. You always start the game in the first 
 * column and have two types of moves. You can either move to the adjacent 
 * column or jump over the adjacent column to land two columns over. The cost 
 * of a game is the sum of the costs of the visited columns.
 * @param board the board
 * @param numColumns number of columns
 * @param knownMinimum minimum previously found, or -1 if not known
 * @return minimum minimum cost to play Jump
 */
int findMinimumCost(const int* board, int numColumns) {
    assert(numColumns > 0);
    int currentColumnCost = board[0];
    if (numColumns == 1) {
        return currentColumnCost;
    }
    int adjacentCost = currentColumnCost + findMinimumCost(&(board[1]), numColumns - 1);
    if (numColumns <= 2) {
        return adjacentCost;
    }
    int jumpCost = currentColumnCost + findMinimumCost(&(board[2]), numColumns - 2);
    if (adjacentCost < jumpCost) {
        return adjacentCost; 
    } else { 
        return jumpCost;
    }
}

void testFindMinimumCost(const vector<int>& board, int expected) {
    int actual = findMinimumCost(board.data(), board.size());
    cout << actual << " is minimum cost of board ";
    for (int column : board) {
        cout << column << ' ';
    }
    cout << endl;
    if (expected != actual) {
        cerr << "expected " << expected << " but got " << actual << " on board of size " << board.size() << endl;
        cerr << endl;
    }
    assert(expected == actual);
}

int main() {
    testFindMinimumCost({1}, 1);
    testFindMinimumCost({2, 4}, 6);
    testFindMinimumCost({2, 4, 8}, 10);
    testFindMinimumCost({2, 0, 4}, 6);
    testFindMinimumCost({2, 4, 8, 16}, 2 + 4 + 16);
    testFindMinimumCost({3, 27, 9, 81}, 3 + 9 + 81);
    testFindMinimumCost({0, 3, 80, 6, 57, 10}, 0 + 3 + 6 + 10);
    testFindMinimumCost({0, 2, 0, 4, 0, 8, 0, 16, 0, 32, 0}, 0);
    return 0;
}
