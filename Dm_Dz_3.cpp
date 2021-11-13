#include <iostream>
#include <list>
#include <vector>


using namespace std;

class Matrix {
public:
	int x;
	vector <vector<int>> matrix ;
	Matrix(int xi) {
		Reset(xi, xi);
	}
	~Matrix(){};

	void Reset(const int& rows, const int& cols) {
		matrix.resize(rows);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				matrix.at(i).push_back(rand() % 24);
			}
		}
	};
			
	void show() {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.at(i).size(); j++) {
				cout << matrix.at(i).at(j) << "  ";
			}
			cout << endl;
		}
	}

	int DeterminFoTwo(int one, int two, int three, int four) {
		int result = 0;
		result = matrix.at(one).at(two) * matrix.at(three).at(four)
			- matrix.at(one).at(four) * matrix.at(three).at(two);
		return result;
	}

	int DeterminThree() {
		int result = 0;
		result = matrix.at(0).at(0) * DeterminFoTwo(1, 1, 2, 2)
			- matrix.at(0).at(1) * DeterminFoTwo(1, 0, 2, 2)
				+ matrix.at(0).at(2) * DeterminFoTwo(1, 0, 2, 1);
		return result;
	}
};


class My_iterator {
public:
	My_iterator(size_t m_capacity) {
		this->m_capacity = m_capacity;
		m_current_pos = 0;
		ptr_it = new int[m_capacity];
	};

	~My_iterator() { delete[] ptr_it;}
	
	int* ptr_it;
	size_t m_capacity;
	size_t m_current_pos;
	
	void push_back(int i) {	ptr_it[m_current_pos++] = i;	}

	int* begin() { return &ptr_it[0]; }
	
	int* end() {return &ptr_it[m_current_pos];}
};

int main()
{
	list<double> d {1.23, 4.56, 17.89};
	double sum = 0;
	for (const auto& n : d) sum += n;
	sum = sum / d.size();
	
	d.push_back(sum);

	for (const auto & t : d) cout << t << endl;
	
	cout << endl << endl;

	// ==============================
	
	Matrix my_matrix(3);
	my_matrix.show();

	cout << " Determinant = " << my_matrix.DeterminThree() << endl;



	cout << endl << endl;


	// ==============================
	My_iterator mi(7);
	mi.push_back(23);
	mi.push_back(7);
	mi.push_back(12);
	mi.push_back(672);
	mi.push_back(999);

	for (const auto n : mi) {
		cout << n << endl;
	}
			return 0;
}
