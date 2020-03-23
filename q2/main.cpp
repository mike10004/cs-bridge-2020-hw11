// mac937@nyu.edu
// hw11 question 2

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void testSumOfSquares(const vector<int>& values, int expected);
void copyVectorToArray(const vector<int>& values, int arr[]);
void testIsSorted(const vector<int>& values, bool expected);

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize > 0) {
        int v = arr[arrSize - 1];
        return v * v + sumOfSquares(arr, arrSize - 1);
    } else {
        return 0;
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize > 1) {
        int ultimate = arr[arrSize - 1];
        int penultimate = arr[arrSize - 2];
        return ultimate >= penultimate && isSorted(arr, arrSize - 1);
    } else {
        return true;
    }
}

int main() {
    testSumOfSquares({}, 0);
    testSumOfSquares({0}, 0);
    testSumOfSquares({1}, 1);
    testSumOfSquares({2}, 4);
    testSumOfSquares({1, 2}, 5);
    testSumOfSquares({2, 3, 4}, 29);
    testSumOfSquares({2, -1, 3, 10}, 114);
    
    testIsSorted({}, true);
    testIsSorted({0}, true);
    testIsSorted({0, 0}, true);
    testIsSorted({0, 0, 0}, true);
    testIsSorted({1}, true);
    testIsSorted({1, 1}, true);
    testIsSorted({-1}, true);
    testIsSorted({-1, -1}, true);
    testIsSorted({-1, 0, 1}, true);
    testIsSorted({1, 4, 9, 16}, true);
    testIsSorted({-100, -99, 99, 100, 101}, true);
    testIsSorted({1, 0}, false);
    testIsSorted({0, 1, -1}, false);
    testIsSorted({-3, -2, -1, -1}, true);
    testIsSorted({-3, -2, 1, -1}, false);
    testIsSorted({5, 4, 9, 10, 11}, false);
    testIsSorted({1, 1, 1, 0, 1, 1}, false);
    return 0;
}

void printVector(const vector<int>& values) {
    for (int value : values) {
        cout << value << ' ';
    }
}

void copyVectorToArray(const vector<int>& values, int arr[]) {
    for (int i = 0; i < values.size(); i++) {
        arr[i] = values[i];
    }
}

void testSumOfSquares(const vector<int>& values, int expected) {
    int* arr = new int[values.size()];
    copyVectorToArray(values, arr);
    int actual = sumOfSquares(arr, values.size());
    delete[] arr;
    if (expected != actual) {
        cout << "expect " << expected << " != " << actual << ": ";
        printVector(values);
        cout << endl;
    }
    assert(expected == actual);
}


void testIsSorted(const vector<int>& values, bool expected) {
    int* arr = new int[values.size()];
    copyVectorToArray(values, arr);
    bool actual = isSorted(arr, values.size());
    delete[] arr;
    if (expected != actual) {
        cout << "expect " << expected << " != " << actual << ": ";
        printVector(values);
        cout << endl;
    }
    assert(expected == actual);
}
