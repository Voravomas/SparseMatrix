#include "../header/functions.h"

vector<double> matrixVector(const SparseMatrix& matrix, const vector<double>& inputVector) {
    //// Sparse matrix multiplied by any vector
    //// Complexity n, where n is number of non-zero elements in matrix.
    if (matrix.colNum != inputVector.size())
    {
        throw runtime_error("vector length != matrix row length");
    }

    // checking if inputVector is zero vector
    for(auto i = 0; i < inputVector.size(); ++i)
    {
        if (inputVector[i] != 0)
        {
            break;
        }
        if (i == inputVector.size() - 1)
        {
            return inputVector;
        }
    }

    vector<double> resVector(matrix.rowNum, 0);
    for(auto i = 0; i < matrix.rowNum; ++i)
    {
        for(auto j = matrix.rowVector[i]; j < matrix.rowVector[i + 1]; ++j)
        {
            resVector[i] += matrix.valueVector[j] * inputVector[matrix.columnVector[j]];
        }
    }
    return resVector;
}