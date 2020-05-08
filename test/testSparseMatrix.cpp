#include "./../header/testSparseMatrix.h"

int test_returnElement(){
    assert(newSparseMatrix.returnElement(0, 0) == 0);
    assert(newSparseMatrix.returnElement(1, 1) == 1);
    assert(newSparseMatrix.returnElement(3, 0) == 1);
    try {
        newSparseMatrix.returnElement(4, 4);
        newSparseMatrix.returnElement(-1, -1);
    } catch (const runtime_error& err) {}
    return 0;
}

int test_changeElement(){
    assert(newSparseMatrix.returnElement(0, 0) == 0);
    newSparseMatrix.changeElement(0, 0, 5);
    assert(newSparseMatrix.returnElement(0, 0) == 5);

    assert(newSparseMatrix.returnElement(3, 2) == -9);
    newSparseMatrix.changeElement(3, 2, 3);
    assert(newSparseMatrix.returnElement(3, 2) == 3);

    assert(newSparseMatrix.returnElement(0, 3) == 4);
    newSparseMatrix.changeElement(0, 3, 0);
    assert(newSparseMatrix.returnElement(0, 3) == 0);

    try
    {
        newSparseMatrix.changeElement(-1, 5, 3);
    } catch (const runtime_error& err) {}
    return 0;
}

int test_retNormal(){
//    assert(newSparseMatrix.retNormal() == normalMatrix);
//    newSparseMatrix.changeElement(2, 0, 10);
//    assert(newSparseMatrix.retNormal() == normal2Matrix);
}