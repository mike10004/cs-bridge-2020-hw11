// mac937@nyu.edu
// hw11 question 2

#include <iostream>

using namespace std;

void printLine(int n, char mark) {
    for (int i = 0; i < n; i++) {
        cout << mark;
    }   
    cout << endl;
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
    printRuler(n);
    return 0;
}
