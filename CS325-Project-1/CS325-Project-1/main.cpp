#include "Header.h"
#include <iostream>

int main() {
    int array[] = { 1, 2, 4, -1, 4, -10, 4, -19, 18, -1, -3, -4, 11, 3, -20, 19, -33, 50, 66, -22, -4, -55, 91, 100, -102, 9, 10, 19, -10, 10, 11, 11, -10, -18, 50, 90 };
    int length = sizeof(array) / sizeof(array[0]);
    std::cout << "algo 1: " << maxSeqEnum(array, length) << std::endl;
    std::cout << "algo 2: " << maxSeqBetterEnum(array, length) << std::endl;
    std::cout << "algo 3: " << maxSeqDandC(array, length) << std::endl;
    std::cout << "algo 4: " << maxSeqLinear(array, length) << std::endl;
    return 0;
}