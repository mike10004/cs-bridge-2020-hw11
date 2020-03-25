// mac937@nyu.edu
// hw11 question 1

#include <iostream>

using namespace std;

/**
 * Prints a sequence of identical characters and a newline.
 * @param length length of sequence
 * @param mark character
 */
void printLine(int length, char mark) {
    if (length > 0) {
        cout << mark;
        printLine(length - 1, mark);
    } else {
        cout << endl;
    }
}

/**
 * Prints a triangle of asterisks.
 * @param n number of lines in the triangle
 */
void printTriangle(int n) {
    if (n > 0) {
        printTriangle(n - 1);
        printLine(n, '*');
    }
}

/**
 * Prints symmetrical triangles.
 * @param n number of lines in each triangle 
 */
void printOppositeTriangles(int n) {
    if (n > 0) {
        printLine(n, '*');
        printOppositeTriangles(n - 1);
        printLine(n, '*');
    }
}

/**
 * Prints a ruler.
 * @param n nonnegative integer specifying how many dashes are in longest line of ruler
 */
void printRuler(int n) {
    if (n > 0) {
        printRuler(n - 1);
        printLine(n, '-');
        printRuler(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Part A" << endl;
    printTriangle(n);
    cout << endl;
    cout << "Part B" << endl;
    printOppositeTriangles(n);
    cout << endl;
    cout << "Part C" << endl;
    printRuler(n);
    return 0;
}
