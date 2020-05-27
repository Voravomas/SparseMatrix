#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "sparseMatrix.h"


SparseMatrix matrixMatrix(const SparseMatrix& A, const SparseMatrix& D);

std::vector<double> solveEq(const SparseMatrix& A, const std::vector<double>& b);
#endif //FUNCTIONS_H
