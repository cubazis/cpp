#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
private:
	int num_rows_;
	int num_columns_;
	vector<vector<int>> elements_;

public:
	Matrix(){
		num_rows_ = 0;
		num_columns_ = 0;
	}

	Matrix(int num_rows, int num_columns) {
		Reset(num_rows, num_columns);
	}

	void Reset(int num_rows, int num_columns){
		if(num_rows < 0){
			throw out_of_range("num of num_rows_ must be >= 0");
		}
		if(num_columns < 0){
			throw out_of_range("num of num_columns_ must be >= 0");
		}
		if (num_rows == 0 || num_columns == 0) {
			num_rows = num_columns = 0;
		}
		num_rows_ = num_rows;
		num_columns_ = num_columns;
		elements_.assign(num_rows_, vector<int>(num_columns_));
	}

	int & At(int row, int column){
		return elements_.at(row).at(column);
	}

	int At(int row, int column) const {
		return elements_.at(row).at(column);
	}

	int GetNumRows() const {
		return num_rows_;
	}

	int GetNumColumns() const {
		return num_columns_;
	}

	void print(){
		cout << num_rows_ << "x" << num_columns_ << endl;
		for(const auto & row:elements_){
			for(const auto & e:row){
				cout << e << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

istream & operator >> (istream & in, Matrix & m){
	int rows, columns;
	in >> rows >> columns;

	m.Reset(rows, columns);
	for (int i = 0; i < m.GetNumRows(); ++i) {
		for (int j = 0; j < m.GetNumColumns(); ++j) {
			in >> m.At(i, j);
		}
	}
	return in;
}

ostream & operator << (ostream & out, const Matrix m){
	out << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for (int i = 0; i < m.GetNumRows(); ++i) {
		for (int j = 0; j < m.GetNumColumns(); ++j) {
			if (j > 0) {
				out << " ";
			}
			out << m.At(i, j);
		}
		out << endl;
	}
	return out;
}

bool operator == (const Matrix & m1, const Matrix & m2){
	if(m1.GetNumRows() != m2.GetNumRows() || m1.GetNumColumns() != m2.GetNumColumns()){
		return false;
	}
	for (int i = 0; i < m1.GetNumRows(); ++i) {
		for (int j = 0; j < m1.GetNumColumns(); ++j) {
			if(m1.At(i, j) != m2.At(i, j)){
				return false;
			}
		}
	}
	return true;
}

Matrix operator + (const Matrix & m1, const Matrix & m2){
	if (m1.GetNumRows() != m2.GetNumRows()) {
		throw invalid_argument("Mismatched number of num_rows_");
	}

	if (m1.GetNumColumns() != m2.GetNumColumns()) {
		throw invalid_argument("Mismatched number of num_columns_");
	}
	Matrix m(m1.GetNumRows(), m1.GetNumColumns());
	for (int i = 0; i < m1.GetNumRows(); ++i) {
		for (int j = 0; j < m1.GetNumColumns(); ++j) {
			m.At(i, j) = m1.At(i, j) + m2.At(i, j);
		}
	}
	return m;
}

//pair<Matrix, Matrix> init(const int num_rows_, const int num_columns_){
//	Matrix m1, m2;
//	m1.Reset(num_rows_, num_columns_);
//	m2.Reset(num_rows_, num_columns_);
//	for (int i = 0; i < m1.GetNumRows(); ++i) {
//		for (int j = 0; j < m1.GetNumColumns(); ++j) {
//			m1.At(i, j) = i + j;
//			m2.At(i, j) = i + j;
//		}
//	}
//	pair<Matrix, Matrix> p = {m1, m2};
//	return p;
//}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}