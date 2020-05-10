#include "./../header/sparseMatrix.h"

SparseMatrix::SparseMatrix(vector<vector<double>> matrix) {
    for (const auto& row: matrix)
    {
        if (row.size() != matrix[0].size())
        {
            throw runtime_error("row sizes differ");
        }
    }

    //https://www.geeksforgeeks.org/sparse-matrix-representations-set-3-csr/
    rowNum = matrix.size();
    colNum = matrix[0].size();
    int pivot = 0;

    for(auto i = 0; i < matrix.size(); ++i)
    {
        for(auto j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] != 0)
            {
                valueVector.push_back(matrix[i][j]);
                columnVector.push_back(j);
                pivot++;
            }
        }
        rowVector.push_back(pivot);
    }
}

double SparseMatrix::returnElement(int getR, int getC, int type) {
    ////function that returns element being in CSR representation
    ////complexity log(n), where n is length of row
    if (getR >= rowNum || getR < 0 || getC < 0 || getC >= colNum)
    {
        throw runtime_error("Wrong column or row");
    }
    int start = rowVector[getR];
    int finish = rowVector[getR + 1] - 1;
    int current;

    if (start == finish + 1)
    {
        return 0;
    }
    //binary search through columns
    while (start <= finish)
    {
        current = (start + finish) / 2;
        if (columnVector[current] == getC)
        {
            if (!type)
            {
                return valueVector[current];
            } else {
                return current;
            }
        }
        if (columnVector[current] < getC)
        {
            start = current + 1;
        } else {
            finish = current - 1;
        }
    }
    return 0;
}

void SparseMatrix::changeElement(int getR, int getC, double newVal) {
    ////function that changes element being in CSR representation
    ////complexity 4*n, where n is length of row
    if (getR >= rowNum || getR < 0 || getC < 0 || getC >= colNum)
    {
        throw runtime_error("Wrong column or row");
    }

    if (returnElement(getR, getC) != 0)
    {
        valueVector[returnElement(getR, getC, 1)] = newVal;
    } else {
        bool wasEmptyRow = (rowVector[getR] == rowVector[getR + 1]);

        for (auto i = getR + 1; i < rowVector.size(); ++i)
        {
            rowVector[i]++;
        }
        //variable truePut shifts, to make concurrent columns
        int truePut = rowVector[getR];
        if (!wasEmptyRow)
        {
            for (auto j = rowVector[getR]; j < rowVector[getR + 1] - 1; ++j)
            {
                if (columnVector[truePut] <= getC)
                {
                    truePut++;
                }
            }
        }
        columnVector.insert(columnVector.begin() + truePut, getC);
        valueVector.insert(valueVector.begin() + truePut, newVal);
    }
}

void SparseMatrix::printSparse(){
    cout << "Values : [" << flush;
    for (double val : valueVector)
    {
        cout << val << ", " << flush;
    }
    cout << "]\nColumns: [" << flush;
    for (double col: columnVector)
    {
        cout << col << ", " << flush;
    }
    cout << "]\nRows   : [" << flush;
    for (double row: rowVector)
    {
        cout << row << ", " << flush;
    }
    cout << "]" <<endl;
}

void SparseMatrix::printNormal(){
    vector<vector<double>> normalMatrix = retNormal();
    for (auto i = 0; i < rowNum; ++i)
    {
        for (auto j = 0; j < colNum; ++j)
        {
            cout << normalMatrix[i][j] << " " << flush;
        }
        cout << endl;
    }
}

vector<vector<double>> SparseMatrix::retNormal(){
    ////function that returns matrix in a usual (vector of vectors) appearance
    vector<vector<double>> finVector(rowNum);
    for (auto i = 0; i < rowNum; ++i)
    {
        for(auto j = 0; j < colNum; ++j)
        {
            finVector[i].emplace_back(returnElement(i, j));
        }
    }
    return finVector;
}