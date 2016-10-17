#include "Header.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>

// print an array to output file
void printArray(int* array, int length, std::ofstream* output) {
    // array format: [x, y, z]
    *output << "[";
    for (int i = 0; i < length; i++) {
        *output << array[i];
        if (i != length - 1)
            *output << ", ";
    }
    *output << "]\n";
}

// print the maximum sequence to output file with its sum
void printResult(maxSeq result, int* array, std::ofstream* output) {
    // array format: [x, y, z]
    *output << "[";
    for (int i = result.start; i <= result.end; i++) {
        *output << array[i];
        if (i != result.end)
            *output << ", ";
    }
    *output << "]\n";

    // print the sum
    *output << result.sum << "\n\n";

}

// algorithm bug testing, used to cross-check the correctness of the four algorithm
bool testAlgorithm(int* array, int length) {
    maxSeq algo1Result = maxSeqEnum(array, length);
    maxSeq algo2Result = maxSeqBetterEnum(array, length);
    maxSeq algo3Result = maxSeqDandC(array, length);
    maxSeq algo4Result = maxSeqLinear(array, length);

    if (algo1Result != algo2Result
        || algo2Result != algo3Result
        || algo3Result != algo4Result) {
        return false;
    }
    return true;
}

int main() {
    /* open input & output file */
    std::ifstream inputFile;
    inputFile.open("MSS_Problems.txt");
    if (!inputFile)
    {
        std::cout << "Error opening input file\n";
        return -1;
    }
    
    std::ofstream outputFile;
    outputFile.open("MSS_Solutions.txt");
    if (!outputFile)
    {
        std::cout << "Error opening output File\n";
        return -1;
    }

    int length = 0;             // array length initiated at 0
    int array[100];             // array can allow 100 elements at most
    std::string newLine = "";   // stores new line from the file as one string
    std::string newNumStr = ""; // stores new number from the string as a string before converting
    int newNum = 0;             // stores converted new number
    int strIndex = 0;           // stores index of the string
    std::string::size_type sz;  // file type alias used for converting numbers

    /* read input file line by line and store each line into an array */

    while (getline(inputFile, newLine)) {  
        // check each character before reaching to the end of the newLine string
        while (newLine[strIndex] != '\0') {
            // if the char is number or sign, add to the newNumStr 
            if (newLine[strIndex] >= '0' && newLine[strIndex] <= '9') {
                newNumStr += newLine[strIndex];
            }
            else if (newLine[strIndex] == '+' || newLine[strIndex] == '-') {
                newNumStr += newLine[strIndex];
            }
            // if the char is not part of a number
            else {
                // check if the newNumStr is empty. If not, convert and clear
                if (newNumStr != "") {
                    // convert and store
                    newNum = std::stoi(newNumStr, &sz);
                    array[length] = newNum;
                    length++;
                    // clear the newNumStr
                    newNumStr = "";
                }
            }      
            strIndex++;
        }
        // if stored array is not empty, get the result and print to file
        if (length != 0) {
            // assert(testAlgorithm(array, length));

            // get the result
            maxSeq maxResult = maxSeqLinear(array, length);
            printArray(array, length, &outputFile);
            printResult(maxResult, array, &outputFile);
        }
        // clear everything for the next array reading
        newLine = "";
        newNumStr = "";
        newNum = 0;
        length = 0;
        strIndex = 0;
    }

    inputFile.close();
    outputFile.close();


    /* ************************************************************************************
    Experimental analysis. 
    For the experimental analysis you will plot running times as a function of input size.  
    Every programming language should provide access to a clock (not necessarily in seconds).  
    Run each of your algorithms on various input sizes for example  n = 100 - 900 or 1000 - 10000. 
    If your algorithm runs very fast and has a time of 0 you will need to increase the sizes of n.  
    Likewise if the algorithm runs for over an hour you will need to decrease your input size.  
    Each algorithm may require different sizes of n and you will need at least 10 different 
    input sizes for each algorithm.  
    ***************************************************************************************/
    // test first algorithm with array size from 100 to 900
   
   /*
	srand(time(0));
    int * expArray;
    clock_t current;
    int nTicks;

    outputFile.open("Exp_tracker.txt");
    if (!outputFile)
    {
        std::cout << "Error opening output File\n";
        return -1;
    }

    const int testSize = 20;
    const int test1Range = 100;
    const int test2Range = 1000;
    const int test3Range = 1000000;
    const int test4Range = 100000000;

    
    outputFile << "Algo 1\n";
    std::cout << "Algo 1\n";
    for (int i = 1; i < testSize; i++) {
        expArray = new int[i * test1Range];
        // generate the array for testing
        for (int j = 0; j < i * test1Range; j++) {
            expArray[j] = rand() % 500 - 1000;
        }
        outputFile << i * test1Range << " ";
        std::cout << i * test1Range << " ";
        for (int j = 0; j < 10; j++) {
            current = clock();
            maxSeqEnum(expArray, i * test1Range);
            nTicks = clock() - current;
            outputFile << nTicks << " ";
            std::cout << nTicks << " ";
        }
        outputFile << "\n";
        std::cout << "\n";

        delete []expArray;
    }

    outputFile << "Algo 2\n";
    std::cout << "Algo 2\n";
    for (int i = 1; i < testSize; i++) {
        expArray = new int[i * test2Range];
        // generate the array for testing
        for (int j = 0; j < i * test2Range; j++) {
            expArray[j] = rand() % 500 - 1000;
        }
        outputFile << i * test2Range << " ";
        std::cout << i * test2Range << " ";
        for (int j = 0; j < 10; j++) {
            current = clock();
            maxSeqBetterEnum(expArray, i * test2Range);
            nTicks = clock() - current;
            outputFile << nTicks << " ";
            std::cout << nTicks << " ";
        }
        outputFile << "\n";
        std::cout << "\n";

        delete[]expArray;
    }
   
    outputFile << "Algo 3\n";
    std::cout << "Algo 3\n";
    for (int i = 1; i < testSize; i++) {
        expArray = new int[i * test3Range];
        // generate the array for testing
        for (int j = 0; j < i * test3Range; j++) {
            expArray[j] = rand() % 500 - 1000;
        }
        outputFile << i * test3Range << " ";
        std::cout << i * test3Range << " ";
        for (int j = 0; j < 10; j++) {
            current = clock();
            maxSeqDandC(expArray, i * test3Range);
            nTicks = clock() - current;
            outputFile << nTicks << " ";
            std::cout << nTicks << " ";
        }
        outputFile << "\n";
        std::cout << "\n";

        delete[]expArray;
    }
   
    outputFile << "Algo 4\n";
    std::cout << "Algo 4\n";

    for (int i = 1; i < testSize; i++) {
	    expArray = new int[i * test4Range];
        // generate the array for testing
        for (int j = 0; j < i * test4Range; j++) {
            expArray[j] = rand() % 500 - 1000;
        }
        outputFile << i * test4Range << " ";
        std::cout << i * test4Range << " ";
        for (int j = 0; j < 10; j++) {
            current = clock();
            maxSeqLinear(expArray, i * test4Range);
            nTicks = clock() - current;
            outputFile << nTicks << " ";
            std::cout << nTicks << " ";
        }
        outputFile << "\n";
        std::cout << "\n";

        delete[]expArray;
    }
    
    outputFile.close(); 
	*/


    return 0;
}

