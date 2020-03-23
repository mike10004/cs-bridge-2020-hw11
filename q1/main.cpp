// mac937@nyu.edu
// hw11 question 1

#include <iostream>

using namespace std;

const char STAR = '*';

void printStarLine(int length) {
    if (length > 0) {
        cout << STAR;
        printStarLine(length - 1);
    } else {
        cout << endl;
    }
}

void printTriangle(int n) {
    if (n > 0) {
        printTriangle(n - 1);
        printStarLine(n);
    }
}

void printOppositeTriangles(int n) {
    if (n > 0) {
        printStarLine(n);
        printOppositeTriangles(n - 1);
        printStarLine(n);
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
    return 0;
}
