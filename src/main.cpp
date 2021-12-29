#include "../include/algorithm.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    Solution findMedian;
    vector<int> array1;
    array1.push_back(1);
    array1.push_back(2);

    vector<int> array2;
    array2.push_back(3);
    array2.push_back(4);

    double median = findMedian.findMedianSortedArrays(array1, array2);
    cout << "median is " << median << endl;

    return 0;
}
