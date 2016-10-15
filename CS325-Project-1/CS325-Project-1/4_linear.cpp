/********************************************************************
Algorithm 4: Linear-time. 
Use the following ideas to develop a nonrecursive linear time algorithm. 
Start at the left end of the array and progress towards the right, 
keeping track of the maximum subarray sum seen so far. 
Knowing a maximum subarray of A[1 . . j], extend the answer to find 
a maximum subarray ending at index j+1 by using the following 
observation: 
a maximum subarray of A[1 . . j+1] is either a maximum subarray of 
A[1 . . j] or a subarray A[i . . j+1], for some 1 <= i <= j+1. 
Determine a maximum subarray of the form A[i . . j+1] in constant 
time based on knowing a maximum subarray ending at index j.
*********************************************************************/

int maxSeqLinear(int* array, int length) {
    int largestSum = 0;
    int currentSum = 0;
    // loop from the beginning to the end
    for (int i = 0; i < length; i++) {
        // if sequence ending at i - 1 is not larger than 0
        // the largest seq sum ending at i is array[i]
        if (currentSum <= 0)
            currentSum = array[i];
        // otherwise, the largest seq ending at i is previous
        // sum plus array[i]
        else 
            currentSum += array[i];
        // compare the largest seq sum ending at i with the 
        // largest sum ending at previous location
        if (currentSum > largestSum)
            largestSum = currentSum;
    }
    return largestSum;
}