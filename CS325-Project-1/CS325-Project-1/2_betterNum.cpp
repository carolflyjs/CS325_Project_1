#include "Header.h"
/********************************************************************
Algorithm 2: Better Enumeration. 
Notice that in the previous algorithm the same sum is computed many 
times. In particular, notice that sum of sequence from element j to k
can be calculated from element j-1 to k, rather than starting from 
scratch. Write a new version of the first algorithm that takes 
advantage of this observation.
*********************************************************************/

maxSeq maxSeqBetterEnum(int* array, int length) {
    int largestSum = 0;
    int currentSum = 0;
    int start = 0;
    int end = 0;

    // loop over all sequences
    // loop over sequences starting from i
    for (int i = 0; i < length; i++) {
        currentSum = 0;
        // loop over sequences ending at j
        for (int j = i; j < length; j++) {
            // get the sum between element i and j
            currentSum += array[j];
            // update the largest sum if found
            if (currentSum > largestSum) {
                largestSum = currentSum;
                start = i;
                end = j;
            }
        }
    }

    return{ start, end, largestSum };
}