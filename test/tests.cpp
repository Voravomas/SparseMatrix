#include "./../header/tests.h"

////Testing SparseMatrix class

TEST(ReturnZero, ReturnElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 0));

    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 2));

    ASSERT_EQ(0, copySparseMatrix.returnElement(2, 3));
}

TEST(ReturnNotZero, ReturnElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(2, copySparseMatrix.returnElement(0, 1));

    ASSERT_EQ(1, copySparseMatrix.returnElement(1, 1));

    ASSERT_EQ(-9, copySparseMatrix.returnElement(3, 2));
}

TEST(ReturnError, ReturnElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_THROW(copySparseMatrix.returnElement(100, 1), std::runtime_error);

    ASSERT_THROW(copySparseMatrix.returnElement(-5, -100), std::runtime_error);

    ASSERT_THROW(copySparseMatrix.returnElement(-10, 1), std::runtime_error);
}

TEST(ElementWasZero, ChangeElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(0, copySparseMatrix.returnElement(0, 0));
    copySparseMatrix.changeElement(0, 0, 5);
    ASSERT_EQ(5, copySparseMatrix.returnElement(0, 0));

    ASSERT_EQ(0, copySparseMatrix.returnElement(1, 2));
    copySparseMatrix.changeElement(1, 2, -3);
    ASSERT_EQ(-3, copySparseMatrix.returnElement(1, 2));

    ASSERT_EQ(0, copySparseMatrix.returnElement(3, 3));
    copySparseMatrix.changeElement(3, 3, 55);
    ASSERT_EQ(55, copySparseMatrix.returnElement(3, 3));
}

TEST(ElementWasNotZero, ChangeElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(2, copySparseMatrix.returnElement(0, 1));
    copySparseMatrix.changeElement(0, 1, 10);
    ASSERT_EQ(10, copySparseMatrix.returnElement(0, 1));

    ASSERT_EQ(-9, copySparseMatrix.returnElement(3, 2));
    copySparseMatrix.changeElement(3, 2, 0);
    ASSERT_EQ(0, copySparseMatrix.returnElement(3, 2));

    ASSERT_EQ(4, copySparseMatrix.returnElement(0, 3));
    copySparseMatrix.changeElement(0, 3, 9);
    ASSERT_EQ(9, copySparseMatrix.returnElement(0, 3));
}

TEST(ReturnError, ChangeElement) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_THROW(copySparseMatrix.changeElement(0, -1, 9), std::runtime_error);

    ASSERT_THROW(copySparseMatrix.changeElement(20, 20, 9), std::runtime_error);

    ASSERT_THROW(copySparseMatrix.changeElement(1999, 20, 0), std::runtime_error);
}

TEST(ReturnTheSame, ReturnNormal) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    ASSERT_EQ(normalMatrix, copySparseMatrix.retNormal());
}

TEST(ReturnModified, ReturnNormal) {
    SparseMatrix copySparseMatrix = newSparseMatrix;

    copySparseMatrix.changeElement(2, 0, 10);
    ASSERT_EQ(normal2Matrix, copySparseMatrix.retNormal());

    copySparseMatrix.changeElement(3, 3, -8);
    ASSERT_EQ(normal3Matrix, copySparseMatrix.retNormal());
}

TEST(ReturnZeroMatrix, ReturnNormal) {
    SparseMatrix copyEmptyMatrix = emptyMatrix;

    ASSERT_EQ(emptyMatrix, copyEmptyMatrix.retNormal());

    copyEmptyMatrix.changeElement(0, 0, 5);
    copyEmptyMatrix.changeElement(2, 2, -8);
    ASSERT_EQ(normal4Matrix, copyEmptyMatrix.retNormal());
}

////Testing functions

TEST(ReturnSumOfEntries, MatrixVector) {
    SparseMatrix copySparseMatrix = newSparseMatrix;
    SparseMatrix copySparseMatrix2 = normal4Matrix;
    SparseMatrix copyEmptyMatrix = emptyMatrix;

    vector<double> resVector1 = {6, 1, 0, -8};
    vector<double> resVector2 = {5, 0, -8};
    vector<double> resVector3 = {0, 0, 0};

    ASSERT_EQ(resVector1, matrixVector(copySparseMatrix, vector1));

    ASSERT_EQ(resVector2, matrixVector(copySparseMatrix2, vector4));

    ASSERT_EQ(resVector3, matrixVector(copyEmptyMatrix, vector4));
}

TEST(MultiplyByDifferentVector, MatrixVector) {
    SparseMatrix copySparseMatrix = newSparseMatrix;
    SparseMatrix copySparseMatrix2 = normal4Matrix;
    SparseMatrix copyEmptyMatrix = emptyMatrix;

    vector<double> resVector1 = {20, 2, 0, 1};
    vector<double> resVector2 = {5, 0, -24};
    vector<double> resVector3 = {0, 0, 0};

    ASSERT_EQ(resVector1, matrixVector(copySparseMatrix, vector3));

    ASSERT_EQ(resVector2, matrixVector(copySparseMatrix2, vector0));

    ASSERT_EQ(resVector3, matrixVector(copyEmptyMatrix, vector0));
}

TEST(ReturnErrorWrongSize, MatrixVector) {
    SparseMatrix copySparseMatrix = newSparseMatrix;
    SparseMatrix copySparseMatrix2 = normal4Matrix;

    ASSERT_THROW(matrixVector(copySparseMatrix, vector0), std::runtime_error);

    ASSERT_THROW(matrixVector(copySparseMatrix2, vector1), std::runtime_error);
}