/********************************************************************
Algorithm 3: Divide and Conquer. 
If we split the array into two halves, we know that the maximum 
subarray will either be
- Contained entirely in the first half,
- Contained entirely in the second half or
- Made of a suffix of the first half of the subarray and a prefix 
of the second half
*********************************************************************/

int maxSeqHelper(int start, int end, int* array);
int max(int a, int b, int c);
int maxSuffix(int start, int end, int* array);
int maxPrefix(int start, int end, int* array);

int maxSeqDandC(int* array, int length) {
    return maxSeqHelper(0, length - 1, array);
}

int maxSeqHelper(int start, int end, int * array)
{
    // base case 1: if start is larger than end, return 0
    if (start > end)
        return 0;
    // base case 2: if start == end, return the current element
    else if (start == end)
        return array[start];
    // recursive cases
    else {
        int midPoint = (start + end) / 2;
        int firstHalf = maxSeqHelper(start, midPoint, array);
        int secondHalf = maxSeqHelper(midPoint + 1, end, array);
        int acrossMidPoint = maxSuffix(start, midPoint, array) + maxPrefix(midPoint + 1, end, array);
        return max(firstHalf, secondHalf, acrossMidPoint);
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

int maxSuffix(int start, int end, int * array)
{
    int currentSum = 0;
    int largestSum = 0;
    // loop from back to front to see 
    // which start index makes the largest sum for sequence ending at a specific location
    for (int i = end; i >= start; i--) {
        currentSum += array[i];
        if (currentSum > largestSum)
            largestSum = currentSum;
    }
    return largestSum;
}

int maxPrefix(int start, int end, int * array)
{
    int currentSum = 0;
    int largestSum = 0;
    // loop from front to back to see
    // which end index makes the largest sum for sequence starting at a specific location
    for (int i = start; i <= end; i++) {
        currentSum += array[i];
        if (currentSum > largestSum)
            largestSum = currentSum;
    }
    return largestSum;
}

