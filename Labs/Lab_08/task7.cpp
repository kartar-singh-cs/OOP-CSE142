#include <iostream>
using namespace std;

class Matrix
{

    int row;
    int col;
    int **arr;

    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);

public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;

        arr = new int *[row];

        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    int at(int i, int j)
    {
        if (i >= row || j >= col || i < 0 || j < 0)
        {
            throw runtime_error("Please insert correct");
        }

        return arr[i][j];
    }

    void test()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void setAllValues()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter value for [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

Matrix operator+(const Matrix &m1, const Matrix &m2)
{

    if (m1.row != m2.row || m1.col != m2.col)
    {
        throw runtime_error("Please insert correct row and columns");
    }

    Matrix m3(m1.row, m1.col);
    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.col; j++)
        {
            m3.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }

    return m3;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    if (m1.col != m2.row)
    {
        throw runtime_error("Please Keep them equal");
    }

    Matrix result(m1.row, m2.col);

    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m2.col; j++)
        {
            result.arr[i][j] = 0;
            for (int k = 0; k < m1.col; k++)
            {
                result.arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
            }
        }
    }

    return result;
}

int main()
{
    Matrix m1(3, 3);
    Matrix m2(3, 3);

    cout << "Enter values for Matrix m1:" << endl;
    m1.setAllValues();

    cout << "Enter values for Matrix m2:" << endl;
    m2.setAllValues();

    try
    {
        Matrix m3 = m1 + m2;
        cout << "Matrix m3 (Addition):" << endl;
        m3.test();
    }
    catch (const exception &e)
    {
        cout << "Addition error: " << e.what() << endl;
    }

    try
    {
        Matrix m4 = m1 * m2;
        cout << "Matrix m4 (Multiplication):" << endl;
        m4.test();
    }
    catch (const exception &e)
    {
        cout << "Multiplication error: " << e.what() << endl;
    }

    return 0;
}