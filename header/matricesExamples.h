#ifndef MATRICESEXAMPLES_H
#define MATRICESEXAMPLES_H

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

static vector<double> vector0 = {1, 2, 3};
static vector<double> vector1 = {1, 1, 1, 1};
static vector<double> vector2 = {0, 0, 0, 0};
static vector<double> vector3 = {1, 2, 0, 4};

#endif //MATRICESEXAMPLES_H