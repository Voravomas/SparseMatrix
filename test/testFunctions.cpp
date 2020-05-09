#include "./../header/testFunctions.h"
#include <gtest/gtest.h>

TEST(matrixVectorTest, PositiveNos){
    SparseMatrix copySparseMatrix = newSparseMatrix;

    vector<double> resVector1 = {6, 1, 0, -8};
    vector<double> resVector2 = {20, 2, 0, 1};

    ASSERT_EQ(matrixVector(copySparseMatrix, vector1), resVector1 );
    ASSERT_EQ(matrixVector(copySparseMatrix, vector2), vector2 );

    ASSERT_EQ(matrixVector(copySparseMatrix, vector3), resVector2 );
    ASSERT_ANY_THROW(matrixVector(copySparseMatrix, vector0) );

    ASSERT_ANY_THROW(matrixVector(copySparseMatrix, {}) );
    ASSERT_ANY_THROW(matrixVector(copySparseMatrix, { 1 }) );
}