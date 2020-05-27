#include <array>
#include "../header/functions.h"
SparseMatrix matrixMatrix(const SparseMatrix& A, const SparseMatrix& D) {
	//error if sizes are different
	if (A.colNum != D.rowNum) {
		throw runtime_error("diff sizes");
	}

	//making empty sparse matrix
	vector<vector<double>> vec(A.rowNum, vector<double>(D.colNum, 0));
	SparseMatrix C = SparseMatrix(vec);

	//making copy of second matrix and transpose it
	SparseMatrix B = D;
	B.transpose();

	// complexity n^2
	for (int i = 0; i < A.rowNum; ++i) {
		for (int j = A.rowVector[i]; j < A.rowVector[i + 1]; ++j) {
			for (int m = 0; m < B.rowNum; ++m) {
				for (int n = B.rowVector[m]; n < B.rowVector[m + 1]; ++n) {
					if (A.columnVector[j] == B.columnVector[n]) {
						double res = A.valueVector[j] * B.valueVector[n];
						res += C.returnElement(i, m);
						C.changeElement(i, m, res);
					}
				}
			}
		}
	}
	return C;
}

std::vector<double> solveEq(const SparseMatrix& A, const std::vector<double>& b) {
	double res = 0;
	std::vector<double> result;
	for (int i = 0; i < A.rowVector.size(); i++) {
		for (int j = 0; j < A.columnVector.size(); j++) {
			if (A.rowVector[j] == j) {
				res += A.rowVector[j];
			}

			else {
				res += A.rowVector[i];
			}
		}
		result.emplace_back(res);
	}
	return result;
}

