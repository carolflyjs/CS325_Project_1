#include "Header.h"
/********************************************************************
Algorithm 3: Divide and Conquer. 
If we split the array into two halves, we know that the maximum 
subarray will either be
- Contained entirely in the first half,
- Contained entirely in the second half or
- Made of a suffix of the first half of the subarray and a prefix 
of the second half
*********************************************************************/

maxSeq maxSeqHelper(int start, int end, int* array);
int max(int a, int b, int c);
maxSeq maxSuffix(int start, int end, int* array);
maxSeq maxPrefix(int start, int end, int* array);

maxSeq maxSeqDandC(int* array, int length) {
    return maxSeqHelper(0, length - 1, array);
}

maxSeq maxSeqHelper(int start, int end, int * array)
{
    // base case 1: if start is larger than end, return 0
    if (start > end)
        return{ start, start, 0 };
    // base case 2: if start == end, return the current element
    else if (start == end)
        return{ start, start, array[start] };
    // recursive cases
    else {
        int midPoint = (start + end) / 2;
        maxSeq firstHalf = maxSeqHelper(start, midPoint, array);
        maxSeq secondHalf = maxSeqHelper(midPoint + 1, end, array);

        maxSeq suffix = maxSuffix(start, midPoint, array); 
        maxSeq prefix = maxPrefix(midPoint + 1, end, array);
        maxSeq acrossMidPoint = { suffix.start, prefix.end, suffix.sum + prefix.sum };

        if (firstHalf.sum >= secondHalf.sum && firstHalf.sum >= acrossMidPoint.sum) {
            return firstHalf;
        }
        else if (secondHalf.sum >= acrossMidPoint.sum) {
            return secondHalf;
        }
        else {
            return acrossMidPoint;
        }
    }

}

int max(int a, int b, int c)
{
    // test if a is the largest
    if (a >= b && a >= c)
        return a;
    // test if b is larger than c
    else if (b >= c)
        return b;
    else
        return c;
}

maxSeq maxSuffix(int start, int end, int * array)
{
    int currentSum = 0;
    int largestSum = 0;
    int newStart = end;
    // loop from back to front to see 
    // which start index makes the largest sum for sequence ending at a specific location
    for (int i = end; i >= start; i--) {
        currentSum += array[i];
        if (currentSum > largestSum) {
            largestSum = currentSum;
            newStart = i;
        }
    }
    return{ newStart, end, largestSum };
}

maxSeq maxPrefix(int start, int end, int * array)
{
    int currentSum = 0;
    int largestSum = 0;
    int newEnd = start;
    // loop from front to back to see
    // which end index makes the largest sum for sequence starting at a specific location
    for (int i = start; i <= end; i++) {
        currentSum += array[i];
        if (currentSum > largestSum) {
            largestSum = currentSum;
            newEnd = i;
        }
    }
    return{ start, newEnd, largestSum };
}

