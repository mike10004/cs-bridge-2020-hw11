// mac937@nyu.edu
// hw11 question 3

#include <iostream>
#include <vector>  // stage: cut
#include <cassert> // stage: cut

using namespace std;

/**
 * Finds the minimum value in an array.
 * @param arr the array
 * @param arrSize the array length
 * @return minimum value; behavior undefined for array length zero
 */
int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    }
    int last = arr[arrSize - 1];
    int minOfOthers = minInArray1(arr, arrSize - 1);
    if (minOfOthers < last) {
        return minOfOthers;
    } else {
        return last;
    }
}

/**
 * Finds the minimum value of a range of an array.
 * @param arr the array
 * @param low lowest index of the range (inclusive)
 * @param high highest index of the range (inclusive)
 * @return minimum value; behavior undefined for low > high
 */
int minInArray2(int arr[], int low, int high) {
    int head = arr[low];
    if (low == high) {
        return head;
    }
    int minOfOthers = minInArray2(arr, low + 1, high);
    if (head < minOfOthers) {
        return head;
    } else {
        return minOfOthers;
    }
}

// stage: cut start
void testMinInArrayFunctions(const vector<int>& values) {
    bool expectedMinAssigned = false;
    int expectedMin = 0;
    int i = 0;
    int* arr = new int[values.size()];
    for (int value : values) {
        arr[i] = value;
        if (!expectedMinAssigned) {
            expectedMin = value;
            expectedMinAssigned = true;
        }
        if (expectedMin == -1 || value < expectedMin) {
            expectedMin = value;
        }
        i++;
    }
    assert(expectedMinAssigned);
    int actual1 = minInArray1(arr, values.size());
    int actual2 = minInArray2(arr, 0, values.size() - 1);
    delete[] arr;
    assert(expectedMin == actual1);
    assert(expectedMin == actual2);    
}

// stage: cut stop
int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3
    // stage: cut start
    testMinInArrayFunctions({0});
    testMinInArrayFunctions({-3});
    testMinInArrayFunctions({3});
    testMinInArrayFunctions({0, 1});
    testMinInArrayFunctions({0, 0, 1});
    testMinInArrayFunctions({1, 0});
    testMinInArrayFunctions({1, 0, 0});
    testMinInArrayFunctions({1, 0, 1});
    testMinInArrayFunctions({0, 1, 0});
    testMinInArrayFunctions({1, 0, 1});
    testMinInArrayFunctions({2, 1, 0});
    testMinInArrayFunctions({1, 0, 1});
    testMinInArrayFunctions({0, 1, 2});
    testMinInArrayFunctions({9, 3, 8, -3, -4, 11, 58, 3, -3});
    // stage: cut stop
    if (res1 == -9 && res2 == -9 && res3 == 3 && res4 == 3) {
        return 0;
    } else {
        cerr << "bad result";
        return 1;   
    }
}