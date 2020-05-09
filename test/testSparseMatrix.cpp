#include "./../header/testSparseMatrix.h"

int test_returnElement(){
    SparseMatrix copySparseMatrix = newSparseMatrix;

    assert(copySparseMatrix.returnElement(0, 0) == 0);

    assert(copySparseMatrix.returnElement(1, 1) == 1);

    assert(copySparseMatrix.returnElement(3, 0) == 1);

    try {
        copySparseMatrix.returnElement(4, 4);
    } catch (const runtime_error& err) {}
    return 0;
}

int test_changeElement(){
    SparseMatrix copySparseMatrix = newSparseMatrix;

    assert(copySparseMatrix.returnElement(0, 0) == 0);
    copySparseMatrix.changeElement(0, 0, 5);
    assert(copySparseMatrix.returnElement(0, 0) == 5);

    assert(copySparseMatrix.returnElement(3, 2) == -9);
    copySparseMatrix.changeElement(3, 2, 3);
    assert(copySparseMatrix.returnElement(3, 2) == 3);

    assert(copySparseMatrix.returnElement(0, 3) == 4);
    copySparseMatrix.changeElement(0, 3, 0);
    assert(copySparseMatrix.returnElement(0, 3) == 0);

    try
    {
        copySparseMatrix.changeElement(-1, 5, 3);
    } catch (const runtime_error& err) {}
    return 0;
}

int test_retNormal(){
    SparseMatrix copySparseMatrix = newSparseMatrix;

    assert(copySparseMatrix.retNormal() == normalMatrix);

    copySparseMatrix.changeElement(2, 0, 10);
    assert(copySparseMatrix.retNormal() == normal2Matrix);

    copySparseMatrix.changeElement(3, 0, 10);
    assert(copySparseMatrix.retNormal() != normal2Matrix);
    return 0;
}