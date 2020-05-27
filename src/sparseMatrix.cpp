#include <functional>
#include <fstream>
#include "./../header/sparseMatrix.h"

SparseMatrix::SparseMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row: matrix)
    {
        if (row.size() != matrix[0].size())
        {
            throw runtime_error("row sizes differ");
        }
    }

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

bool sortByFirstAndSec(const std::tuple<int, int, double>& A, const std::tuple<int, int, double>& B)
{
	return (std::get<0>(A) < std::get<0>(B)) ||
	       ((std::get<0>(A) == std::get<0>(B)) && (std::get<1>(A) < std::get<1>(B)));
}

void SparseMatrix::transpose(){
	// expand row vector to "COO" format
	vector<int> expRow;
	for(auto i = 0; i < rowVector.size() - 1; ++i)
	{
		for(auto j = rowVector[i]; j < rowVector[i + 1]; ++j){
			expRow.push_back(i);
		}
	}
	// give rowVector colVector values, and colVector assign to expRow vector
	this->rowVector = std::ref(this->columnVector);
	this->columnVector = std::ref(expRow);
	//first add tuple of Value-Column-Row of every element into one array
	vector<std::tuple<int, int, double>> tupleVec;
	tupleVec.reserve(rowVector.size());
	for (auto i = 0; i < rowVector.size(); ++i)
	{
		tupleVec.emplace_back(rowVector[i], columnVector[i], valueVector[i]);
	}
	//then sort by row and column (sorting function ^^^)
	std::sort(tupleVec.begin(), tupleVec.end(), sortByFirstAndSec);
	//then assign sorted array to rowVector (in "CSR", not "COO"), columnVector, valueVector
	rowVector.clear();
	columnVector.clear();
	valueVector.clear();
	rowVector.emplace_back(0);

	int tempVal = rowVector[0];
	int sizer = tupleVec.size();
	for(auto i= 0; i < sizer; ++i)
	{
		tempVal++;
		if ((i != sizer - 1) && (std::get<0>(tupleVec[i]) != std::get<0>(tupleVec[i + 1])))
		{
			rowVector.emplace_back(tempVal);
		}
		columnVector.emplace_back(std::get<1>(tupleVec[i]));
		valueVector.emplace_back(std::get<2>(tupleVec[i]));
	}
	rowVector.emplace_back(valueVector.size());
	std::swap(this->rowNum, this->colNum);
}

template<typename CharT, typename Traits,
		typename Allocator = std::allocator<CharT>>

auto read_txt_into_memory(std::basic_ifstream<CharT, Traits> &in, Allocator alloc = {}) {
	using std::begin;
	using std::end;

	auto const chunk_size = std::size_t{BUFSIZ};

	auto container = std::vector<CharT, Allocator>(
			std::move(alloc));

	auto chunk = std::array<char, chunk_size>{};

	while (
			in.read(chunk.data(), chunk.size()) ||
			in.gcount())
		container.insert(end(container),
		                 begin(chunk),
		                 begin(chunk) + in.gcount());

	return container;
}






vector<double> parseDOK(std::vector<char> file_as_chars) {
	vector<double> data;
	std::string temp;

	for (auto c: file_as_chars) {
		if ((c == '\n' || c == ' ') && !temp.empty()) {
			data.push_back(std::stod(temp));
			temp = "";
		} else {
			temp += c;
		}
	}
	if (!temp.empty()) {
		data.push_back(std::stod(temp));
	}

	return data;
}


SparseMatrix::SparseMatrix(const std::string& filename, MatrixFileFormat format) {
	std::ifstream file(filename);

	if (format == DOK) {
		//coordinate keys

		auto raw_data = read_txt_into_memory(file);
		auto data = parseDOK(raw_data);

		this->rowNum = data[0];
		this->colNum = data[1];

		size_t pivot = 0;
		long last_row = data[4]-1;

		for (int i = 3; i < data.size(); i+=3) {
			columnVector.push_back(data[i]-1);
			valueVector.push_back(data[i+2]);


			if (data[i+1]-1 == last_row) {
				pivot++;
			}
			else {
				auto rows_diff = (data[i+1]-1) - last_row;
				if (rows_diff > 1) {
					for (int j = 0; j < rows_diff-1; ++j) {
						rowVector.push_back(pivot);
					}
				}
				rowVector.push_back(pivot);
				pivot++;
			}
			last_row = data[i+1]-1;
			//std::cout << endl;
		}

		rowVector.push_back(pivot);

	}
	else {
		std::cout << "Not supported matrix format...\n";
	}
}

