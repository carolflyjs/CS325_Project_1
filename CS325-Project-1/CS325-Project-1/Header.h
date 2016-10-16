#ifndef HEADER_H
#define HEADER_H
struct maxSeq maxSeqEnum(int* array, int length);
struct maxSeq maxSeqBetterEnum(int* array, int length);
struct maxSeq maxSeqDandC(int* array, int length);
struct maxSeq maxSeqLinear(int* array, int length);

struct maxSeq {
    int start;
    int end;
    int sum;
};

bool operator==(maxSeq lhs, maxSeq rhs);
bool operator!=(maxSeq lhs, maxSeq rhs);

#endif