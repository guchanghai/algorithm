#include "../include/algorithm.hpp"

using namespace std;

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // result vector
    vector<int> result;

    // total amount of two arrays
    int size = 0;

    int medianPos = 0;

    // merge two sorted arrays to one array
    vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();

    for( ; iter1 != nums1.end() || iter2 != nums2.end(); ){

        // if reach the end of array 1, then always get array 2
        if( iter1 == nums1.end()){
            result.push_back( *iter2 );
            iter2++;
        } else if( iter2 == nums2.end()){
            // if reach the end of array 2, then always get array 1
            result.push_back( *iter1 );
            iter1++;
        } else {
            // Get the smaller one from two arrays
            if( *iter1 > *iter2){
                result.push_back( *iter2 );
                iter2++;
            } else {
                result.push_back( *iter1 );
                iter1++;
            }
        }

        // increase the size of result array
        size++;

        // move median number position
        int newMedianPos = (size - 1) / 2;
        if( medianPos != newMedianPos ){
            //median++;
            medianPos = newMedianPos;
        }
    }

    // position of median
    if( size % 2 == 0){
        return double(result[medianPos] + result[medianPos+1]) / 2;
    } else {
        // if size is odd, return the middle number
        return result[medianPos];
    }

    // check result
    return 0;

    // // if size is even, return the average of two middle numbers
    // if( size % 2 == 0){
    //     return (*median + *(median++)) / 2;
    // } else {
    //     // if size is odd, return the middle number
    //     return *median;
    // }
};