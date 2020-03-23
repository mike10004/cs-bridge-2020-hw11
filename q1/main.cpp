// mac937@nyu.edu
// hw11 question 1

#include <iostream>

using namespace std;

void printLine(int length, char mark) {
    if (length > 0) {
        cout << mark;
        printLine(length - 1, mark);
    } else {
        cout << endl;
    }
}

void printTriangle(int n) {
    if (n > 0) {
        printTriangle(n - 1);
        printLine(n, '*');
    }
}

void printOppositeTriangles(int n) {
    if (n > 0) {
        printLine(n, '*');
        printOppositeTriangles(n - 1);
        printLine(n, '*');
    }
}

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
