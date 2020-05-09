#include "./../header/testSparseMatrix.h"
#include <gtest/gtest.h>

TEST(copySparseMatrixTest, PositiveNos) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 0) );
    ASSERT_EQ(1, copySparseMatrix.returnElement(1, 1) );

    ASSERT_EQ(1, copySparseMatrix.returnElement(3, 0) );
    ASSERT_ANY_THROW(copySparseMatrix.returnElement(4, 4) );
}

TEST(changeElementTest, PositiveNos){
    SparseMatrix copySparseMatrix = newSparseMatrix;
    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 0) );
    copySparseMatrix.changeElement(0, 0, 5);
    ASSERT_EQ(5, copySparseMatrix.returnElement(0, 0) );

    ASSERT_EQ(-9, copySparseMatrix.returnElement(3, 2) );
    copySparseMatrix.changeElement(3, 2, 3);
    ASSERT_EQ(3, copySparseMatrix.returnElement(3, 2) );

    ASSERT_EQ(4, copySparseMatrix.returnElement(0, 3) );
    copySparseMatrix.changeElement(0, 3, 0);
    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 3) );

    ASSERT_ANY_THROW(copySparseMatrix.changeElement(-1, 5, 3) );
}

TEST(test_retNormalTest, PositiveNos){
    SparseMatrix copySparseMatrix = newSparseMatrix;
    ASSERT_EQ( copySparseMatrix.retNormal(), normalMatrix );

    copySparseMatrix.changeElement(2, 0, 10);
    ASSERT_EQ( copySparseMatrix.retNormal(), normal2Matrix );

    copySparseMatrix.changeElement(3, 0, 10);
    ASSERT_NE( copySparseMatrix.retNormal(), normal2Matrix );

    auto copySparseMatrix_2 = new SparseMatrix( { {}, {} } );
    ASSERT_NO_THROW(copySparseMatrix_2->retNormal() );
}

TEST(SparseMatrixTest, PositiveNos){
    vector<double> resVector1 = {0, 0 ,0 ,0};
    vector<double > resVector2 = {1, 1, 1, 1};
    vector<double > resVector5 = {1, 0};

    vector<vector<double >> resVector3 = {resVector1, resVector2};
    vector<vector<double >> resVector4 = {resVector1, resVector5};
    vector<vector<double >> resVector6 = {{}, {}};

    ASSERT_ANY_THROW(new SparseMatrix(resVector4) );
    ASSERT_NO_THROW(new SparseMatrix(resVector6) );

    ASSERT_NO_THROW(new SparseMatrix(resVector3) );
    ASSERT_ANY_THROW(new SparseMatrix( { {1, 0}, {0} } ));
}

