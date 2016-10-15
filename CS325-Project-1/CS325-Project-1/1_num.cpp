/**********************************************************************
Algorithm 1: Enumeration.
Loop over each pair of indices i, j and compute the sum from i to j.
Keep the best sum you have found so far.
**********************************************************************/

int seqSum(int start, int end, int * array);


int maxSeqEnum(int* array, int length) {
    int largestSum = 0;
    int currentSum = 0;
    // get sum between each index pair i & j
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            currentSum = seqSum(i, j, array);
            // keep the largest sum found
            if (currentSum > largestSum)
                largestSum = currentSum;
        }
    }
    return largestSum;
}


/* calculates between array[start] and array[end] */

int seqSum(int start, int end, int * array) {
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += array[i];
    }
    return sum;
}