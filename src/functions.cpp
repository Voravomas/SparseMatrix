#include "../header/functions.h"

vector<double> matrixVector(const SparseMatrix& matrix, const vector<double>& inputVector) {
    if (matrix.colNum != inputVector.size())
    {
        throw runtime_error("vector length != matrix row length");
    }
    vector<double> resVector(matrix.rowNum, 0);
    for(auto i = 0; i < matrix.rowNum; ++i)
    {
        for(auto j = matrix.rowVector[i]; j < matrix.rowVector[i + 1]; ++j)
        {
            resVector[i] += matrix.valueVector[j] * inputVector[j - matrix.rowVector[i]];
        }
    }
    return resVector;
}