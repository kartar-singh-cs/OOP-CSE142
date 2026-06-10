#include <iostream>
#include <map>
using namespace std;

template <typename T>
class SparseMatrix
{
private:
    int rows, cols;
    map<pair<int, int>, T> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Set a value at a specific position
    void setValue(int r, int c, T val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw runtime_error("Index out of bounds");
        if (val != 0)
            data[{r, c}] = val;
        else
            data.erase({r, c});
    }

    T getValue(int r, int c) const
    {
        auto it = data.find({r, c});
        if (it != data.end())
            return it->second;
        return 0;
    }

    SparseMatrix operator+(const SparseMatrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("Matrix sizes do not match for addition");

        SparseMatrix result(rows, cols);

        for (auto &elem : data)
            result.data[elem.first] = elem.second;

        for (auto &elem : other.data)
            result.data[elem.first] += elem.second;

        return result;
    }

    // Subtraction
    SparseMatrix operator-(const SparseMatrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("Matrix sizes do not match for subtraction");

        SparseMatrix result(rows, cols);

        for (auto &elem : data)
            result.data[elem.first] = elem.second;

        for (auto &elem : other.data)
            result.data[elem.first] -= elem.second;

        return result;
    }

    // Multiplication
    SparseMatrix operator*(const SparseMatrix &other) const
    {
        if (cols != other.rows)
            throw runtime_error("Matrix sizes do not match for multiplication");

        SparseMatrix result(rows, other.cols);

        for (auto &elem1 : data)
        {
            int i = elem1.first.first;
            int k = elem1.first.second;
            T val1 = elem1.second;

            for (int j = 0; j < other.cols; j++)
            {
                T val2 = other.getValue(k, j);
                if (val2 != 0)
                    result.data[{i, j}] += val1 * val2;
            }
        }

        return result;
    }

    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << getValue(i, j) << " ";
            cout << endl;
        }
    }
};

int main()
{
    SparseMatrix<int> A(3, 3);
    SparseMatrix<int> B(3, 3);

    A.setValue(0, 0, 1);
    A.setValue(1, 1, 2);
    A.setValue(2, 2, 3);

    B.setValue(0, 0, 4);
    B.setValue(1, 0, 5);
    B.setValue(2, 1, 6);

    cout << "Matrix A:" << endl;
    A.print();

    cout << "Matrix B:" << endl;
    B.print();

    SparseMatrix<int> C = A + B;
    cout << "A + B:" << endl;
    C.print();

    SparseMatrix<int> D = A - B;
    cout << "A - B:" << endl;
    D.print();

    SparseMatrix<int> E = A * B;
    cout << "A * B:" << endl;
    E.print();

    return 0;
}