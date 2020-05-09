#include "./../header/testFunctions.h"

int test_matrixVector(){
    SparseMatrix copySparseMatrix = newSparseMatrix;

    vector<double> resVector1 = {6, 1, 0, -8};
    vector<double> resVector2 = {20, 2, 0, 1};

    assert(matrixVector(copySparseMatrix, vector1) == resVector1);

    assert(matrixVector(copySparseMatrix, vector2) == vector2);

    assert(matrixVector(copySparseMatrix, vector3) == resVector2);

    try {
        assert(matrixVector(copySparseMatrix, vector0) == resVector2);
    } catch (const runtime_error& err) {}
    return 0;
}