#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>


using std::vector;
using std::runtime_error;
using std::cout;
using std::flush;
using std::endl;

class SparseMatrix {
public:
    int rowNum;
    int colNum;

    vector<double> valueVector;
    vector<int> columnVector;
    vector<int> rowVector = {0};
public:
    SparseMatrix(vector<vector<double>> matrix);
    double returnElement(int getR, int getC, int type=0);
    void changeElement(int newRow, int newCol, double newVal);
    void printSparse();
    void printNormal();
    vector<vector<double>> retNormal();

};
#endif //SPARSEMATRIX_H