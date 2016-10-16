#include "Header.h"

bool operator==(maxSeq lhs, maxSeq rhs) {
    return (lhs.start == rhs.start
        && lhs.end == rhs.end
        && lhs.sum == rhs.sum);
}

bool operator!=(maxSeq lhs, maxSeq rhs) {
    return (lhs.start != rhs.start
        || lhs.end != rhs.end
        || lhs.sum != rhs.sum);
}