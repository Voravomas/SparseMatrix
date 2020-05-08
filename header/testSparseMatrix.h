#ifndef TESTSPARSEMATRIX_H
#define TESTSPARSEMATRIX_H

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include "sparseMatrix.h"

static vector<vector<double>> normalMatrix = {
        {0, 2, 0, 4},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 0, -9, 0}
};

static vector<vector<double>> normal2Matrix = {
        {0, 2, 0, 4},
        {0, 1, 0, 0},
        {10, 0, 0, 0},
        {1, 0, -9, 0}
};

static SparseMatrix newSparseMatrix = SparseMatrix(normalMatrix);

int test_returnElement();
int test_changeElement();
int test_retNormal();

#endif //TESTSPARSEMATRIX_H
