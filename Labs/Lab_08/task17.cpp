#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename BinaryOperation>
vector<vector<T>> matrix_operation(
    const vector<vector<T>>& m1,
    const vector<vector<T>>& m2,
    size_t rows,
    size_t cols,
    BinaryOperation op)
{
    vector<vector<T>> result(rows, vector<T>(cols));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            result[i][j] = op(m1[i][j], m2[i][j]);
    return result;
}

int main()
{
    size_t rows = 2, cols = 3;

    vector<vector<int>> m1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> m2 = {
        {7, 8, 9},
        {10, 11, 12}
    };

    auto add = [](const int& a, const int& b){ return a + b; };

    vector<vector<int>> result = matrix_operation(m1, m2, rows, cols, add);

    cout << "Matrix 1:" << endl;
    for (auto& row : m1) {
        for (auto& val : row) cout << val << " ";
        cout << endl;
    }

    cout << "Matrix 2:" << endl;
    for (auto& row : m2) {
        for (auto& val : row) cout << val << " ";
        cout << endl;
    }

    cout << "Result (Addition):" << endl;
    for (auto& row : result) {
        for (auto& val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}