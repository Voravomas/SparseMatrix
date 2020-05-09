#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#include "./../header/sparseMatrix.h"
#include "./../header/functions.h"
#include "./../header/testSparseMatrix.h"
#include "./../header/testFunctions.h"

int main( int argc, char **argv ) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
