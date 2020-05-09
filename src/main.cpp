#include <iostream>
#include <vector>

#include "./../header/sparseMatrix.h"
#include "./../header/functions.h"
#include "./../header/testSparseMatrix.h"
#include "./../header/testFunctions.h"

int main() {
    test_returnElement();
    test_changeElement();
    test_retNormal();
    test_matrixVector();
    return 0;
}
